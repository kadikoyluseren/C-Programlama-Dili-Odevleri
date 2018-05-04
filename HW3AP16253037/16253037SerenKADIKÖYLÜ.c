#include <stdio.h>
#include<math.h>
#include<conio.h>

void giris(int no[], int notu[], int N);
float ortalama(int notu[], int N);
void goruntule(int no[], int notu[], int N);
void otele(int notu[], int N);
void notKB(int no[], int notu[], int N);
void noKB(int no[], int notu[], int N);
double sapma(int notu[], int N);
void yatayHist(int notu[], int N);
void dikeyHist(int notu[], int N);

void main()
{
	struct ogrenci
	{
		int OgrNo[BUFSIZ], BNotu[BUFSIZ];
	}ogr;

	int N;
	float ort;
	printf("Ogrenci sayisini giriniz: ");
	scanf("%d", &N);
	giris(ogr.OgrNo, ogr.BNotu, N);
	printf("\n");
	printf("\nB A S L A N G I C T A \n");
	printf("---------------------\n");
	goruntule(ogr.OgrNo, ogr.BNotu, N);
	ort = ortalama(ogr.BNotu, N);
	printf("Not ortalamasi: %5.2f\n\n", ort);

	otele(ogr.BNotu, N);
	printf("\nO T E L E M E D E N   S O N R A \n");
	printf("-------------------------------\n");
	goruntule(ogr.OgrNo, ogr.BNotu, N);
	ort = ortalama(ogr.BNotu, N);
	printf("Not ortalamasi: %5.2f\n", ort);

	printf("\n\nN O T A   G O R E   S I R A L A M A \n");
	printf("------------------------------------\n");
	notKB(ogr.OgrNo, ogr.BNotu, N);

	printf("\n\nN U M A R A Y A   G O R E   S I R A L A M A \n");
	printf("--------------------------------------------\n");
	noKB(ogr.OgrNo, ogr.BNotu, N);

	printf("\n\nStandart Sapma : %f\n", sapma(ogr.BNotu, N));

	printf("\n\n  Y A T A Y   H I S T O G R A M\n");
	yatayHist(ogr.BNotu, N);

	printf("\n\n  D I K E Y   H I S T O G R A M");
	dikeyHist(ogr.BNotu, N);

	printf("\n\n");
	_getch();
}
void giris(int no[], int notu[], int N)
{
	int i;
	for (i = 0; i<N; i++)
	{
		printf("Ogrenci no gir: ");
		scanf("%d", &no[i]);
		printf("%d numarali ogrencinin basari notunu gir : ", no[i]);
		scanf("%d", &notu[i]);
	}
}
void goruntule(int no[], int notu[], int N)
{
	int i;
	printf("Ogrenci#\tNotu\n");
	for (i = 0; i<N; i++)
		printf("%8d\t%3d\n", no[i], notu[i]);
}
float ortalama(int notu[], int N)
{
	float t;
	int i;
	t = 0;
	for (i = 0; i<N; i++)
		t = t + notu[i];
	float ort = t / N;
	return ort;
}
void otele(int notu[], int N)
{
	int i, sayac = 0;
	float oteOrt, oteleme;
	int toplam = 0;

	for (i = 0; i < N; i++)
	{
		if (notu[i] >= 20)
		{
			toplam += notu[i];
			sayac++;
		}
	}
	if (sayac == 0)
		sayac = 1;
	oteOrt = toplam / sayac;

	if (oteOrt < 50)
		oteleme = 50 - oteOrt;
	else
		oteleme = 0;

	for (i = 0; i < N; i++)
	{
		if (notu[i] >= 30)
			notu[i] += oteleme;
	}
}
void notKB(int no[], int notu[], int N)
{
	int i, j, geciciNot, geciciNo;
	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			if (notu[i] <= notu[j])
			{
				geciciNot = notu[i];
				notu[i] = notu[j];
				notu[j] = geciciNot;

				geciciNo = no[i];
				no[i] = no[j];
				no[j] = geciciNo;
			}
		}
	}
	printf("Ogrenci#\tNotu\n");
	for (i = 0; i<N; i++)
		printf("%8d\t%3d\n", no[i], notu[i]);
}
void noKB(int no[], int notu[], int N)
{
	int i, j, geciciNot, geciciNo;

	for (i = 0; i<N; i++)
	{
		for (j = 0; j<N; j++)
		{
			if (no[i] <= no[j])
			{
				geciciNot = notu[i];
				notu[i] = notu[j];
				notu[j] = geciciNot;

				geciciNo = no[i];
				no[i] = no[j];
				no[j] = geciciNo;
			}
		}
	}
	printf("Ogrenci#\tNotu\n");
	for (i = 0; i<N; i++)
		printf("%8d\t%3d\n", no[i], notu[i]);
}
double sapma(int notu[], int N)
{
	int i;
	float toplam = 0.0;

	for (i = 0; i < N; i++)
	{
		toplam += notu[i];
	}
	float ortalama = toplam / N;

	double pay = 0.0, sapma;
	for (i = 0; i < N; i++)
	{
		pay += pow((ortalama - notu[i]), 2);
	}

	sapma = sqrt(pay / N);
	return sapma;
}
void yatayHist(int notu[], int N)
{
	int i,j,s;
	int harfNotu[10] = { 0,0,0,0,0,0,0,0,0,0 };
	char harf[10][2] = { { 'A','1' },{ 'A','2' },{ 'B','1' },{ 'B','2' } ,{ 'C','1' },{ 'C','2' },{ 'D','1' },{ 'D','2' },{ ' ','E' },{ ' ','F' } };
	for (i = 0; i < N; i++)
	{
		if (notu[i] >= 90)
			harfNotu[0]++;
		else if (notu[i] >= 80)
			harfNotu[1]++;
		else if (notu[i] >= 75)
			harfNotu[2]++;
		else if (notu[i] >= 70)
			harfNotu[3]++;
		else if (notu[i] >= 65)
			harfNotu[4]++;
		else if (notu[i] >= 60)
			harfNotu[5]++;
		else if (notu[i] >= 55)
			harfNotu[6]++;
		else if (notu[i] >= 50)
			harfNotu[7]++;
		else if (notu[i] >= 40)
			harfNotu[8]++;
		else if (notu[i] >= 0)
			harfNotu[9]++;
	}

	int max = -1;
	for (i = 0; i<10; i++)
	{
		if (harfNotu[i]>max)
			max = harfNotu[i];
	}

	for (i = 0; i<10; i++)
	{
		printf(" ");
		for (j = 0; j < 2; j++)
		{
			printf("%c", harf[i][j]);
		}printf(" | ");

		for (s = 0; s<max; s++)
		{
			if (s >= harfNotu[i])
				printf("  ");
			else
				printf("* ");
		}
		printf("\n");
	}
	printf("----+-");
	for (i = 0; i < max; i++)
	{
		printf("--");
	}
	printf("\n      ");
	for (i = 0; i<max; i++)
		printf("%d ", i + 1);
}
void dikeyHist(int notu[], int N)
{
	int i,j,s;
	int harfNotu[10] = { 0,0,0,0,0,0,0,0,0,0 };
	char harf[10][2] = { { 'A','1' },{ 'A','2' },{ 'B','1' },{ 'B','2' } ,{ 'C','1' },{ 'C','2' },{ 'D','1' },{ 'D','2' },{ ' ','E' },{ ' ','F' } };
	for (i = 0; i < N; i++)
	{
		if (notu[i] >= 90)
			harfNotu[0]++;
		else if (notu[i] >= 80)
			harfNotu[1]++;
		else if (notu[i] >= 75)
			harfNotu[2]++;
		else if (notu[i] >= 70)
			harfNotu[3]++;
		else if (notu[i] >= 65)
			harfNotu[4]++;
		else if (notu[i] >= 60)
			harfNotu[5]++;
		else if (notu[i] >= 55)
			harfNotu[6]++;
		else if (notu[i] >= 50)
			harfNotu[7]++;
		else if (notu[i] >= 40)
			harfNotu[8]++;
		else if (notu[i] >= 0)
			harfNotu[9]++;
	}
	int max = -1;
	for (i = 0; i<10; i++)
	{
		if (harfNotu[i]>max)
			max = harfNotu[i];
	}

	for (i = max; i>0; i--)
	{
		printf("\n%3d | ", i);
		for (s = 0; s<10; s++)
		{
			if (i <= harfNotu[s])
				printf("** ");
			else
				printf("   ");
		}printf("|");
	}
	printf("\n----+-------------------------------+\n     ");

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%c", harf[i][j]);
		}
		printf(" ");
	}
}
