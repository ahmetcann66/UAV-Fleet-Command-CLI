#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

struct GorevNode {
    int islemID;
    struct GorevNode *next;
};

struct GorevNode *gorevListesiBas = NULL;
struct GorevNode *gorevListesiSon = NULL;

struct IHA {
    char Model[20];
    int yakit;
    int irtifa;
    int muhimmat; 
};

struct IHA filo[3];
int seciliIHA = 0; 
int hedefKilitli = 0;

void bekle(int saniye) {
#ifdef _WIN32
    Sleep(saniye * 1000);
#else
    sleep(saniye);
#endif
}

void logKaydet(char* tur, char* detay) {
    FILE *fp = fopen("ucus_kayitlari.txt", "a");
    if (fp == NULL) return;

    time_t rawtime;
    struct tm * timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    fprintf(fp, "[%02d-%02d-%04d %02d:%02d:%02d] [%s] %s\n", 
            timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,
            tur, detay);

    fclose(fp);
}

void gorevKaydet() {
    FILE *fp = fopen("mission_data.dat", "wb");
    if (fp == NULL) {
        printf("HATA: Kayit dosyasi olusturulamadi!\n");
        return;
    }
    fwrite(filo, sizeof(struct IHA), 3, fp);
    fclose(fp);
    printf(">>> TUM GOREV VERILERI BASARIYLA KAYDEDILDI (Binary) <<<\n");
    logKaydet("SAVE", "Gorev durumu mission_data.dat dosyasina kaydedildi.");
}

void gorevYukle() {
    FILE *fp = fopen("mission_data.dat", "rb");
    if (fp == NULL) {
        printf("HATA: Kayitli gorev bulunamadi!\n");
        return;
    }
    fread(filo, sizeof(struct IHA), 3, fp);
    fclose(fp);
    printf(">>> ESKI GOREV VERILERI YUKLENDI <<<\n");
    logKaydet("LOAD", "Gorev durumu dosyadan geri yuklendi.");
}

void gorevEkle(int id) {
    struct GorevNode *yeniGorev = (struct GorevNode*) malloc(sizeof(struct GorevNode));
    yeniGorev->islemID = id;
    yeniGorev->next = NULL;

    if (gorevListesiBas == NULL) {
        gorevListesiBas = yeniGorev;
        gorevListesiSon = yeniGorev;
    } else {
        gorevListesiSon->next = yeniGorev;
        gorevListesiSon = yeniGorev;
    }
    printf("[+] Gorev kuyruga eklendi: ID %d\n", id);
}

void ihaSekliCiz(int modelIndex) {
    printf("\n");
    if (modelIndex == 0) {
        printf("      __!__\n");
        printf("-----o(.)o-----\n");
        printf("     TB2-BAY\n");
    } 
    else if (modelIndex == 1) {
        printf("       | \n");
        printf("   ---=|=---\n");
        printf("    \\_|^|_/    \n");
        printf("    AKINCI-TIHA\n");
    } 
    else if (modelIndex == 2) {
        printf("    /-----\\ \n");
        printf("---(  O.O  )---\n");
        printf("    \\_____/    \n");
        printf("   AKSUNGUR-TW\n");
    }
    printf("\n");
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
    logKaydet("INFO", "Filo durum raporu goruntulendi.");
}

