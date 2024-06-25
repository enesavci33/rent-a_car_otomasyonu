#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//21100011059/ENES/AVCI


typedef struct araba_ozellik
{
    int araba_no;
    char renk[20];
    int yil;
    int km;
    float alis;
    float satis;
    float araba_kar;
    float motor_hacmi;
    char yakit_tipi[10];
    char kasa_tipi[10];
    int hasar_kaydi;
    char boya_durum[40];
    int kira_bedel;
    int komisyon;
} araba_ozellik;
typedef struct
{
    char araba_marka[20];
    int araba_adet;
    char araba_model[20];
    araba_ozellik *araba_ozellik;

} araba;

int deneme=0; //araba sayisini tutmak
araba *ptr=NULL;
void ekle()
{
    int i;
    printf("**********ARAC EKLEME FONKSIYONUNA HOSGELDINIZ**********\n");
    printf("Arabanin belirtilecek ozelliklerini giriniz\n");
    if(ptr==NULL)
    {
        deneme=deneme+1;
        ptr= (araba *)calloc(sizeof(araba),1);
        if(ptr== NULL)
        {
            printf("Hata! hafiza tahsis edilmedi.");
            exit(0);
        }

        printf("Araba Marka: ");
        scanf("%s", &ptr->araba_marka);

        printf("Araba Model: ");
        scanf("%s", &ptr->araba_model);

        printf("Araba Adet: ");
        scanf("%d", &ptr->araba_adet);

        ptr->araba_ozellik = calloc(sizeof(*ptr->araba_ozellik),ptr->araba_adet);
        if(ptr->araba_ozellik == NULL)
        {
            printf("Hata! hafiza tahsis edilmedi.");
            exit(0);
        }
        int i;
        for(i=0; i<ptr->araba_adet; i++)
        {
            printf("\n%d. Araba Bilgileri\n\n",i+1);
            printf("Araba no:");
            scanf("%d", &(ptr->araba_ozellik+i)->araba_no);
            printf("Araba Rengi: ");
            scanf("%s", &(ptr->araba_ozellik+i)->renk);
            printf("Araba Uretim Yili: ");
            scanf("%d", &(ptr->araba_ozellik+i)->yil);
            printf("Araba Km: ");
            scanf("%d", &(ptr->araba_ozellik+i)->km);
            printf("Araba Alis Fiyat: ");
            scanf("%f", &(ptr->araba_ozellik+i)->alis);
            printf("Araba Satis Fiyat: ");
            scanf("%f", &(ptr->araba_ozellik+i)->satis);
            printf("Araba Motor Hacmi: ");
            scanf("%f", &(ptr->araba_ozellik+i)->motor_hacmi);
            printf("Araba Yakit Tipi: "); // char tipinde tanimlandi YAKiT TiPi->BENZiN DiZEL LPG ELEKTRiKLi
            scanf("%s", &(ptr->araba_ozellik+i)->yakit_tipi);
            printf("Araba Kasa Tipi: "); // char tipinde tanimlandi KASA TiPLERi ->SEDAN HATCHBACK STATIONWAGON
            scanf("%s", &(ptr->araba_ozellik+i)->kasa_tipi);
            printf("Araba hasar kaydi: ");
            scanf("%d", &(ptr->araba_ozellik+i)->hasar_kaydi);
            printf("Araba boya durum: "); // char tipinde tanimlandi BOYA DURUM-> LOKAL KOMPLE BOYALi BOYASiZ
            scanf("%s", &(ptr->araba_ozellik+i)->boya_durum);
            printf("Araba gunluk kira bedeli: ");
            scanf("%d",&(ptr->araba_ozellik+i)->kira_bedel);
            printf("Arabadan alinacak galeri komisyonu:%% ");
            scanf("%d",&(ptr->araba_ozellik+i)->komisyon);

        }
    }
    else
    {
        deneme=deneme+1;
        ptr = (araba *)realloc(ptr, deneme * sizeof(araba));
        printf("Araba Marka: ");
        scanf("%s", &(ptr+deneme-1)->araba_marka);
        printf("Araba Model: ");
        scanf("%s", &(ptr+deneme-1)->araba_model);
        printf("Araba Adet: ");
        scanf("%d", &(ptr+deneme-1)->araba_adet);
        (ptr+deneme-1)->araba_ozellik = calloc(sizeof(araba_ozellik),(ptr+deneme-1)->araba_adet);
        if((ptr+deneme-1)->araba_ozellik == NULL)
        {
            printf("Hata! hafiza tahsis edilmedi.");
            exit(0);
        }
        int i;
        for(i=0; i<(ptr+deneme-1)->araba_adet; i++)
        {
            printf("\n%d. Araba Bilgileri\n\n",i+1);
            printf("Araba no:");
            scanf("%d", &((ptr+(deneme-1))->araba_ozellik+i)->araba_no);
            printf("Araba Rengi: ");
            scanf("%s", &((ptr+(deneme-1))->araba_ozellik+i)->renk);
            printf("Araba Uretim Yili: ");
            scanf("%d", &((ptr+(deneme-1))->araba_ozellik+i)->yil);
            printf("Araba Km: ");
            scanf("%d", &((ptr+(deneme-1))->araba_ozellik+i)->km);
            printf("Araba Alis Fiyat: ");
            scanf("%f", &((ptr+(deneme-1))->araba_ozellik+i)->alis);
            printf("Araba Satis Fiyat: ");
            scanf("%f", &((ptr+(deneme-1))->araba_ozellik+i)->satis);
            printf("Araba Motor Hacmi: ");
            scanf("%f", &((ptr+(deneme-1))->araba_ozellik+i)->motor_hacmi);
            printf("Araba Yakit Tipi: ");
            scanf("%s", &((ptr+(deneme-1))->araba_ozellik+i)->yakit_tipi);
            printf("Araba Kasa Tipi: ");
            scanf("%s", &((ptr+(deneme-1))->araba_ozellik+i)->kasa_tipi);
            printf("Araba hasar kaydi: ");
            scanf("%d", &((ptr+(deneme-1))->araba_ozellik+i)->hasar_kaydi);
            printf("Araba boya durum: ");
            scanf("%s", &((ptr+(deneme-1))->araba_ozellik+i)->boya_durum);
            printf("Araba gunluk kira bedeli: ");
            scanf("%d",&((ptr+(deneme-1))->araba_ozellik+i)->kira_bedel);
            printf("Arabadan alinacak galeri komisyonu:%% ");
            scanf("%d",&((ptr+(deneme-1))->araba_ozellik+i)->komisyon);
        }
    }
}


