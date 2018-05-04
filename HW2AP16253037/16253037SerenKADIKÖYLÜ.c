#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<ctype.h>

int i, temp, toplam=0, asal=0;
int pul[3];

void pulCek()
{
	pul[0] = rand() % 99 + 1;
	pul[1] = rand() % 99 + 1;

	while (pul[0] == pul[1])
		pul[1] = rand() % 99 + 1;

	pul[2] = rand() % 99 + 1;
	while (pul[0] == pul[2] || pul[1] == pul[2])
		pul[2] = rand() % 99 + 1;
}
int asalMi(int toplam)
{
	for (i = 2; i < toplam; i++)
	{
		if (toplam%i == 0)
		{
			asal++;
		}
	}
	return asal;
}
void sirala(int dizi[3])
{
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (dizi[i] > dizi[j]) {
				temp = dizi[i];
				dizi[i] = dizi[j];
				dizi[j] = temp;
			}
		}
	}
}
void pulGoruntule()
{
	for (int i = 0; i < 3; i++)
	{
		printf("%d. pul :%3d\n", i + 1, pul[i]);
	}
}
int pulTopla()
{
	for (int i = 0; i < 3; i++)
	{
		toplam += pul[i];
	}
	return toplam;
}

void main()
{
	srand(time(NULL));
	printf("	Oyuna baslamak icin herhangi bir tusa basiniz...");
	_getch();
	printf("\n\n");
	char evet = 'e';
	srand(time(NULL));

	while (evet == 'e' || evet == 'E')
	{
		toplam = 0;
		pulCek();
		pulGoruntule();
		sirala(pul);
		pulTopla();

		if (toplam < 150)
		{
			printf("--> Toplam: %d + %d + %d = %d\n", pul[0], pul[1], pul[2], toplam);
			printf(" _____________________________\n");
			printf("|  1.KURAL : %d < 150	      |\n", toplam);
			printf("|  Tebrikler, kazandiniz.     |\n");
			printf(" '''''''''''''''''''''''''''''\n");
		}
		else if (asalMi(toplam)==0)
		{
			printf("--> Toplam: %d + %d + %d = %d\n", pul[0], pul[1], pul[2], toplam);
			printf(" _____________________________\n");
			printf("|  2. KURAL : %d asal.       |\n", toplam);
			printf("|  Tebrikler, kazandiniz.     |\n");
			printf(" '''''''''''''''''''''''''''''\n");
		}
		else if (pul[2] - pul[0] > pul[1])
		{
			printf("--> Max-Min: %d - %d = %d\n", pul[2], pul[0], pul[2] - pul[0]);
			printf(" _____________________________\n");
			printf("|  3.KURAL : %d > %d          |\n", pul[2] - pul[0], pul[1]);
			printf("|  Tebrikler, kazandiniz.     |\n");
			printf(" '''''''''''''''''''''''''''''\n");
		}
		else
		{
			printf("--> Toplam: %d + %d + %d = %d\n", pul[0], pul[1], pul[2], toplam);
			printf("--> Max-Min: %d - %d = %d\n", pul[2], pul[0], pul[2] - pul[0]);
			printf("~~ 1.kural : %d < 150 (yanlis)\n", toplam);
			printf("~~ 2.kural : %d (asal degil)\n", toplam);
			printf("~~ 3.kural : %d > %d (yanlis)\n", pul[2] - pul[0], pul[1]);
			printf(" _____________________________\n");
			printf("|  Maalesef kaybettiniz...!   |\n");
			printf(" '''''''''''''''''''''''''''''\n");
		}

		printf("Devam e/E? ");
		evet = _getche();
		printf("\n\n");
	}
}