#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#endif

struct IHA {
    char Model[20];
    int yakit;
    int irtifa;
    int muhimmat; 
};

struct IHA filo[3];
int seciliIHA = 0; 

void ekranTemizle() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void filoDurumu(int size) {
    printf("\n=== FILO OPERASYON DURUMU ===\n");
    printf("%-3s %-10s %-8s %-10s %-10s %-8s\n", "No", "Model", "Yakit", "Irtifa", "Muhimmat", "Durum");
    printf("------------------------------------------------------\n");
    
    for (int i = 0; i < size; i++) {
        printf("%-3d %-10s %%%-7d %-9dm %-10d %-8s\n", 
               i+1, filo[i].Model, filo[i].yakit, filo[i].irtifa, filo[i].muhimmat,
               (filo[i].yakit <= 30) ? "KRITIK" : "HAZIR");
    }
    printf("======================================================\n");
}

int carpismaVarmi(int hedefIrtifa) {
    if (hedefIrtifa == 0) return 0; 

    for (int i = 0; i < 3; i++) { 
        if (i != seciliIHA && filo[i].irtifa == hedefIrtifa) {
            printf("\n!!! KRITIK UYARI: %dm irtifada %s var! Carpisma riski !!!\n", hedefIrtifa, filo[i].Model);
            return 1;
        }
    }
    return 0;
}

void atisYap() 
{    
    if (filo[seciliIHA].irtifa == 0) {
        printf("\nUYARI: Guvenlik kilidi devrede! Yerdeyken atis yapilamaz.\n");
        printf("Once yukselmeniz gerekiyor.\n");
        return;
    }

    if (seciliIHA == 0) {
        if (filo[0].muhimmat > 0) {
            printf("\n*** HEDEF KILITLENDI... ***\n");
            printf(">>> %s, 1 adet MAM-L fuzesi atisladi! HEDEF VURULDU. <<<\n", filo[seciliIHA].Model);
            filo[0].muhimmat--; 
            printf("Kalan Muhimmat: %d\n", filo[0].muhimmat);
        } else {
            printf("\n!!! UYARI: Muhimmat tukendi! Atis yapilamaz. Usse donun. !!!\n");
        }
    }
    else if (seciliIHA == 1) {
        if (filo[1].muhimmat > 0) {
            printf("\n*** HEDEF KILITLENDI... ***\n");
            printf(">>> %s, 1 adet MAM-C fuzesi atisladi! HEDEF VURULDU. <<<\n", filo[seciliIHA].Model);
            filo[1].muhimmat--; 
            printf("Kalan Muhimmat: %d\n", filo[1].muhimmat);
        } else {
            printf("\n!!! UYARI: Muhimmat tukendi! Atis yapilamaz. Usse donun. !!!\n");
        }
    }
    else if (seciliIHA == 2) {
        if (filo[2].muhimmat > 0) {
            printf("\n*** HEDEF KILITLENDI... ***\n");
            printf(">>> %s, 1 adet L-UMTAS Lazer gudumlu tank savar fuzesi atisladi! HEDEF VURULDU. <<<\n", filo[seciliIHA].Model);
            filo[2].muhimmat--; 
            printf("Kalan Muhimmat: %d\n", filo[2].muhimmat);
        } else {
            printf("\n!!! UYARI: Muhimmat tukendi! Atis yapilamaz. Usse donun. !!!\n");
        }
    }
}