void goruntule()
{
    int i;
    int j;
    printf("**********ARABALARIMIZ HOSGELDINIZ**********\n");
    for(i=0; i<deneme; i++)
    {
        if(strcmp((ptr+i)->araba_model,"\0")==0)
        {
            continue;
        }

        for(j=0; j<(ptr+i)->araba_adet; j++)
        {
            if(((ptr+i)->araba_ozellik+j)->araba_no==0)
            {
                continue;
            }
            printf("\n\n**********************************************\n");
            printf("Araba Marka: %s\n",(ptr+i)->araba_marka);
            printf("Araba Model: %s\n",(ptr+i)->araba_model);
            printf("--------------------------------------------------\n");
            printf("%s marka %s model arac ozellikleri:\n",(ptr+i)->araba_marka,(ptr+i)->araba_model);
            printf("Araba no:%d\n",((ptr+i)->araba_ozellik+j)->araba_no);
            printf("Araba Renk: %s\n",((ptr+i)->araba_ozellik+j)->renk);
            printf("Araba Yil: %d\n",((ptr+i)->araba_ozellik+j)->yil);
            printf("Araba km: %d\n",((ptr+i)->araba_ozellik+j)->km);
            printf("Araba alis:%.2f\n",((ptr+i)->araba_ozellik+j)->alis);
            printf("Araba satis:%.2f\n",((ptr+i)->araba_ozellik+j)->satis);
            printf("Araba motor hacmi:%.1f\n",((ptr+i)->araba_ozellik+j)->motor_hacmi);
            printf("Araba yakit tipi:%s\n",((ptr+i)->araba_ozellik+j)->yakit_tipi);
            printf("Araba kasa tipi:%s\n",((ptr+i)->araba_ozellik+j)->kasa_tipi);
            printf("Araba hasar kaydi:%d\n",((ptr+i)->araba_ozellik+j)->hasar_kaydi);
            printf("Araba boya durumu :%s\n",((ptr+i)->araba_ozellik+j)->boya_durum);
            printf("Araba gunluk kira bedeli:%d\n",((ptr+i)->araba_ozellik+j)->kira_bedel);
            printf("Arabadan alinacak galeri komisyonu:%% %d\n",((ptr+i)->araba_ozellik+j)->komisyon);
        }

    }
}

