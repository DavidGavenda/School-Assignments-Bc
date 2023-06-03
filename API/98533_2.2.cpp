// 2.2.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
#include <iostream>

int main()
{ 
	char slovo[100] = "architektura_pocitacov_je_super_predmet_milujem_ho";
	printf("%s", slovo); //vypisem svoje "slovo"
	char *pointer;
	pointer = slovo;
	printf("\n%p", pointer); //vypisem pointer
	pointer = pointer + 1; //zvysim jeho hodnotu o 1
	*pointer = 1998; //dosadil som nejaku hodnotu
	printf("\n%s", slovo); // toto je upravene "slovo"
	pointer = pointer + 123; // idem na nejaku random hodnotu
	printf("\n%p", pointer); // nova nahodna pozicia pre pointer
	printf("\n%d", *pointer); // na adrese sa nachadza 
}

