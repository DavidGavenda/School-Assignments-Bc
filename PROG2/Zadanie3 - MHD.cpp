#include <stdio.h>
#include "pch.h"
#include <iostream>
#pragma warning(disable:4996)
#define CLEAR_SCREEN() system("cls")
// hlavickovy subor so specifikaciou CP
#include "cp_data2.h"

int generovanie(int cislo_spoja, int cas);
void vypis(int cislo_spoja);
int menu();
int spoj();
int najblizsi(int cislo_spoja,int minuta);

// funkcia na vypis specifikacie CP
void cp_data() {
	char left_space[10] = "\t";
	int width = 17;
	printf("\n... [SPECIFIKACIA CESTOVNEHO PORIADKU] ...\n\n");

	// casovy rozdiel medzi 2 po sebe iducimi zastavkami
	printf("%s%-*s %d min\n", left_space, width, "DELTA:", DELTA);
	// hodina odchodu prveho spoja z 1. zastavky
	printf("\n");
	printf("%s%-*s %02d\n", left_space, width, "PRVY_SPOJ_H:", PRVY_SPOJ_H);
	// minuta odchodu prveho spoja z 1. zastavky
	printf("%s%-*s %02d\n", left_space, width, "PRVY_SPOJ_M:", PRVY_SPOJ_M);
	// posledna hodina, kedy linka premava
	printf("%s%-*s %02d\n", left_space, width, "POSLED_SPOJ_H:", POSLED_SPOJ_H);
	printf("\n");
	// hodina zaciatku rannej spicky
	printf("%s%-*s %02d\n", left_space, width, "RANO_START:", RANO_START);
	// hodina konca rannej spicky
	printf("%s%-*s %02d\n", left_space, width, "RANO_END:", RANO_END);
	printf("\n");
	// hodina zaciatku poobednej spicky
	printf("%s%-*s %02d\n", left_space, width, "POOBEDE_START:", POOBEDE_START);
	// hodina konca poobednej spicky
	printf("%s%-*s %02d\n", left_space, width, "POOBEDE_END:", POOBEDE_END);
	printf("\n");
	// frekvencia premavania linky (v minutach) mimo spicky
	printf("%s%-*s %d min\n", left_space, width, "INTERVAL_NORMAL:", INTERVAL_NORMAL);
	// frekvencia premavania linky (v minutach) v rannej spicke
	printf("%s%-*s %d min\n", left_space, width, "INTERVAL_RANO:", INTERVAL_RANO);
	// frekvencia premavania linky (v minutach) v poobednej spicke
	printf("%s%-*s %d min\n", left_space, width, "INTERVAL_POOBEDE:", INTERVAL_POOBEDE);
	printf("\n..........................................\n");
}


int main() //NEMAM TAM TO VIZ SPOJ 3 napriklad. V 10 je posun o 8 a potom o 15. MNE TO NEROBI,ide rovno o 15
{
	//cp_data();
	int cislo_spoja,volba,minuta,cas;
	cas = 0;
	while (1==1)
	{ 
		CLEAR_SCREEN();
		volba=menu();
		switch (volba)
		{
		case 1:
			CLEAR_SCREEN();
			printf("ZADAJ CISLO SPOJA : ");
			scanf("%d", &cislo_spoja);
			vypis(cislo_spoja);
			getchar();
			getchar(); //ked bol len raz nesiel
			break;
		case 2:
			CLEAR_SCREEN();
			minuta = spoj();
			printf("ZADAJ CISLO SPOJA : ");
			scanf("%d", &cislo_spoja);
			while (1 == 1)
			{
				cas=najblizsi(cislo_spoja, minuta);
				if (cas == minuta) { break; } // pokial mi nieco najde, ukonci. Nevypisuje dalsie
				minuta = (minuta + 1)%1440; //ak na novy den
			}
			getchar();
			getchar(); //ked bol len raz nesiel
			break;
		case 3:
			return 0;

		}
	}

	return 0;
}


int generovanie(int cislo_spoja,int cas)
{
	if (cas == 0)
	{
		cas = 60 * PRVY_SPOJ_H + PRVY_SPOJ_M + ((cislo_spoja-1)*DELTA); //pokial sa jedna o prvy autobus ten den,tak mu automaticky nastavim kolko je hodin
	}

	int hodina;
	hodina = cas / 60;
	if ((hodina < RANO_START) || ((hodina > RANO_END) && (hodina < POOBEDE_START)) || (hodina > POOBEDE_END))
	{
		cas = cas + INTERVAL_NORMAL; //toto je rozdelenie na intervaly, v tomto pripade na ten kde pridavam len normalnu hodnotu
	}

	if ((hodina >= RANO_START) && (hodina <= RANO_END))
	{
		cas = cas + INTERVAL_RANO; //toto je pre ranny interval
	}

	if ((hodina >= POOBEDE_START) && (hodina <= POOBEDE_END))
	{
		cas = cas + INTERVAL_POOBEDE; // poobedny interval
	}

	return cas;
}

void vypis(int cislo_spoja)
{
	int cas, stara_hodina, nova_hodina;
	cas = 0;
	nova_hodina = 0;
	stara_hodina = PRVY_SPOJ_H;
	printf("HODINA | MINUTA\n");
	printf("................................");
	while (nova_hodina <= POSLED_SPOJ_H)
	{
		if (nova_hodina > stara_hodina) // vypisuje mi nove hodiny
		{
			printf("%6d | ", nova_hodina);
			if (stara_hodina == 0) //vypis uplne prveho spoja
			{
				printf("%02d ", (cas - INTERVAL_NORMAL)%60); 
			}
			//printf("DANE INFORMACIE %d %d %d|||", cas, nova_hodina, stara_hodina);
		}
		if (cas != 0)
		{
			printf("%02d ", cas % 60);
		}
		stara_hodina = cas / 60;
		cas = generovanie(cislo_spoja, cas);
		nova_hodina = cas / 60;
		if (nova_hodina > stara_hodina) // ak sa hodina posunie tak skoci na novy riadok
		{
			printf("\n");
		}
	}

}

int menu()
{
	int volba;
	printf("ZDRAVIM, VITA TA DOPRAVNA SPOLOCNOST DAVID = DPD\n");
	printf("VYBER SI JEDNU Z MOZNOSTI \n");
	printf("1. VYBERIES SI ZASTAVKU,KTOREJ CHCES VYPIS CESTOVNEHO PLANU\n");
	printf("2. POTREBUJES ZISTIT NAJBLIZSI SPOJ ? ZVOL TUTO MOZNOST\n");
	printf("3. MOJA POMOC TI STACILA? TU MOZES UKONCIT PROGRAM\n");
	scanf("%d", &volba);
	return volba;
}

int spoj()
{
	int hodina, minuta;
	printf("ZADAJ KOLKO JE HODIN:");
	scanf("%d", &hodina);
	printf("ZADAJ KOLKO JE MINUT:");
	scanf("%d", &minuta);
	minuta = minuta + (hodina * 60);
	return minuta;
}

int najblizsi(int cislo_spoja, int minuta)
{
	int cas, stara_hodina, nova_hodina;
	cas = 0;
	nova_hodina = 0;
	stara_hodina = PRVY_SPOJ_H;
	while (nova_hodina <= POSLED_SPOJ_H)
	{
		stara_hodina = cas / 60;
		cas = generovanie(cislo_spoja, cas);
		nova_hodina = cas / 60;
		if (minuta == cas)
		{
			printf("%d : %02d", cas / 60, cas % 60);
			break;
		}
	}
	return cas;

}
