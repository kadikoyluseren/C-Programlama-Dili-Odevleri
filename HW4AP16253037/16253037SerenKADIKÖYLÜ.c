#include<stdio.h>
#include<math.h>
#include<string.h>
void basariNotu();
void ortalamaBul();
void stdSapma();
void harfNot();
void dosyaOku();
void dosyaYaz();
void ekranaYaz();

struct ogrTip
{ 
	unsigned long ogrNo;
	char ad[15];
	char soyad[15];
	unsigned vize;
	unsigned final;
	unsigned proje;
	unsigned short devam;
	float bNotu;
	char harf[2];	

}ogr[BUFSIZ];

int j,k, i=0;
float ortalama, sapma, toplam=0;
int sayac[11]={0,0,0,0,0,0,0,0,0,0,0};
int harfNotu[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
char harf[11][2] = { { 'A','1' },{ 'A','2' },{ 'B','1' },{ 'B','2' } ,{ 'C','1' },{ 'C','2' },{ 'D','1' },{ 'D','2' },{ 'E',' ' },{ 'F','1' },{ 'F','2' }};

int main()
{	
	dosyaOku(ogr);
	basariNotu(ogr);
	ortalamaBul(ogr);
	stdSapma(ogr);
	harfNot(ogr);
	dosyaYaz(ogr);	
	ekranaYaz(ogr);
}
void dosyaOku(struct ogrTip ogr[])
{
	FILE *dosya;	
	dosya=fopen("CENG101_IN.TXT","r");
	if(dosya!=NULL)
	{
		while(!feof(dosya))
		{
			fscanf(dosya,"%lu %s %s %d %d %d %u",&ogr[i].ogrNo,&ogr[i].ad,&ogr[i].soyad,
			&ogr[i].vize,&ogr[i].final,&ogr[i].proje,&ogr[i].devam);
			i++;
		}
	}
	else
	{
		printf("Dosya bulunamadi");
	}	
	fclose(dosya);
}
void basariNotu(struct ogrTip ogr[])
{
	for(j=0;j<i;j++)
	{
		ogr[j].bNotu=ogr[j].vize*0.3+ogr[j].final*0.4+ogr[j].proje*0.3;
	}
}
void ortalamaBul(struct ogrTip ogr[])
{
	for(j=0;j<i;j++)
	{
		toplam+=ogr[j].bNotu;
	}
	ortalama=toplam/i;
}
void stdSapma(struct ogrTip ogr[])
{
	float pay = 0;
	for (j = 0; j < i; j++)
	{
		pay += pow((ortalama - ogr[j].bNotu), 2);
	}
	sapma = sqrt(pay / (i-1));
}
void harfNot(struct ogrTip ogr[])
{
		for (j = 0; j < i; j++)
	{
		if (ogr[j].bNotu >= 89.5)
		{
			strcpy(ogr[j].harf,"A1");
			sayac[0]++;
		}
		else if (ogr[j].bNotu >= 79.5)
		{
			strcpy(ogr[j].harf,"A2");
			sayac[1]++;	
		}
		else if (ogr[j].bNotu >= 74.5)
		{
			strcpy(ogr[j].harf,"B1");
			sayac[2]++;
		}
		else if (ogr[j].bNotu >= 69.5)
		{
			strcpy(ogr[j].harf,"B2");
			sayac[3]++;
		}
		else if (ogr[j].bNotu >= 64.5)
		{
			strcpy(ogr[j].harf,"C1");
			sayac[4]++;
		}
		else if (ogr[j].bNotu >= 59.5)
		{
			strcpy(ogr[j].harf,"C2");
			sayac[5]++;
		}
		else if (ogr[j].bNotu >= 54.5)
		{
			strcpy(ogr[j].harf,"D1");
			sayac[6]++;
		}
		else if (ogr[j].bNotu >= 49.5)
		{
			strcpy(ogr[j].harf,"D2");
			sayac[7]++;
		}
		else if (ogr[j].bNotu >= 39.5)
		{
			strcpy(ogr[j].harf,"E");
			sayac[8]++;
		}
		else if (ogr[j].bNotu >= 0)
		{	
			if(ogr[j].devam==1)
			{
				strcpy(ogr[j].harf,"F1");
				sayac[9]++;
			}
			else
			{
				strcpy(ogr[j].harf,"F2");
				sayac[10]++;
			}
		}
	}
}	
void dosyaYaz(struct ogrTip ogr[])
{
	FILE *dosya2;
	dosya2=fopen("CENG101_OUT.TXT","w");

	fprintf(dosya2,"OGRENCI#\tAD\t\tSOYAD\t\t VIZE\tFINAL\tPROJE\tB.NOTU\tHARF\n");
	fprintf(dosya2,"====================================================================================\n");

	for(j=0;j<i;j++)
	{
		fprintf(dosya2,"%-15lu %-15s %-12s %7d %7d %7d %7.0f\t%s\n",ogr[j].ogrNo,ogr[j].ad,ogr[j].soyad,
		ogr[j].vize,ogr[j].final,ogr[j].proje,ogr[j].bNotu,ogr[j].harf);
	}
	fprintf(dosya2,"Ogrenci Sayisi: %d\n",i);
	fprintf(dosya2,"Basari Notlari Ortalamasi: %5.2f\n",ortalama);
	fprintf(dosya2,"Basari Notlari Standart Sapmasi: %5.2f\n",sapma);
	
	for(j=0;j<11;j++)
	{
		for(k=0;k<2;k++)
			fprintf(dosya2,"%c",harf[j][k]);
		fprintf(dosya2,": %d\n",sayac[j]);
	}
		fclose(dosya2);	
}
void ekranaYaz(struct ogrTip ogr[])
{	
	printf("OGRENCI#\tAD\t\tSOYAD\t\t VIZE\tFINAL\tPROJE\tB.NOTU\tHARF\n");
	printf("====================================================================================\n");

	for(j=0;j<i;j++)
	{
		printf("%-15lu %-15s %-12s %7d %7d %7d %7.0f\t%s\n",ogr[j].ogrNo,ogr[j].ad,ogr[j].soyad,
		ogr[j].vize,ogr[j].final,ogr[j].proje,ogr[j].bNotu,ogr[j].harf);
	}
	printf("Ogrenci Sayisi: %d\n",i);
	printf("Basari Notlari Ortalamasi: %5.2f\n",ortalama);
	printf("Basari Notlari Standart Sapmasi: %5.2f\n",sapma);
	
	for(j=0;j<11;j++)
	{
		for(k=0;k<2;k++)
			printf("%c",harf[j][k]);
		printf(": %d\n",sayac[j]);
	}
}