void guncelleme()
{
    int i,j,deger;
    char araba_tur[20];
    printf("\n**********ARABA GUNCELLEME**********\n");
    printf("Guncellenecek arabanin modelini giriniz:");
    scanf("%s",&araba_tur);
    printf("Guncellenecek arabanin numarasini giriniz:");
    scanf("%d",&deger);
    for(i=0; i<deneme; i++)
    {
        if(strcmp((ptr+i)->araba_model,araba_tur)==0)
        {
            for(j=0; j<(ptr+i)->araba_adet; j++)
            {
                if(((ptr+i)->araba_ozellik+j)->araba_no==deger)
                {
                    printf("Guncel Km: ");
                    scanf("%d",&((ptr+i)->araba_ozellik+j)->km);
                    printf("Guncel Satis Fiyat: ");
                    scanf("%f",&((ptr+i)->araba_ozellik+j)->satis);
                    printf("Guncel hasar kaydi: ");
                    scanf("%d",&((ptr+i)->araba_ozellik+j)->hasar_kaydi);
                    printf("Guncel boya durumu:");
                    scanf("%s",&((ptr+i)->araba_ozellik+j)->boya_durum);
                    printf("Guncel kira bedeli:");
                    scanf("%d",&((ptr+i)->araba_ozellik+j)->kira_bedel);
                    printf("Guncel komisyon bedeli:");
                    scanf("%d",&((ptr+i)->araba_ozellik+j)->komisyon);
                }
                else
                {
                    printf("HATALI TUSLAMA YAPTINIZ ARADIGINIZ ARAC BULUNMAMAKTADIR!!!\n");
                    printf("Ana menuye yonlendirildiniz\n");
                }
            }
        }
    }
}
void silme()
{
    int i,j,deger;
    char araba_tur[20];
    printf("**********SILME**********\n");
    printf("Silinecek arabanin modelini giriniz:");
    scanf("%s",&araba_tur);
    printf("Silinecek arabanin numarasini giriniz:");
    scanf("%d",&deger);

    for(i=0; i<deneme; i++)
    {
        if(strcmp((ptr+i)->araba_model,araba_tur)==0)
        {
            for(j=0; j<(ptr+i)->araba_adet; j++)
            {
                if(((ptr+i)->araba_ozellik+j)->araba_no==deger)
                {
                    ((ptr+i)->araba_ozellik+j)->araba_no=0;
                }
                else
                {
                    printf("HATALI TUSLAMA YAPTINIZ ARADIGINIZ ARAC BULUNMAMAKTADIR!!!\n");
                    printf("Ana menuye yonlendirildiniz\n");
                }
            }
        }
    }
}

