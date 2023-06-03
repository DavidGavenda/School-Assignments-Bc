// 98533_1.1.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>

void prevod(int b);

int main()
{  
	int a, b;
	a = 33777;
	b = (int)'X';
	printf("Cisla v desiatkovej %d,%d\n", a, b);
	printf("Cisla v dvojkovej ");
	prevod(a);
	printf(" ");
	prevod(b);
	printf("\n");
	printf("Cisla v desiatkovej %X,%X\n", a, b); //len zmenim vypis 


}
void prevod(int b)
{
	int i,j,pole[100];
	i = 0;
	while (b != 0)
	{
		pole[i] = b % 2;
		i = i + 1;
		b = b / 2;	
	}
	for (j = i-1;j >= 0;j--) //to -1 je tam preto lebo mi hadzalo akesi divne cislo predtym no idea why
	{
		printf("%d", pole[j]); //vypisujem cisla, ktore mam v poli ale od zadu
	}
}