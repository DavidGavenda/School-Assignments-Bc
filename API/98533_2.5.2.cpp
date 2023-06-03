// 2.5.2.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#include <windows.h>

void gotoxy(int x, int y);

int main()
{
	char meno[] = "David Gavenda";
	int vyska = 196;
	int hmotnost = 105;
	char cislo[] = "0918 / 449 716";
	int x = 10,y = 10;
	int i,najdlhsi=0;
	najdlhsi = sizeof(cislo);
	if (sizeof(meno) > najdlhsi) najdlhsi = sizeof(meno);


	gotoxy(x, y);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	printf("%c", 218);
	for(i=0;i<8;i++) printf("%c", 196);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("Zaznam 001");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	for (i = 0;i < najdlhsi-8;i++) printf("%c", 196);
	printf("%c", 191); //prvy riadok
	
	gotoxy(x, y+1);
	printf("%c", 195);
	for (i = 0;i < 9;i++) printf("%c", 196);
	printf("%c", 194);
	for (i = 0;i < najdlhsi;i++) printf("%c", 196); // (19-7-1)
	printf("%c", 180); // druhy riadok

	gotoxy(x, y+2);
	printf("%c", 179);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("Meno     ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("%c", 179);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	for (i = 0;i < najdlhsi - sizeof(meno) +1;i++) printf(" ");
	printf("%s", meno);
	//for (i = 0;i < 1;i++) printf(" ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("%c", 179); //treti riadok

	gotoxy(x, y+3);
	printf("%c", 195);
	for (i = 0;i < 9;i++) printf("%c", 196);
	printf("%c", 197);
	for (i = 0;i < najdlhsi;i++) printf("%c", 196); // (19-7-1)
	printf("%c", 180); // stvrty riadok

	gotoxy(x, y+4);
	printf("%c", 179);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("Vyska    ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("%c", 179);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("%*d cm ",najdlhsi-4, vyska);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("%c", 179); //piaty riadok

	gotoxy(x, y+5);
	printf("%c", 195);
	for (i = 0;i < 9;i++) printf("%c", 196);
	printf("%c", 197);
	for (i = 0;i < najdlhsi;i++) printf("%c", 196); // (19-7-1)
	printf("%c", 180); // siesty riadok

	gotoxy(x, y+6);
	printf("%c", 179);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("Hmotnost ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("%c", 179);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("%*d kg ", najdlhsi-4, hmotnost);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("%c", 179); //siedmy riadok

	gotoxy(x, y+7);
	printf("%c", 195);
	for (i = 0;i < 9;i++) printf("%c", 196);
	printf("%c", 197);
	for (i = 0;i < najdlhsi;i++) printf("%c", 196); 
	printf("%c", 180); // osmy riadok

	gotoxy(x, y+8);
	printf("%c", 179);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("Tel.     ");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("%c", 179);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	for (i = 0;i < (najdlhsi - sizeof(cislo));i++) printf(" ");
	printf("%s ", cislo);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("%c", 179); //deviaty riadok

	gotoxy(x, y+9);
	printf("%c", 192);
	for (i = 0;i < 9;i++) printf("%c", 196);
	printf("%c", 193);
	for (i = 0;i < najdlhsi;i++) printf("%c", 196); // (19-7-1)
	printf("%c\n", 217); // konecnik

}



void gotoxy(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}