int carpismaVarmi(int hedefIrtifa) {
    if (hedefIrtifa == 0) return 0; 
    for (int i = 0; i < 3; i++) { 
        if (i != seciliIHA && filo[i].irtifa == hedefIrtifa) {
            printf("\n!!! KRITIK UYARI: %dm irtifada %s var! Carpisma riski !!!\n", hedefIrtifa, filo[i].Model);
            logKaydet("UYARI", "Carpisma riski nedeniyle manevra engellendi.");
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
        logKaydet("RADAR", "Hedef kilitlendi.");
    } else {
        hedefKilitli = 0;
        printf("[RADAR] Bolge temiz. Tehdit unsuru bulunamadi.\n");
        logKaydet("RADAR", "Tarama temiz.");
    }
}

void atisYap() {    
    if (filo[seciliIHA].irtifa == 0) {
        printf("\nUYARI: Guvenlik kilidi devrede! Yerdeyken atis yapilamaz.\n");
        return;
    }
    if (hedefKilitli == 0) {
        printf("\n[HATA] HEDEF KILITLI DEGIL! Atis yapilamaz.\n");
        return;
    }
    if (filo[seciliIHA].muhimmat > 0) {
        printf("\n*** FUSELAGE RELEASED ***\n");
        printf(">>> %s ATIS YAPTI! HEDEF IMHA EDILDI. <<<\n", filo[seciliIHA].Model);
        filo[seciliIHA].muhimmat--; 
        logKaydet("ATIS", "Basarili atis gerceklestirildi.");
    } else {
        printf("\n!!! UYARI: Muhimmat tukendi! !!!\n");
        logKaydet("UYARI", "Muhimmat bittigi icin atis yapilamadi.");
    }
    hedefKilitli = 0; 
}

void gorevleriCalistir() {
    struct GorevNode *temp = gorevListesiBas;
    printf("\n>>> OTONOM GOREV MODU BASLATILIYOR <<<\n");
    logKaydet("OTONOM", "Gorev zinciri baslatildi.");

    int adim = 1;
    while (temp != NULL) {
        printf("\n--- Gorev Adimi %d Isleniyor ---\n", adim);
        bekle(1);

        if (temp->islemID == 1) {
             printf("[AUTO] Yukselis komutu...\n");
             if (filo[seciliIHA].yakit >= 5) {
                 filo[seciliIHA].irtifa += 1000;
                 filo[seciliIHA].yakit -= 5;
                 printf("Irtifa: %dm\n", filo[seciliIHA].irtifa);
             }
        }
        else if (temp->islemID == 2) {
            printf("[AUTO] Alcalis komutu...\n");
            if (filo[seciliIHA].irtifa >= 1000) {
                filo[seciliIHA].irtifa -= 1000;
                filo[seciliIHA].yakit -= 5;
                printf("Irtifa: %dm\n", filo[seciliIHA].irtifa);
            }
        }
        else if (temp->islemID == 3) {
            printf("[AUTO] Radar Taramasi...\n");
            radarTaramasi();
        }
        else if (temp->islemID == 4) {
            printf("[AUTO] Atis Kontrol...\n");
            atisYap();
        }

        struct GorevNode *silinecek = temp;
        temp = temp->next;
        free(silinecek);
        adim++;
    }

    gorevListesiBas = NULL;
    gorevListesiSon = NULL;
    printf("\n>>> TUM GOREVLER TAMAMLANDI. LINKED LIST TEMIZLENDI. <<<\n");
    logKaydet("OTONOM", "Gorev zinciri tamamlandi ve hafiza temizlendi.");
}

int main() {
    srand(time(NULL));
    logKaydet("SISTEM", "Sistem baslatildi (V4.0).");
    
    strcpy(filo[0].Model, "TB2"); filo[0].yakit=100; filo[0].irtifa=0; filo[0].muhimmat=4; 
    strcpy(filo[1].Model, "AKINCI"); filo[1].yakit=85; filo[1].irtifa=5000; filo[1].muhimmat=8; 
    strcpy(filo[2].Model, "AKSUNGUR"); filo[2].yakit=70; filo[2].irtifa=8000; filo[2].muhimmat=6; 

    int secim;
    while (1) {
        printf("\n=== UAV FLEET COMMAND (V4.0 - PERSISTENCE) ===\n");
        printf("Secili: %s (Alt: %dm | Ammo: %d)\n", filo[seciliIHA].Model, filo[seciliIHA].irtifa, filo[seciliIHA].muhimmat);
        printf("---------------------------------------\n");
        printf("1. IHA Degistir\n");
        printf("2. Durum Raporu\n");
        printf("3. Yuksel\n");
        printf("4. Alcal\n");
        printf("5. ATIS YAP\n"); 
        printf("6. Filo Durumu\n");
        printf("7. Bakim\n");
        printf("8. RADAR\n");
        printf("9. GOREV PLANLAYICI (Auto)\n");
        printf("10. GOREV KAYDET (Save)\n");
        printf("11. GOREV YUKLE (Load)\n");
        printf("0. Cikis\n");
        printf("Secim: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1: 
                seciliIHA = (seciliIHA + 1) % 3;
                printf("Aktif IHA: %s\n", filo[seciliIHA].Model);
                ihaSekliCiz(seciliIHA);
                break;
            case 2: filoDurumu(3); break;
            case 3: 
                if(!carpismaVarmi(filo[seciliIHA].irtifa + 1000)) {
                    filo[seciliIHA].irtifa += 1000; filo[seciliIHA].yakit -= 5;
                    logKaydet("MANUEL", "Yukselis yapildi.");
                }
                break;
            case 4: 
                if(filo[seciliIHA].irtifa > 0) {
                    filo[seciliIHA].irtifa -= 1000; filo[seciliIHA].yakit -= 5;
                    logKaydet("MANUEL", "Alcalis yapildi.");
                }
                break;
            case 5: atisYap(); break;
            case 6: filoDurumu(3); break;
            case 7: printf("Bakim yapildi.\n"); logKaydet("BAKIM", "Onarim tamamlandi."); break;
            case 8: radarTaramasi(); break;
            
            case 9:
                printf("\n--- GOREV PLANLAYICI (Kuyruk Olustur) ---\n");
                printf("1. Yuksel Ekle\n2. Alcal Ekle\n3. Tara Ekle\n4. Atis Ekle\n5. BASLAT\nSecim: ");
                int gSecim;
                while(1) {
                    scanf("%d", &gSecim);
                    if (gSecim == 5) { gorevleriCalistir(); break; }
                    else if (gSecim >= 1 && gSecim <= 4) { gorevEkle(gSecim); printf("Sonraki komut (5: Baslat): "); }
                    else { printf("Gecersiz. Tekrar: "); }
                }
                break;

            case 10: gorevKaydet(); break;
            case 11: gorevYukle(); break;

            case 0: return 0;
        } 
    } 
    return 0;
}