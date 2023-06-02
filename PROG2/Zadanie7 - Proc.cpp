// Proc.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

char *vymena(const char *s, const char *oldW, const char *newW);

int main(int argc, char* argv[])
{
	char riadok[1000];
	char *vysledok = NULL; 
	int i,j;
	char lomka[2] = "/";
	char *novy;
	char *stary;

	char * cenzura1; 	char censore1[2] = "*";
	char * cenzura2;	char censore2[3] = "**";
	char * cenzura3;	char censore3[4] = "***";
	char * cenzura4;	char censore4[5] = "****";
	char * cenzura5;	char censore5[6] = "*****";
	char * cenzura6;	char censore6[7] = "******";
	char * cenzura7;	char censore7[8] = "*******";
	char * cenzura8;	char censore8[9] = "********";
	char * cenzura9; 	char censore9[10] = "********";
	char * cenzura10over; 	char censore10over[11] = "*********";

	cenzura1 = censore1;
	cenzura2 = censore2;
	cenzura3 = censore3;
	cenzura3 = censore3;
	cenzura4 = censore4;
	cenzura5 = censore5;
	cenzura6 = censore6;
	cenzura7 = censore7;
	cenzura8 = censore8;
	cenzura9 = censore9;
	cenzura10over = censore10over;

	//fgets(riadok, 1000, stdin);
	while (fgets(riadok, 1000, stdin) != NULL)
	{
		vysledok = riadok;
		for (i = 1;i < argc;i++)
		{
			stary = strtok(argv[i], lomka); //vytvoril som si dve slova
			novy = strtok(NULL, lomka);
			if (novy != NULL) vysledok = vymena(vysledok, stary, novy); //nahradzam, mam tam vysledok keby som pouzil viac vymen
			else if (strlen(stary) == 1) vysledok = vymena(vysledok, stary, cenzura1);
			else if (strlen(stary) == 2) vysledok = vymena(vysledok, stary, cenzura2);
			else if (strlen(stary) == 3) vysledok = vymena(vysledok, stary, cenzura3);
			else if (strlen(stary) == 4) vysledok = vymena(vysledok, stary, cenzura4);
			else if (strlen(stary) == 5) vysledok = vymena(vysledok, stary, cenzura5);
			else if (strlen(stary) == 6) vysledok = vymena(vysledok, stary, cenzura6);
			else if (strlen(stary) == 7) vysledok = vymena(vysledok, stary, cenzura7);
			else if (strlen(stary) == 8) vysledok = vymena(vysledok, stary, cenzura8);
			else if (strlen(stary) == 9) vysledok = vymena(vysledok, stary, cenzura9);
			else if (strlen(stary) > 9) vysledok = vymena(vysledok, stary, cenzura10over); //na toto nie som pysny ale fakt nic ine sa mi uz nechce robit
		}
		printf("%s", vysledok);
		
	}
	return 0;
}



char *vymena(const char *riadok, const char *stare,const char *nove)
{
	char *vysledok;
	int i = 0, j = 0, k = 0;; //j=pocet
	int noveD = strlen(nove);
	int stareD = strlen(stare);

	for (i = 0; riadok[i] != '\0'; i++)  //ratam kolko krat sa nachadza slovo s stringu
	{
		if (strstr(&riadok[i], stare) == &riadok[i])
		{
			j++;
			i = i +  stareD - 1; //skacem o index po starom slove
		}
	}

	vysledok = (char *)malloc(i + j * (noveD - stareD) + 1); //vytvaram novy string, ktory je dost velky
	i = 0;
	while (*riadok)
	{
		if (strstr(riadok, stare) == riadok) // hladam stare v riadku
		{
			strcpy(&vysledok[k], nove); //vymena
			k = k + noveD;
			riadok = riadok + stareD;
		}
		else
			vysledok[k++] = *riadok++;
	}
	vysledok[k] = '\0';
	return vysledok;
}

