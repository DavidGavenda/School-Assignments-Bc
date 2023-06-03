// BLOK2.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//
#include "pch.h"
#include <iostream>
#include <stdio.h>
#pragma warning(disable:4996)

static int cislo,prevod;         // Niektore verzie potrebuju globalne premenne

int main(int argc, char* argv[])
{
	cislo = 15;
	prevod = 0;

	__asm {
		MOV EAX,cislo
		MOV EBX,prevod
		ADD EBX,cislo
		ADD EBX,48 //priratam 48 lebo to je hodnota 0
		CMP EAX,10
		JB LP1
		ADD EBX,7 // priratam sedem pokial je vacsie ako 10 , sedem pretoze 7 volnych znakov medzi cislami a pismenami
		LP1:
		MOV prevod,EBX
	}
	printf("\nCISLO: %d", prevod);
	printf("\n\nStlac ENTER a skoncime...");
	scanf("?");
	return(0);
}
