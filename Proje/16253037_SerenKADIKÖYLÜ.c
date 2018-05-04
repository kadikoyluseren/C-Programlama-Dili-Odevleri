#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct adresler
{
	char mahalle[BUFSIZ];
	char sokak[BUFSIZ];
	char il[BUFSIZ];
	char ilce[BUFSIZ];
};
struct kisiler
{
	char ad[BUFSIZ];     
	char soyad[BUFSIZ];  
	char evTel[BUFSIZ]; 
	char cepTel[BUFSIZ];  
	char isTel[BUFSIZ];  
	char ePosta[BUFSIZ];
	char dogumTarihi[BUFSIZ];
	struct adresler adres;
}kisi;
FILE *dosya;
FILE *gecici;
void menu();
void kisiEkle();
void kisiGoruntule();
void kisiArama();
void kisiGuncelle();
void kisiSil();
void bilgi();
void eskiBilgi();
void dosyayaYaz();
void main()
{
	menu();
}
void dosyayaYaz(FILE *x)
{
	fprintf(x,"%s %s %s %s %s %s %s %s %s %s %s\n",
			kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,
		  	kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,
		    kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce);
}
void eskiBilgi()
{
	printf("\nKisinizin eski bilgileri\n");
   	printf("Ad : %s",kisi.ad);
	printf("\nSoyad : %s",kisi.soyad);
	printf("\nEv Telefonu : %s",kisi.evTel);
	printf("\nCep Telefonu : %s",kisi.cepTel);
	printf("\nIs Telefonu : %s",kisi.isTel);
	printf("\nE-Posta Adresi : %s",kisi.ePosta);	
	printf("\nDogum Tarihi : %s",kisi.dogumTarihi);
	printf("\nMahalle : %s",kisi.adres.mahalle);
	printf("\nSokak : %s",kisi.adres.sokak);
	printf("\nIl : %s",kisi.adres.il);
	printf("\nIlce : %s",kisi.adres.ilce);
}
void bilgi()
{   				
	printf("Ad : "); scanf("%s",kisi.ad);
	printf("Soyad : "); scanf("%s",kisi.soyad);
	printf("Ev Telefonu : "); scanf("%s",kisi.evTel);
	printf("Cep Telefonu : "); scanf("%s",kisi.cepTel);
	printf("Is Telefonu : "); scanf("%s",kisi.isTel);
	printf("E-Posta Adresi : "); scanf("%s",kisi.ePosta);
	printf("Dogum Tarihi (GG.AA.YYYY) : "); scanf("%s",kisi.dogumTarihi);
	printf("Mahalle : "); scanf("%s",kisi.adres.mahalle);
	printf("Sokak : "); scanf("%s",kisi.adres.sokak);
	printf("Il : "); scanf("%s",kisi.adres.il);
	printf("Ilce : "); scanf("%s",kisi.adres.ilce);
}
void menu()
{
	char secim=' ';
	while(secim!='C' && secim!='c')
	{	
		printf("|....... M E N U .......|\n");
		printf("  [E] Kisi Ekleme\n");
		printf("  [L] Kisileri Listeleme\n");
		printf("  [G] Kisi Guncelleme\n");
		printf("  [S] Kisi Silme\n");
		printf("  [A] Kisi Arama\n");
		printf("  [C] Cikis\n");
		printf("Seciminiz : ");
		secim=getch();
		if(secim=='E' || secim=='e')
			kisiEkle();
		else if(secim=='L' || secim=='l')
			kisiGoruntule();
		else if(secim=='G' || secim=='g')
			kisiGuncelle();
		else if(secim=='S' || secim=='s')
			kisiSil();
		else if(secim=='A' || secim=='a')
			kisiArama();
		else if(secim=='C' || secim=='c')
			printf("Cikis yaptiniz...");
		else
		{	
			system("cls");
			printf("Yanlis giris, tekrar deneyin.\n");
		}
	}	
}
void kisiEkle()
{
	system("cls");
	dosya = fopen("telRehber.txt", "a");
	if(dosya!=NULL)
	{
		char yesNo;
		printf("Yeni kisi bilgilerini girin.\n");
		bilgi();
		dosyayaYaz(dosya);
		fclose(dosya);
	}
	else
	{
		printf("Dosya bulunamadi!");
	}		
	char yesNo;
	printf("\nTekrar eklemek ister misiniz? (Evet [E]/Ana Menu [A]/Cikis icin herhangi bir tusa basiniz.)");
	yesNo=getch();
	if(yesNo=='E' || yesNo=='e')
		kisiEkle();
	else if(yesNo=='A' || yesNo=='a' )
	{
		system("cls");
	}
	else 
		exit(1);
}
void kisiGoruntule()
{
	system("cls");
	dosya=fopen("telRehber.txt","r");
	if(dosya!=NULL)
	{
		printf("..................................................................................................................................................................................................................\n");
		printf("       Ad       |     Soyad      |   Ev Telefonu  |  Cep Telefonu  |  Is Telefonu   |           e-Posta             | Dogum Tarihi   |   Mahalle      |    Sokak       |      Il        |    Ilce\n");
		printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		while(fscanf(dosya,"%s%s%s%s%s%s%s%s%s%s%s",
		kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,
		kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,
		kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce)!=EOF)
		{
			printf(" %-15s| %-15s| %-15s| %-15s| %-15s| %-30s| %-15s| %-15s| %-15s| %-15s| %-15s\n",kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce);
		}
		fclose(dosya);
	}
	else
		printf("Dosya bulunamadi!");
	printf("\n(Ana Menu [A]/Cikis icin herhangi bir tusa basiniz.)");
	char yesNo;
	yesNo=getch();
	if(yesNo=='A' || yesNo=='a' )
	{
		system("cls");
	}
	else 
		exit(1);
}
void kisiArama()
{
	system("cls");
	dosya=fopen("telRehber.txt","r");
	if(dosya!=NULL)
	{
		printf("Ada gore arama yapmak icin [A], Dogum tarihine gore arama yapmak icin [D] : ");
		char sec=getch();
		if(sec=='A' || sec=='a')
		{	
			system("cls");
			char aranan[BUFSIZ];
			printf("Aradiginiz kisinin adi : ");
			scanf("%s",aranan);
			int i=0;
			system("cls");
			printf("..................................................................................................................................................................................................................\n");
			printf("       Ad       |     Soyad      |   Ev Telefonu  |  Cep Telefonu  |  Is Telefonu   |           e-Posta             | Dogum Tarihi   |   Mahalle      |    Sokak       |      Il        |    Ilce\n");
			printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
			while(fscanf(dosya,"%s %s %s %s %s %s %s %s %s %s %s ",
			kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,
			kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,
			kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce)!=EOF)
			{
				if(strcmp(kisi.ad,aranan)==0)
				{
					printf(" %-15s| %-15s| %-15s| %-15s| %-15s| %-30s| %-15s| %-15s| %-15s| %-15s| %-15s\n",
					kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,
					kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,
					kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce);
					i++;
				}
			}	
			if(i==0)
			{	system("cls");		
				printf("Aradiginiz kisi bulunamadi!\n");
			}
			else
				printf("\n~%s adinda %d kayit bulundu.\n",aranan, i);
			fclose(dosya);	
			printf("\nAramaya devam etmek ister misiniz? (Evet [E]/Ana Menu [A]/Cikis icin herhangi bir tusa basiniz.)");
			char yesNo=getch();
			if(yesNo=='E' || yesNo=='e')
				kisiArama();
			else if(yesNo=='A' || yesNo=='a' )
			{
				system("cls");
			}
			else 
				exit(1);
		}
		else if(sec=='D' || sec=='d')
		{
			system("cls");
			char aranan[BUFSIZ];
			printf("Aradiginiz kisinin dogum tarihi (GG.AA.YYYY) : ");
			scanf("%s",aranan);
			int i=0;
			system("cls");
			printf("..................................................................................................................................................................................................................\n");
			printf("       Ad       |     Soyad      |   Ev Telefonu  |  Cep Telefonu  |  Is Telefonu   |           e-Posta             | Dogum Tarihi   |   Mahalle      |    Sokak       |      Il        |    Ilce\n");
			printf("------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");	
			while(fscanf(dosya,"%s %s %s %s %s %s %s %s %s %s %s ",
			kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,
			kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,
			kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce)!=EOF)
			{
				if(strcmp(kisi.dogumTarihi,aranan)==0)
				{
					printf(" %-15s| %-15s| %-15s| %-15s| %-15s| %-30s| %-15s| %-15s| %-15s| %-15s| %-15s\n",
					kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,
					kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,
					kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce);
					i++;
				}
			}	
			if(i==0)
			{
				system("cls");		
				printf("Aradiginiz kisi bulunamadi!\n");
			}
			else
				printf("\n~Dogum tarihi %s olan %d kayit bulundu.\n",aranan, i);
			fclose(dosya);	
			printf("\nAramaya devam etmek ister misiniz? (Evet [E]/Ana Menu [A]/Cikis icin herhangi bir tusa basiniz.)");
			char yesNo=getch();
			if(yesNo=='E' || yesNo=='e')
				kisiArama();
			else if(yesNo=='A' || yesNo=='a' )
			{
				system("cls");
			}
			else 
				exit(1);
		}
		else
		{
			system("cls");
			kisiArama();
		}			
	}
	else
	{
		printf("Dosya bulunamadi.");
		getch();
		system("cls");
	}
}
void kisiGuncelle()
{
	system("cls");
	dosya=fopen("telRehber.txt","r");
	gecici=fopen("gecici.txt","w");
	if(dosya!=NULL)
	{
		printf("Guncelleme icin secim");
		printf("\n( Adres[A], Telefon[T], E-Posta[E], Soyad[S] ) : ");
		char sec=getch();
		int i=0;
		if(sec=='A'||sec=='a')
		{
			system("cls");
			char guncellenecekIl[BUFSIZ],guncellenecekIlce[BUFSIZ],guncellenecekMahalle[BUFSIZ],guncellenecekSokak[BUFSIZ];
			printf("Guncellemek istediginiz kisinin eski adres bilgileri\n");
			printf("Mahalle : "); 
			scanf("%s",guncellenecekMahalle);
			printf("Sokak : ");
			scanf("%s",guncellenecekSokak);
			printf("Il : ");
			scanf("%s",guncellenecekIl);
			printf("Ilce : ");
			scanf("%s",guncellenecekIlce);
			while(fscanf(dosya,"%s %s %s %s %s %s %s %s %s %s %s ",
			kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,
			kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,
			kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce)!=EOF)
			{
   				if((strcmp(kisi.adres.il,guncellenecekIl)==0)&&
				   (strcmp(kisi.adres.ilce,guncellenecekIlce)==0)&&
				   (strcmp(kisi.adres.mahalle,guncellenecekMahalle)==0)&&
				   (strcmp(kisi.adres.sokak,guncellenecekSokak)==0))
   				{
   					i++;
   					eskiBilgi();
   					printf("\n\nGuncel bilgileri girin\n");
   					bilgi();
  					dosyayaYaz(gecici);
				}
				else
					dosyayaYaz(gecici);
			}	
			if(i==0)
				printf("Guncellenecek kisi bulunamadi!");		
			fclose(dosya);
			fclose(gecici);
			remove("telRehber.txt");
			rename("gecici.txt","telRehber.txt");
			printf("\nGuncellemeye devam etmek ister misiniz? (Evet [E]/Ana Menu [A]/Cikis icin herhangi bir tusa basiniz.)");
			char yesNo=getch();
			if(yesNo=='E' || yesNo=='e')
				kisiGuncelle();
			else if(yesNo=='A' || yesNo=='a' )
			{
				system("cls");
			}
			else 
				exit(1);
		}
		else if(sec=='T'||sec=='t')
		{	
			system("cls");
			char guncellenecek[BUFSIZ];
			printf("Guncellemek istediginiz kisinin eski telefonunu girin : "); 
			scanf("%s",guncellenecek);
			while(fscanf(dosya,"%s %s %s %s %s %s %s %s %s %s %s ",
			kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,
			kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,
			kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce)!=EOF)
			{
   				if((strcmp(kisi.cepTel,guncellenecek))==0 ||
				   (strcmp(kisi.evTel,guncellenecek))==0 ||
				   (strcmp(kisi.isTel,guncellenecek))==0)
   				{
   					i++;
   					eskiBilgi();
   					printf("\n\nGuncel bilgileri girin\n");
   					bilgi();
					dosyayaYaz(gecici);
				}
				else
					dosyayaYaz(gecici);
			}	
			if(i==0)
				printf("Guncellenecek kisi bulunamadi!");		
			fclose(dosya);
			fclose(gecici);
			remove("telRehber.txt");
			rename("gecici.txt","telRehber.txt");
			printf("\nGuncellemeye devam etmek ister misiniz? (Evet [E]/Ana Menu [A]/Cikis icin herhangi bir tusa basiniz.)");
			char yesNo=getch();
			if(yesNo=='E' || yesNo=='e')
				kisiGuncelle();
			else if(yesNo=='A' || yesNo=='a' )
			{
				system("cls");
			}
			else 
				exit(1);
		}
		else if(sec=='E'||sec=='e')
		{
			system("cls");
			char guncellenecek[BUFSIZ];
			printf("Guncellemek istediginiz kisinin eski e-postasini girin : "); 
			scanf("%s",guncellenecek);
			while(fscanf(dosya,"%s %s %s %s %s %s %s %s %s %s %s ",
			kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,
			kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,
			kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce)!=EOF)
			{
   				if(strcmp(kisi.ePosta,guncellenecek)==0)
   				{
   					i++;
   					eskiBilgi();
   					printf("\n\nGuncel bilgileri girin\n");
   					bilgi();
 					dosyayaYaz(gecici);
				}
				else
					dosyayaYaz(gecici);
			}	
			if(i==0)
				printf("Guncellenecek kisi bulunamadi!");		
			fclose(dosya);
			fclose(gecici);
			remove("telRehber.txt");
			rename("gecici.txt","telRehber.txt");
			printf("\nGuncellemeye devam etmek ister misiniz? (Evet [E]/Ana Menu [A]/Cikis icin herhangi bir tusa basiniz.)");
			char yesNo=getch();
			if(yesNo=='E' || yesNo=='e')
				kisiGuncelle();
			else if(yesNo=='A' || yesNo=='a' )
			{
				system("cls");
			}
			else 
				exit(1);
		}
		else if(sec=='S'||sec=='s')
		{	
			system("cls");
			char guncellenecek[BUFSIZ];
			printf("Guncellemek istediginiz kisinin eski soyadini girin : "); 
			scanf("%s",guncellenecek);
			while(fscanf(dosya,"%s %s %s %s %s %s %s %s %s %s %s ",
			kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,
			kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,
			kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce)!=EOF)
			{
   				if(strcmp(kisi.soyad,guncellenecek)==0)
   				{
   					i++;
   					eskiBilgi();
   					printf("\n\nGuncel bilgileri girin\n");
   					bilgi();
   					dosyayaYaz(gecici);
				}
				else
					dosyayaYaz(gecici);
			}	
			if(i==0)
				printf("Guncellenecek kisi bulunamadi!");		
			fclose(dosya);
			fclose(gecici);
			remove("telRehber.txt");
			rename("gecici.txt","telRehber.txt");
			printf("\nGuncellemeye devam etmek ister misiniz? (Evet [E]/Ana Menu [A]/Cikis icin herhangi bir tusa basiniz.)");
			char yesNo=getch();
			if(yesNo=='E' || yesNo=='e')
				kisiGuncelle();
			else if(yesNo=='A' || yesNo=='a' )
			{
				system("cls");
			}
			else 
				exit(1);
		}
		else
		{
			system("cls");
			kisiArama();
		}			
	}
	else
	{
		printf("Dosya bulunamadi.");
		getch();
		system("cls");
	}
}
void kisiSil()
{
	system("cls");
	dosya=fopen("telRehber.txt","r");
	gecici=fopen("gecici.txt","w");
	if(dosya!=NULL || gecici!=NULL)
	{
		char silinecek[BUFSIZ];
		int i=0;
		printf("Silmek istediginiz kisinin adi :"); 
		scanf("%s",silinecek);
		while(fscanf(dosya,"%s %s %s %s %s %s %s %s %s %s %s ",
		kisi.ad,kisi.soyad,kisi.evTel,kisi.cepTel,kisi.isTel,
		kisi.ePosta,kisi.dogumTarihi,kisi.adres.mahalle,
		kisi.adres.sokak,kisi.adres.il,kisi.adres.ilce)!=EOF)
		{
   			if(strcmp(kisi.ad,silinecek)==0)
   			{	
   				char cevap;
   				printf("\n%s kisisini silmeyi onayliyor musunuz? (Silmek icin [E], vazgecmek icin herhangi bir tusa basiniz) : ",silinecek);
   				cevap=getch();
   				if(cevap=='E' || cevap=='e')
   				{
   					i++;
   					continue;
				}	
   				else
					dosyayaYaz(gecici);
			}
			else
				dosyayaYaz(gecici);
		}	
		if(i==0)
			printf("Silinecek kisi bulunamadi!");					
		fclose(dosya);
		fclose(gecici);
		remove("telRehber.txt");
		rename("gecici.txt","telRehber.txt");	
		printf("\nSilmeye devam etmek ister misiniz? (Evet [E]/Ana Menu [A]/Cikis icin herhangi bir tusa basiniz.)");
		char yesNo=getch();
		if(yesNo=='E' || yesNo=='e')
			kisiSil();
		else if(yesNo=='A' || yesNo=='a' )
		{
			system("cls");
		}
		else 
			exit(1);
	}
	else
	{
		printf("Dosya bulunamadi.");
		getch();
		system("cls");
	}
}
