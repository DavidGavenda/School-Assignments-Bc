

#include "pch.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<stdio.h>

#pragma warning(disable:4996)

char vypis();

int main()
{
	char nahodne,Fko,pokus=0;
	float start, end;


	while (1)
	{
		system("cls");
		Fko = getch(); //Funkcia na nacitanie Fka f1=59 , f10=68
		if (Fko == 0)
			Fko = getch();
		//Fko = (int)Fko;
		switch (Fko)
		{
		case 59: //F1
			printf("Nahodim ti nahodne pismeno, F2 zacne merat cas, bude to pokracovat pokial ho nezadas, F10 to ukonci");
			break;
		case 60:	 //F2	
			nahodne = vypis();
			printf("\n");
			start = clock();
			while (nahodne != pokus)
			{
				pokus = getch();
			}
			end = clock();
			printf("Tvoj cas bol %.2f s", ((end - start)/1000));
			break;
		case 68: //F10
			return 0;
		}
		getch();
	}
	return 0;
}

char vypis()
{
	int i;
	srand(time(NULL));
	char nahodne = 'A' + (rand() % 26);
	for (i = 0;i < 30;i++)
	{
		printf("\n");
	}
	printf(" %105c", nahodne);
	return nahodne;
}


