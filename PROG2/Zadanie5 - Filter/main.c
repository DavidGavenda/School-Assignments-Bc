#include <stdio.h>
#include "median_filter.h"

// DOLEZITE: program spustite z prikazoveho riadku z adresara, kde mate ulozeny textovy subor
// so vstupnym signalom (napr. signal.txt).
// Na nacitanie vstupneho signalu zo suboru pouzijeme znak presmerovania standardneho vstupu ('<').
// Na zapis vysledneho signalu do suboru pouzijeme znak presmerovania standardneho vystupu ('>').

// PRIKLAD spustenia vasho programu (program.exe) z prikazoveho riadku.
// Program nacita vstupny signal z 'signal.txt' a vysledny prefiltrovany signal zapise do 'output.txt'.

// program.exe < signal.txt > output.txt

int main()
{
    int k=0,i=0; // pocet nacitanych prvkov vstupneho signalu (vrati funkcia 'loadData')
	int w; //docasne
    double input[MAX_DATA_SIZE]; // vstupny signal
    double output[MAX_DATA_SIZE]; // vystupny prefiltrovany signal

	k=loadData(input,k);
	filterData(input, output, k, 5);
	printData(output, k);
    return 0;
}