void karimiz()
{
    int i,j,deger;
    char araba_tur[20];
    float alisfiyat,satisfiyat;
    float malsahibikar,komisyoncu,komisyon_sonuc;
    printf("**********KAR HESAPLAMA**********\n");
    printf("Kari belirlenecek arabanin modelini giriniz:");
    scanf("%s",&araba_tur);
    printf("Kari belirlenecek arabanin numarasini giriniz:");
    scanf("%d",&deger);
    for(i=0; i<deneme; i++)
    {
        if(strcmp((ptr+i)->araba_model,araba_tur)==0)
        {
            for(j=0; j<(ptr+i)->araba_adet; j++)
            {
                if(((ptr+i)->araba_ozellik+j)->araba_no==deger)
                {

                    printf("\n*****ARABADAN ELDE EDILEN KAR*****\n");
                    printf("ARABA MARKA: %s\n",(ptr+i)->araba_marka);
                    printf("ARABA MODEL: %s\n",(ptr+i)->araba_model);

                    printf("****************************************\n");
                    printf("%s marka %s model %d.aracindan elde edilen kar bilgisi :\n",(ptr+i)->araba_marka,(ptr+i)->araba_model,j+1);
                    alisfiyat=((ptr+i)->araba_ozellik+j)->alis;
                    satisfiyat=((ptr+i)->araba_ozellik+j)->satis;
                    komisyoncu=((ptr+i)->araba_ozellik+j)->komisyon;
                    komisyon_sonuc=((satisfiyat-alisfiyat)*((ptr+i)->araba_ozellik)->komisyon)/100;
                    malsahibikar=((satisfiyat-alisfiyat)-komisyon_sonuc);
                    printf("Mal sahibinin araba uzerinden kari:%.2f\n",malsahibikar);
                    printf("Galericinin araba uzerinden kari:%.2f\n",komisyon_sonuc);
                    printf("****************************************\n");
                }
                else
                {
                    printf("HATALI TUSLAMA YAPTINIZ ARADIGINIZ ARAC BULUNMAMAKTADIR!!!\n");
                    printf("Ana menuye yonlendirildiniz\n");
                }
            }


        }
    }
}


void kiralama()
{
    int tercih,i,j,secnum;
    char secmodel[20];
    float dolar,euro;
    printf("**********KIRALAMA**********\n");
    printf("*************************************\n");
    printf("Su anki dolar kurunu giriniz:");
    scanf("%f",&dolar);
    printf("Su anki euro kurunu giriniz:");
    scanf("%f",&euro);
    printf("*************************************\n");
    printf("Yabanci uyruklu musunuz? (EVET=1 HAYIR=2)=");
    scanf("%d",&tercih);
    if(tercih==1)
    {
        printf("ULKEMIZE HOSGELDINIZ\n");
        goruntulekira();
        printf("sectiginiz arabanin modelini giriniz:");
        scanf("%s",&secmodel);
        printf("sectiginiz arabanin numarasini giriniz:");
        scanf("%d",&secnum);
        for(i=0; i<deneme; i++)
        {
            if(strcmp((ptr+i)->araba_model,secmodel)==0 )
            {
                for(j=0; j<(ptr+i)->araba_adet; j++)
                {
                    if(((ptr+i)->araba_ozellik+j)->araba_no==secnum)
                    {
                        printf("Sectiginiz arabanin gunluk kiralama bedeli TL olarak= %d\n",((ptr+i)->araba_ozellik+j)->kira_bedel);
                        printf("Sectiginiz arabanin gunluk kiralama bedeli $(DOLAR)olarak= %.2f\n",((ptr+i)->araba_ozellik+j)->kira_bedel/dolar);
                        printf("Sectiginiz arabanin gunluk kiralama bedeli EURO olarak= %.2f\n",((ptr+i)->araba_ozellik+j)->kira_bedel/euro);

                    }
                    else
                    {
                        printf("HATALI TUSLAMA YAPTINIZ ARADIGINIZ ARAC BULUNMAMAKTADIR!!!\n");
                        printf("Ana menuye yonlendirildiniz\n");
                    }

                }
            }
        }
    }

    if(tercih==2)
    {
        printf("*************************************\n");
        printf("***********HOSGELDINIZ***********\n");
        printf("*************************************\n");
        goruntulekira();
        printf("sectiginiz arabanin modelini giriniz:");
        scanf("%s",&secmodel);
        printf("sectiginiz arabanin numarasini giriniz:");
        scanf("%d",&secnum);

        for(i=0; i<deneme; i++)
        {
            if(strcmp((ptr+i)->araba_model,secmodel)==0)
            {
                for(j=0; j<(ptr+i)->araba_adet; j++)
                {
                    if(((ptr+i)->araba_ozellik+j)->araba_no==secnum)
                    {
                        printf("Sectiginiz arabanin gunluk kiralama bedeli TL olarak= %d\n",((ptr+i)->araba_ozellik)->kira_bedel);

                    }
                    else
                    {
                        printf("HATALI TUSLAMA YAPTINIZ ARADIGINIZ ARAC BULUNMAMAKTADIR!!!\n");
                        printf("Ana menuye yonlendirildiniz\n");
                    }
                }
            }
        }
    }
    else
    {
        printf("HATALI TUSLAMA YAPTINIZ!!!\n");
        printf("Ana menuye yonlendirildiniz\n");
    }
}
goruntulekira()
{
    int i=0;
    int j;
    printf("**********ARABALARIMIZ**********\n");
    for(i=0; i<deneme; i++)
    {
        printf("**********************************************\n");
        printf("Araba Marka: %s\n",(ptr+i)->araba_marka);
        printf("Araba Model: %s\n",(ptr+i)->araba_model);

        for(j=0; j<(ptr+i)->araba_adet; j++)
        {
            printf("--------------------------------------------------\n");
            printf("%s marka %s model arac ozellikleri:\n",(ptr+i)->araba_marka,(ptr+i)->araba_model);
            printf("Araba no:%d\n",((ptr+i)->araba_ozellik+j)->araba_no);
            printf("Araba Renk: %s\n",((ptr+i)->araba_ozellik+j)->renk);
            printf("Araba Yil: %d\n",((ptr+i)->araba_ozellik+j)->yil);
            printf("Araba km: %d\n",((ptr+i)->araba_ozellik+j)->km);
            printf("Araba motor hacmi:%.2f\n",((ptr+i)->araba_ozellik+j)->motor_hacmi);
            printf("Araba yakit tipi:%s\n",((ptr+i)->araba_ozellik+j)->yakit_tipi);
            printf("Araba kasa tipi:%s\n",((ptr+i)->araba_ozellik+j)->kasa_tipi);
            printf("Araba gunluk kira bedeli:%d\n",((ptr+i)->araba_ozellik+j)->kira_bedel);
            printf("*************************************\n");

        }
    }
}






