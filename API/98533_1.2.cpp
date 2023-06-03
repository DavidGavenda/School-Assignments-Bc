// ConsoleApplication3.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

int main()
{
	int cislo,a,b,c;
	while (1 == 1)
	{
		printf("Zadaj cislo, ktore chces previest (od 1-100):\n");
		scanf("%d", &cislo);

		if (cislo == 100)
		{
			printf("C");
			cislo = 0;
		}
		b = cislo / 10; 
		if ((b >= 5)&&(b!=9))
		{
			printf("L");
			cislo = cislo - 50;
			b = b - 5;
		}
		if (b == 4)
		{
			printf("XL");
			cislo = cislo - 40;
			b = b - 4;
		}
		if (b == 9)
		{
			printf("XC");
			cislo = cislo - 90;
			b = b - 9;
		}
		cislo = cislo - b * 10;
		for (b;b > 0;b--)
		{
			printf("X");
		}

		if (cislo == 9)
		{
			printf("IX");
			cislo = cislo - 9;
		}
		if (cislo == 4)
		{
			printf("IV");
			cislo = cislo - 4;
		}
		if ((cislo >= 5)&&(cislo!=9))
		{
			printf("V");
			cislo = cislo - 5;
		}
		for (cislo;cislo > 0;cislo--)
		{
			printf("I");
		}	
		printf("\n");
	}
	return 0;

}
