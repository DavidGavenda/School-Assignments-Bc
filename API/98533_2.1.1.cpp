// BLOK2.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//
#include "pch.h"
#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

static int iCislo, iVysledok,xCislo,prevod;         // Niektore verzie potrebuju globalne premenne

int main(int argc, char* argv[])
{
	iCislo = 27;
	iVysledok = 0;
	xCislo = 3;
	prevod = 10;
	printf("\nCislo: %d  Vysledok: %d", iCislo, iVysledok);
	__asm {                         
		MOV EAX, iCislo              
		ADD EAX, xCislo                   
		MOV iVysledok, EAX               
	}                                

	printf("\nCislo: %d  Vysledok: %d", iCislo, iVysledok);

	printf("\n\nStlac ENTER a skoncime...");
	scanf("?");
	return(0);
}