int main()
{
    int secim,i;
    while(secim!=-1)
    {
karar:
        printf("****************************************");
        printf("\n**********AVCI GALERI**********\n");
        printf("LUTFEN 1-6 ARASINDA SAYI GIRINIZ\n");
        printf("****************************************\n");
        printf("LUTFEN BIR FONKSIYON SECINIZ\n\n");
        printf("1-ARABA EKLEME\n");
        printf("-------------------\n");
        printf("2-ARABA BILGILERI GUNCELLEME\n");
        printf("-------------------\n");
        printf("3-ARABALARI LISTELEME \n");
        printf("-------------------\n");
        printf("4-ARABA SILME\n");
        printf("-------------------\n");
        printf("5-KAR HESAPLAMA\n");
        printf("-------------------\n");
        printf("6-KIRALAMA\n");
        printf("-------------------\n");
        printf("CIKIS ICIN -1'E BASINIZ\n");
        printf("-------------------\n");
        scanf("%d",&secim);
        printf("****************************************\n\n");
        if(secim>6|| secim<-1)

        {
            printf("Hatali tuslama yaptiniz\nLutfen gecerli bir tuslama yapiniz\n");
        }
        switch(secim)
        {
        case 1:
            ekle();
            break;
        case 2:
            guncelleme();
            break;
        case 3:
            goruntule();
            break;
        case 4:
            silme();
            break;
        case 5:
            karimiz();
            break;
        case 6:
            kiralama();
            break;
        case -1:
            printf("BIZI TERCIH ETTIGINIZ ICIN TESEKKUR EDERIZ............AVCI GALERI............");
            break;

        }
    }



    return 0;
}
