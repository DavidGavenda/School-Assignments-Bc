// 2.3.1.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>
#pragma warning(disable:4996)

int main()
{
	FILE *fr,*fw;
	fr = fopen("poviedka.html", "r");
	fw = fopen("preklad.html", "w");
	char a;
	int i = 0;
	if (fr == 0)
	{
		printf("subor neexistuje\n");
		return 0;
	}
	while ((a = getc(fr)) != EOF)// cita subor fr (vstup.txt) pokym nenarazi na EOF - koniec suboru
	{
		if (a == (char)165) a = (char)188;
		if (a == (char)169) a = (char)138;
		if (a == (char)171) a = (char)141;
		if (a == (char)174) a = (char)142;

		if (a == (char)181) a = (char)190;
		if (a == (char)185) a = (char)154;
		if (a == (char)187) a = (char)157;
		if (a == (char)190) a = (char)158;
		fputc(a, fw);
		//printf("%c", a);
	}

}

