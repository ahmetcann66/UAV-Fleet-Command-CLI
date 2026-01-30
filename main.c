#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 

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
int hedefKilitli = 0; 

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


void radarTaramasi() {
    if (filo[seciliIHA].irtifa == 0) {
        printf("\nUYARI: Radar yer seviyesinde calisamaz! Once havalanin.\n");
        return;
    }

    printf("\n[RADAR] Bolge taraniyor... Sinyal araniyor...\n");
    
    
    int sans = rand() % 2; 

    if (sans == 1) {
        hedefKilitli = 1;
        printf("!!! TESPIT: Dusman zirhli araci tespit edildi! Kordinatlar kilitlendi. !!!\n");
        printf("[SYSTEM] ATIS SISTEMI AKTIF. \n");
    } else {
        hedefKilitli = 0;
        printf("[RADAR] Bolge temiz. Tehdit unsuru bulunamadi.\n");
    }
}

void atisYap() 
{    
    
    if (filo[seciliIHA].irtifa == 0) {
        printf("\nUYARI: Guvenlik kilidi devrede! Yerdeyken atis yapilamaz.\n");
        return;
    }

    
    if (hedefKilitli == 0) {
        printf("\n[HATA] HEDEF KILITLI DEGIL! Atis yapilamaz.\n");
        printf("Once '8' tusuna basarak Radar Taramasi yapin.\n");
        return;
    }

    if (seciliIHA == 0) {
        if (filo[0].muhimmat > 0) {
            printf("\n*** HEDEF KILITLENDI... FUSELAGE RELEASED ***\n");
            printf(">>> %s, 1 adet MAM-L fuzesi atisladi! HEDEF IMHA EDILDI. <<<\n", filo[seciliIHA].Model);
            filo[0].muhimmat--; 
            printf("Kalan Muhimmat: %d\n", filo[0].muhimmat);
        } else {
            printf("\n!!! UYARI: Muhimmat tukendi! !!!\n");
        }
    }
    else if (seciliIHA == 1) {
        if (filo[1].muhimmat > 0) {
            printf("\n*** HEDEF KILITLENDI... FUSELAGE RELEASED ***\n");
            printf(">>> %s, 1 adet MAM-C fuzesi atisladi! HEDEF IMHA EDILDI. <<<\n", filo[seciliIHA].Model);
            filo[1].muhimmat--; 
            printf("Kalan Muhimmat: %d\n", filo[1].muhimmat);
        } else {
            printf("\n!!! UYARI: Muhimmat tukendi! !!!\n");
        }
    }
    else if (seciliIHA == 2) {
        if (filo[2].muhimmat > 0) {
            printf("\n*** HEDEF KILITLENDI... FUSELAGE RELEASED ***\n");
            printf(">>> %s, 1 adet L-UMTAS fuzesi atisladi! HEDEF IMHA EDILDI. <<<\n", filo[seciliIHA].Model);
            filo[2].muhimmat--; 
            printf("Kalan Muhimmat: %d\n", filo[2].muhimmat);
        } else {
            printf("\n!!! UYARI: Muhimmat tukendi! !!!\n");
        }
    }

    
    hedefKilitli = 0; 
    printf("[BILGI] Hedef imha edildi. Radar sifirlandi.\n");
}

int main() {
    
    srand(time(NULL));
    
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
        printf("\n=== UAV FLEET COMMAND SYSTEM (V3.1 - ISR UPDATE) ===\n");
       
        char durum[20];
        if(hedefKilitli) strcpy(durum, "[KILITLI]"); else strcpy(durum, "[TARANIYOR]");

        printf("Secili IHA: %s (Irtifa: %dm | Muhimmat: %d) %s\n", filo[seciliIHA].Model, filo[seciliIHA].irtifa, filo[seciliIHA].muhimmat, durum);
        printf("---------------------------------------\n");
        printf("1. IHA Degistir\n");
        printf("2. Durum Raporu\n");
        printf("3. Yuksel (+1000m, -5 yakit)\n");
        printf("4. Alcal (-1000m, -5 yakit)\n");
        printf("5. ATIS YAP (Fire Mission) \n"); 
        printf("6. Tum Filo Durumu\n");
        printf("7. Tam Bakim (Logistics)\n");
        printf("8. RADAR TARAMASI (Target Acquisition) [YENI]\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");

        scanf("%d", &secim);

        switch (secim) {
            case 1: 
                printf("\nIHA Sec:\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d. %s\n", i+1, filo[i].Model);
                }
                printf("Seciminiz (1-3): ");
                int ihaSec;
                scanf("%d", &ihaSec);
                if (ihaSec >= 1 && ihaSec <= 3) {
                    seciliIHA = ihaSec - 1;
                    printf("%s secildi!\n", filo[seciliIHA].Model);
                    hedefKilitli = 0; 
                } else {
                    printf("Hatali secim!\n");
                }
                break;

            case 2: 
                printf("\n--- %s DETAYLI RAPOR ---\n", filo[seciliIHA].Model);
                printf("Model: %s\n", filo[seciliIHA].Model);
                printf("Yakit: %%%d\n", filo[seciliIHA].yakit);
                printf("Irtifa: %d m\n", filo[seciliIHA].irtifa);
                printf("Mühimmat: %d\n", filo[seciliIHA].muhimmat);
                printf("Radar Durumu: %s\n", hedefKilitli ? "HEDEF KILITLENDI" : "BEKLEMEDE");
                break;

            case 3: 
                if (filo[seciliIHA].yakit >= 5) { 
                    int hedefIrtifa = filo[seciliIHA].irtifa + 1000;
                    if (carpismaVarmi(hedefIrtifa) == 0) {
                        filo[seciliIHA].irtifa = hedefIrtifa;
                        filo[seciliIHA].yakit -= 5;
                        printf("Yukselis basarili. Irtifa: %d m\n", filo[seciliIHA].irtifa);
                    } else {
                        printf("HATA: Rota dolu!\n");
                    }
                } else {
                    printf("YETERSIZ YAKIT!\n");
                }
                break;

            case 4: 
                if (filo[seciliIHA].irtifa >= 1000) { 
                    int hedefIrtifa = filo[seciliIHA].irtifa - 1000;
                    if (carpismaVarmi(hedefIrtifa) == 0) {
                        filo[seciliIHA].irtifa = hedefIrtifa;
                        filo[seciliIHA].yakit -= 5;
                        printf("Alcalis basarili. Irtifa: %d m\n", filo[seciliIHA].irtifa);
                    } else {
                        printf("HATA: Rota dolu!\n");
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
                hedefKilitli = 0;
                break;

            case 8: 
                radarTaramasi();
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