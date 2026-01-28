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
};

void ekranTemizle() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void filoDurumu(struct IHA filo[], int size) {
    printf("\n=== FILO DURUMU ===\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - Yakit: %d%% - Irtifa: %dm - Durum: %s\n", 
               i+1, filo[i].Model, filo[i].yakit, filo[i].irtifa,
               (filo[i].yakit <= 30) ? "KRITIK" : "IYI");
    }
    printf("==================\n");
}

int main() {
    
    struct IHA filo[3];
    
    strcpy(filo[0].Model, "TB2");
    filo[0].yakit = 100;
    filo[0].irtifa = 0;
    
    strcpy(filo[1].Model, "AKINCI");
    filo[1].yakit = 85;
    filo[1].irtifa = 5000;
    
    strcpy(filo[2].Model, "AKSUNGUR");
    filo[2].yakit = 70;
    filo[2].irtifa = 8000;

    int secim;
    int seciliIHA = 0; 

    while (1) {
        ekranTemizle();
        printf("\n=== UAV FLEET COMMAND SYSTEM ===\n");
        printf("Secili IHA: %s\n", filo[seciliIHA].Model);
        printf("--------------------------------\n");
        printf("1. IHA Degistir\n");
        printf("2. Durum Raporu (Secili IHA)\n");
        printf("3. Yuksel (+1000m, -5 yakit)\n");
        printf("4. Alcal (-1000m, -5 yakit)\n");
        printf("5. Yakit Doldur (Secili IHA)\n");
        printf("6. Tum Filo Durumu\n");
        printf("7. Hizli Yakit Doldur (Tum IHA'lar)\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");

        scanf("%d", &secim);

        switch (secim) {
            case 1: 
                printf("\nIHA Sec:\n");
                for (int i = 0; i < 3; i++) {
                    printf("%d. %s (Yakit:%d%%, Irtifa:%dm)\n", i+1, filo[i].Model, filo[i].yakit, filo[i].irtifa);
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
                printf("\n--- %s DETAYLI DURUM ---\n", filo[seciliIHA].Model);
                printf("Model: %s\n", filo[seciliIHA].Model);
                printf("Yakit: %d%%\n", filo[seciliIHA].yakit);
                printf("Irtifa: %d m\n", filo[seciliIHA].irtifa);
                if (filo[seciliIHA].yakit <= 30) 
                    printf("UYARI: Yakit kritik seviyede!\n");
                else if (filo[seciliIHA].yakit <= 60) 
                    printf("BILGI: Yakit orta seviyede.\n");
                else 
                    printf("DURUM: Yakit durumu iyi.\n");
                break;

            case 3: 
                if (filo[seciliIHA].yakit >= 5) { 
                    filo[seciliIHA].irtifa += 1000;
                    filo[seciliIHA].yakit -= 5;
                    printf("%s yukselis basarili. Yeni irtifa: %d m\n", 
                           filo[seciliIHA].Model, filo[seciliIHA].irtifa);
                } else {
                    printf("YETERSIZ YAKIT! Yukselemezsiniz.\n");
                }
                break;

            case 4: 
                if (filo[seciliIHA].irtifa >= 1000) { 
                    filo[seciliIHA].irtifa -= 1000;
                    filo[seciliIHA].yakit -= 5;
                    printf("%s alcalis basarili. Yeni irtifa: %d m\n", 
                           filo[seciliIHA].Model, filo[seciliIHA].irtifa);
                } else {
                    printf("Zaten yerdesiniz! Daha fazla alcalamazsiniz.\n");
                }
                break;

            case 5: 
                filo[seciliIHA].yakit = 100;
                printf("%s yakit deposu dolduruldu!\n", filo[seciliIHA].Model);
                break;

            case 6: 
                filoDurumu(filo, 3);
                break;

            case 7: 
                for (int i = 0; i < 3; i++) {
                    filo[i].yakit = 100;
                }
                printf("Tum IHA'larin yakit depolari dolduruldu!\n");
                break;

            case 0: 
                printf("UAV Fleet Command System kapatiliyor...\n");
                return 0; 

            default:
                printf("Hatali secim yaptiniz!\n");
        } 
        
        if (secim != 0) {
            printf("\nDevam etmek icin Enter'a basin...");
            while (getchar() != '\n'); 
            getchar();
        }
    } 

    return 0;
}