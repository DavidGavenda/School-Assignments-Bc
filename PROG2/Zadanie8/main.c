#include <stdio.h>
#include "databaza.h"
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)


int main(int argc, char* argv[])
{
	int k;
	struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV];
	struct Zamestnanec kopia[MAX_ZAMESTNANCOV];
	srand(time(NULL));
	zamestnanci(&zamestnanec); //vytvori originalnu
	vypis(&zamestnanec,MAX_ZAMESTNANCOV); //vypise originalnu
	while (1)
	{
		kopirka(&zamestnanec, &kopia);
		k = nacitanie(&kopia); //ZORADZUJEM PODLA PRVEHO
		vypis(kopia, k);
		getch();
	}
	return 0;
}