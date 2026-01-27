#include <stdio.h>
#include <string.h>

struct IHA {
    char Model[20];
    int yakit;
    int irtifa;
};

int main() {
    
    struct IHA IHA1;
    strcpy(IHA1.Model, "TB2");
    IHA1.yakit = 100;
    IHA1.irtifa = 0;

    int secim; 

   
    while (1) {
        printf("\n\n----- %s DURUM RAPORU -----\n", IHA1.Model);
        printf("Mevcut Yakit: %d | Mevcut Irtifa: %d m\n", IHA1.yakit, IHA1.irtifa);
        printf("---------------------------\n");
        printf("1. Durum Raporu (Detayli)\n");
        printf("2. Yuksel (Irtifa +1000m, Yakit -5)\n");
        printf("3. Alcal (Irtifa -1000m, Yakit -5)\n");
        printf("4. Yakiti Doldur\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");

        
        scanf("%d", &secim);

        
        switch (secim) {
            case 1: 
                if (IHA1.yakit <= 30) printf("UYARI: Yakit Kritik Seviyede!\n");
                else printf("Yakit durumu iyi.\n");
                break;

            case 2: 
                if (IHA1.yakit >= 5) { 
                    IHA1.irtifa += 1000;
                    IHA1.yakit -= 5;
                    printf("Yukselis basarili. Yeni Irtifa: %d\n", IHA1.irtifa);
                } else {
                    printf("YETERSIZ YAKIT! Yukselemezsin.\n");
                }
                break;

            case 3: 
                if (IHA1.irtifa >= 1000) { 
                    IHA1.irtifa -= 1000;
                    IHA1.yakit -= 5;
                    printf("Alcalis basarili. Yeni Irtifa: %d\n", IHA1.irtifa);
                } else {
                    printf("Zaten yerdesiniz! Daha fazla alcalamazsiniz.\n");
                }
                break;

            case 4: 
                IHA1.yakit = 100;
                printf("Depo fullendi!\n");
                break;

            case 0: 
                printf("Sistem Kapatiliyor...\n");
                return 0; 

            default:
                printf("Hatali secim yaptiniz!\n");
        } 
    } 

    return 0;
}