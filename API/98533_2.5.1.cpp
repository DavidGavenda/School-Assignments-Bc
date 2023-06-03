// 2.5.1.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//



#include "pch.h"
#include <iostream>
#include <windows.h> 

int main()
{
	int i;
	for (i = 1;i <= 50;i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((i-1)/10)+1);
		printf("%3d ",i);
		if (i % 10 == 0) printf("\n");
		Sleep(1000);

	}
}

