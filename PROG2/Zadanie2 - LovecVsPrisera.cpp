
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <math.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#pragma warning(disable:4996)
#define CLEAR_SCREEN() system("cls")
#define HUNTER_STEP 4 //velkost kroku lovca
#define MONSTER_STEP 2 //velkost kroku monstra
#define MAP_W 50 //sirka mapy
#define MAP_H 30 //vyska mapy
#define CATCH 3 //minimalna vzdialenost ktoru potrebuje lovec na chytenie monstra
#define M_PI 3.14159265358979323846


void arena(float HunX, float HunY, float MonX, float MonY);
float vzdialenost(float HunX, float HunY, float MonX, float MonY);
int uhol(int HunU, char smer);
float novaX(float HunX, int HunU);
float novaY(float HunY, int HunU);
float monY(float MonY, float MonU);
float monX(float MonX, float MonU);



int main()
{
	float HunX, HunY, MonX, MonY; //suradnice X,Y pre oboch
	int HunU, MonU; // uhly pre oboch
	char smer;
	srand(time(NULL));
	HunX = rand() % MAP_H * 1.0;	//Generovanie nahodnych suradnic
	HunY = rand() % MAP_W * 1.0;
	MonX = rand() % MAP_H* 1.0;
	MonY = rand() % MAP_W * 1.0;
	HunU = rand() % 360;
	MonU = rand() % 360;
	arena(HunX, HunY, MonX, MonY);
	while ((vzdialenost(HunX, HunY, MonX, MonY)) >= (CATCH))
	{	
		printf("Dolava = l, Rovno = r, Doprava = p\n");
		scanf("%c", &smer);
		HunU = uhol(HunU, smer);
		HunX = novaX(HunX, HunU); //ziskavanie novych suradnic
		HunY = novaY(HunY, HunU);
		MonX = monX(MonX, MonU);
		MonY = monY(MonY, MonU);
		MonU = rand() % 360;
		arena(HunX, HunY, MonX, MonY);
		printf("HUNX = %.2f HUNY = %.2f\nMONX = %.2f MONY = %.2f \nVzdialenost = %.2f\n", HunX, HunY, MonX, MonY,vzdialenost(HunX, HunY, MonX, MonY)); //pokial chces vypisat suradnice a aktualne polohy
	}
	printf("MONSTRUM JE MRTVE");
}

void arena(float HunX, float HunY, float MonX, float MonY) //funkcia na vykreslovanie areny
{
	CLEAR_SCREEN();
	int plocha[MAP_W][MAP_H];
	int i, j;
		for (i=0;i <= MAP_H;i++)
		{
			for (j = 0; j <= MAP_W; j++)
			{
				if ((i == (int)round(HunX)) && (j == (int)round(HunY)))  printf ("H");
				if ((i == (int)round(MonX)) && (j == (int)round(MonY)))  printf("M");
				else printf(" ");
			}
			printf("\n");
		}
}
float vzdialenost(float HunX, float HunY, float MonX, float MonY) //funkcia na vypocet vzdialenosti dvoch bodov v XxY poli
{
	float vzd;
	vzd = sqrt(pow(MonX - HunX, 2) + pow(MonY - HunY, 2));
	return vzd;
}
int uhol(int HunU, char smer) //len vypocet noveho uhla
{
	if ((smer == 'l') or (smer == 'L')) HunU = HunU + 30;
	if ((smer == 'r') or (smer == 'R')) HunU = HunU + 0;
	if ((smer == 'p') or (smer == 'P')) HunU = HunU - 30;

	HunU = HunU % 360;
	return HunU;
}
float novaX(float HunX,int HunU) // vypocet novej Xovej suradnice, moze prechadzat cez steny
{
	double ret,rad;
	rad = HunU * M_PI / 180.0;
	ret = cos(rad);
	HunX = HunX + HUNTER_STEP * ret;
	HunX = abs(fmod(HunX, MAP_H)); //ak by nahodou nabudol hodnotu vacsiu ako Map_h    fmod() je % pre float
	return HunX;
}
float novaY(float HunY, int HunU) // vypocet novej Ypsilonovej suradnice
{
	double ret, rad;
	rad = HunU * M_PI / 180.0;
	ret = sin(rad);
	HunY = HunY + HUNTER_STEP * ret;
	HunY = abs(fmod(HunY, MAP_W));
	return HunY;
}
float monX(float MonX, float MonU)
{
	double ret, rad;
	rad = MonU * M_PI / 180.0;
	ret = cos(rad);
	MonX = MonX + MONSTER_STEP * ret;
	MonX = abs(fmod(MonX, MAP_H));
	return MonX;
}
float monY(float MonY, float MonU)
{
	double ret, rad;
	rad = MonU * M_PI / 180.0;
	ret = sin(rad);
	MonY = MonY + MONSTER_STEP * ret;
	MonY = abs(fmod(MonY, MAP_W));
	return MonY;
}