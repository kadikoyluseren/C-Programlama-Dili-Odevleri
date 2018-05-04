// AD SOYAD : SEREN KADIKÖYLÜ
//ÖÐRENCÝ NUMARASI : 16253037
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
void main()
{
	srand(time(NULL));
	int jeton, i, j, k, randSagSol, hazne;
	int maxJeton = 0;
	int haznedekiJetonSayisi[10] = { 0,0,0,0,0,0,0,0,0,0 };
	printf("Jeton sayisi: ");
	scanf("%d", &jeton);

	for (i = 1; i <= jeton; i++)
	{
		printf("%3d. jetonu atmak icin herhangi bir tusa basiniz -> ", i);
		_getch();
		int konum = 10;

		for (k = 0; k < 9; k++)
		{
			randSagSol = rand() % 2;
			if (randSagSol == 0)
				konum--;
			else
				konum++;
		}
		hazne = (konum + 1) / 2;
		printf("%2d. hazneye dustu..", hazne);

		for (j = 0; j<10; j++)
		{
			if (hazne == j + 1)
				haznedekiJetonSayisi[j]++;
		}printf("\n");
	}printf("\n");

	for (i = 0; i < 10; i++)
	{
		printf("%2d. haznedeki jeton sayisi: %d\n", i + 1, haznedekiJetonSayisi[i]);
	}

	for (i = 0; i<10; i++)
	{
		if (haznedekiJetonSayisi[i]>maxJeton)
			maxJeton = haznedekiJetonSayisi[i];
	}

	printf("\nJetonlarin histogram seklinde dagilimlari:\n");
	for (i = maxJeton; i>0; i--)
	{
		printf("\n%2d", i);
		for (j = 0; j<10; j++)
		{
			if (haznedekiJetonSayisi[j] >= i)
				printf("| o ");
			else
				printf("|   ");
		}printf("|");
	}
	printf("\n--+---+---+---+---+---+---+---+---+---+---+\n  | 1   2   3   4   5   6   7   8   9   10|\n\n");
}