int main() {
    
    strcpy(filo[0].Model, "TB2");
    filo[0].yakit = 100;
    filo[0].irtifa = 0;
    filo[0].muhimmat = 4; 
    
    strcpy(filo[1].Model, "AKINCI");
    filo[1].yakit = 85;
    filo[1].irtifa = 5000;
    filo[1].muhimmat = 8; 
    
    strcpy(filo[2].Model, "AKSUNGUR");
    filo[2].yakit = 70;
    filo[2].irtifa = 8000;
    filo[2].muhimmat = 6; 

    int secim;

    while (1) {
        printf("\n=== UAV FLEET COMMAND SYSTEM (V3.0) ===\n");
        printf("Secili IHA: %s (Irtifa: %dm | Muhimmat: %d)\n", filo[seciliIHA].Model, filo[seciliIHA].irtifa, filo[seciliIHA].muhimmat);
        printf("---------------------------------------\n");
        printf("1. IHA Degistir\n");
        printf("2. Durum Raporu\n");
        printf("3. Yuksel (+1000m, -5 yakit)\n");
        printf("4. Alcal (-1000m, -5 yakit)\n");
        printf("5. ATIS YAP (Fire Mission) \n"); 
        printf("6. Tum Filo Durumu\n");
        printf("7. Tam Bakim (Yakit + Muhimmat Fulle)\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");

        scanf("%d", &secim);

        switch (secim) {
            case 1: 
                printf("\nIHA Sec:\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d. %s (Yakit:%%%d, Irtifa:%dm)\n", i+1, filo[i].Model, filo[i].yakit, filo[i].irtifa);
                }
                printf("Seciminiz (1-3): ");
                int ihaSec;
                scanf("%d", &ihaSec);
                if (ihaSec >= 1 && ihaSec <= 3) {
                    seciliIHA = ihaSec - 1;
                    printf("%s secildi!\n", filo[seciliIHA].Model);
                } else {
                    printf("Hatali secim!\n");
                }
                break;

            case 2: 
                printf("\n--- %s OPERASYONEL DURUM ---\n", filo[seciliIHA].Model);
                printf("Model: %s\n", filo[seciliIHA].Model);
                printf("Yakit: %%%d\n", filo[seciliIHA].yakit);
                printf("Irtifa: %d m\n", filo[seciliIHA].irtifa);
                printf("Silah Yuku: %d adet MAM-L\n", filo[seciliIHA].muhimmat);
                break;

            case 3: 
                if (filo[seciliIHA].yakit >= 5) { 
                    int hedefIrtifa = filo[seciliIHA].irtifa + 1000;
                    if (carpismaVarmi(hedefIrtifa) == 0) {
                        filo[seciliIHA].irtifa = hedefIrtifa;
                        filo[seciliIHA].yakit -= 5;
                        printf("%s yukselis basarili. Yeni irtifa: %d m\n", filo[seciliIHA].Model, filo[seciliIHA].irtifa);
                    } else {
                        printf("HATA: Rota dolu! Yukselis iptal edildi.\n");
                    }
                } else {
                    printf("YETERSIZ YAKIT! Yukselemezsiniz.\n");
                }
                break;

            case 4: 
                if (filo[seciliIHA].irtifa >= 1000) { 
                    int hedefIrtifa = filo[seciliIHA].irtifa - 1000;
                    if (carpismaVarmi(hedefIrtifa) == 0) {
                        filo[seciliIHA].irtifa = hedefIrtifa;
                        filo[seciliIHA].yakit -= 5;
                        printf("%s alcalis basarili. Yeni irtifa: %d m\n", filo[seciliIHA].Model, filo[seciliIHA].irtifa);
                    } else {
                        printf("HATA: Rota dolu! Alcalis iptal edildi.\n");
                    }
                } else {
                    printf("Zaten yerdesiniz!\n");
                }
                break;

            case 5: 
                atisYap();
                break;

            case 6: 
                filoDurumu(3);
                break;

            case 7: 
                for (int i = 0; i < 3; i++) {
                    filo[i].yakit = 100;
                    if(i==0) filo[i].muhimmat = 4;      
                    else if(i==1) filo[i].muhimmat = 8; 
                    else filo[i].muhimmat = 6;          
                }
                printf("Tum filonun YAKIT ve MUHIMMAT ikmali tamamlandi!\n");
                break;

            case 0: 
                printf("Sistem kapatiliyor...\n");
                return 0; 

            default:
                printf("Hatali secim yaptiniz!\n");
        } 
        
        if (secim != 0) {
            printf("\nDevam etmek icin bir tusa ve Enter'a basin...");
            char temp;
            scanf(" %c", &temp);
        }
    } 

    return 0;
}