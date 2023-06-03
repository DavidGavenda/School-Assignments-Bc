
#include "pch.h"
#include <iostream>
#include <stdio.h>      
#include <math.h>
#define M_PI 3.14159265358979323846
#pragma warning(disable:4996)

double faktorial(int a)  //faktorial pomocou rekurzie. To iste ako python
{
	if ((a == 0) || (a == 1))
	{
		return (1);
	}
	else
	{
		return (a*faktorial(a - 1));
	}
}

double sinus(double x)	// funkcia na vypocitanie sinusu podla vzorca
{
	int a;
	double hodnota = 0;
	for (a = 0;a < 7;a++) //sucet 8 krat, ked som sa vyssie cislo, hadzalo mi zaporne hodnoty pri vyssich cislach
	{
		double vrsoklavo= pow(-1, a); //funkcia math.h
		double vrsokpravo= pow(x, 2 * a + 1);
		long int spodok = faktorial(2 * a + 1);
		hodnota = hodnota + (vrsoklavo * vrsokpravo / spodok);
	}
	return hodnota;
}


int main()
{	
	double x,radian;
	int f=0;
	printf("Zadaj uhol v stupnoch: ");
	scanf("%lf", &x);
	printf("Hodnota sinusu pre hodnotu ' %0.2lf ' je priblizne ", x);
	x = fmod(x, 360);  //po 360 stupnoch sa stale opakuje, fmod lebo je to double
	if (x > 180)			//metoda pokus omyl 
	{
		x = 180 - x;
	}
	if (x < -180)
	{
		x = x + 180;
		f = 1;					//jediny dovod preco to tu je lebo mi tam hadzalo minus napriklad -350 stupnov vo vysledku
	}
	
	radian = x * M_PI / 180; //prevod na radiany
	if (f==0) printf("%0.4lf\n",sinus(radian));
	if (f == 1) printf("%0.4lf\n", fabs(sinus(radian)));
	
   
}

