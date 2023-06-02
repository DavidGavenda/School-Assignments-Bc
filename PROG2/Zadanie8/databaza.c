#include <stdio.h>
#include "databaza.h"
#include <time.h>
#include <stdlib.h>
#pragma warning(disable:4996)




void generovanie(struct Zamestnanec *zamestnanec) //generuje kazdeho zamestnanca
{
	const char *mena[20] = { "Peter","Jan","Simon","Jozef","David","Jakub","Adam","Michal","Tomas","Samuel","Filip","Lukas","Tobias","Denis","Juraj","Marko","Matias","Dominik","Maxim","Viktor" };
	const char *pozicie[4] = { "developer","tester","analytik","web dizajner"};
	zamestnanec->udaje.narodenie.den = rand() % 30 + 1;
	zamestnanec->udaje.narodenie.mesiac = rand() % 11 + 1;
	zamestnanec->udaje.narodenie.rok = rand() % 50 + 1950;
	zamestnanec->ID = rand() % 7999 + 1000;
	zamestnanec->plat = rand() % 5000 + 1000;
	
	strcpy(zamestnanec->udaje.meno, mena[rand()%19]);
	strcpy(zamestnanec->pozicia, pozicie[rand() % 4]);
}

void vypis(struct Zamestnanec *zamestnanec, int pocet) //sluzi na vypis
{
	int i, j;
	printf("Meno     | ID     | Pozicia         | Plat     | Datum narodenia\n");
	printf("................................................................\n");
	for (i = 0;i < pocet;i++) //znamena to ze hlada iba z prvych (pocet)
	{
		if ((zamestnanec[i].plat != 0) && (zamestnanec[i].pozicia[0]!='\0') && (zamestnanec[i].udaje.meno[0] != '\0') && (zamestnanec[i].udaje.narodenie.rok!=0))
		{
		printf("%s", zamestnanec[i].udaje.meno);
		for (j = 0;j < 9 - strlen(zamestnanec[i].udaje.meno);j++) printf(" ");
		printf("|");
		printf("% d   |", zamestnanec[i].ID);
		printf(" %s", zamestnanec[i].pozicia);
		for (j = 0;j < 16 - strlen(zamestnanec[i].pozicia);j++) printf(" ");
		printf("|");
		printf(" %d.00  |", zamestnanec[i].plat);
		printf(" %d/%d/%d", zamestnanec[i].udaje.narodenie.den, zamestnanec[i].udaje.narodenie.mesiac, zamestnanec[i].udaje.narodenie.rok);
		printf("\n");
		}
	}
}

void zamestnanci(struct Zamestnanec *zamestnanec) //prikaz na generovanie zamestnancov
{
	int i;
	for (i = 0;i < MAX_ZAMESTNANCOV;i++)
	{
		generovanie(&zamestnanec[i]);
	}
}

int nacitanie(struct Zamestnanec *zamestnanec)
{
	char prikaz1[200];
	char prikaz2[200];
	char prikaz3[200];
	char meno[50], plat[50], pozicia[50], datum[50];
	char smeno[50],splat[50],spozicia[50],sdatum[50];
	char *k, *all;
	int i, j = 0, platI,splatI;
	char *platCH;
	int decide = 0; // 1=mensi 2=rovne 3=vacsie
	int miesta[10], pozicia1[2], pozicia2[2], miesta1[10], miesta2[10];
	const char ciarka1[2] = "|";
	const char ciarka2[2] = "[";
	const char ciarka3[2] = "]";
	const char vacsi[2] = ">";
	const char mensi[2] = "<";
	const char rovna[2] = "=";
	int decide2 = 0;
	char den[5], mesiac[5], rok[10];
	int denI, mesiacI, rokI;
	int poziciaznaku;
	int o = 0,p = 0;

	
	
	
	////////SHOW
	do
	{
		printf("\nPrikaz vo formate 'show [k|%d]' : ", MAX_ZAMESTNANCOV);
		fgets(prikaz1, 200, stdin);
		all = strtok(prikaz1, ciarka1);
		all = strtok(NULL, ciarka3);
		k = strtok(prikaz1, ciarka2);
		k = strtok(NULL, ciarka3);
		if (k != NULL) k = abs(atoi(k)); //pocet kolko vypisujem , abs ak by hodil zapornu
	} while (k > MAX_ZAMESTNANCOV); //ak nenapise ani cislo,nevyhodi mu nic


	//////WHERE
	printf("Prikaz vo formate 'where [plat|pozicia|meno|datum]' : ");
	fgets(prikaz2, 200, stdin);

	for (i = 0;i < strlen(prikaz2);i++)
	{
		if (prikaz2[i] == '|') 
		{
			miesta[j] = i;
			j = j + 1;
		}
		else if (prikaz2[i] == '[')
		{
			pozicia1[0] = i;
			o = 1;
		}
		else if (prikaz2[i] == ']')
		{
			pozicia2[0] = i;
			p = 1;
		}
	}
	if ((j != 3) || (p==0) || (o==0))
	{
		printf("Nepoznam");
		return 0;
	}
	
	strncpy(plat,prikaz2  + pozicia1[0] + 1, miesta[0] - pozicia1[0] -1); // rozkuskovanie stringu
	plat[miesta[0] - pozicia1[0]-1] = '\0';

	strncpy(pozicia, prikaz2 + miesta[0] + 1, miesta[1] - miesta[0] - 1); // rozkuskovanie stringu
	pozicia[miesta[1] - miesta[0] - 1] = '\0';

	strncpy(meno, prikaz2 + miesta[1] + 1, miesta[2] - miesta[1] - 1); // rozkuskovanie stringu
	meno[miesta[2] - miesta[1] - 1] = '\0';

	strncpy(datum, prikaz2 + miesta[2] + 1, pozicia2[0] - miesta[2] - 1); // rozkuskovanie stringu
	datum[pozicia2[0] - miesta[2] - 1] = '\0';



	
	
	/////////////////PRACA S PLATOM
	
	
	
	for (i = 0;i < strlen(plat);i++)
	{
		if (plat[i] == '<')
		{
			memmove(&plat[i], &plat[i + 1], strlen(plat) - i); //odstrani zmanieko z plat
			decide = 1;
		}
		if (plat[i] == '=')
		{
			memmove(&plat[i], &plat[i + 1], strlen(plat) - i);
			decide = 2;
		}
		if (plat[i] == '>')
		{
			memmove(&plat[i], &plat[i + 1], strlen(plat) - i);
			decide = 3;
		}
	}
	platI = atoi(plat);
	
	if (platI!=0) cisticplat(zamestnanec, decide, platI);

	/////////////////// POZICIA 



	if (pozicia[0] != '\0') //pokial je pozicia prazdna neprebieha vyhadzovanie
	{
		for (i = 0;i < MAX_ZAMESTNANCOV;i++) //zbavim sa pozicii,ktore nechcem //////////////// ak naopak len zmenim != -> ==
		{
			if (strcmp(zamestnanec[i].pozicia, pozicia) != 0) zamestnanec[i].pozicia[0] = '\0';
		}
	}
	
	////////////////////////PRACA S MENOM

	if (meno[0] != '\0')
	{
		for (i = 0;i < MAX_ZAMESTNANCOV;i++) //zbavim sa pozicii,ktore nechcem //////////////// ak naopak len zmenim != -> ==
		{
			if (strcmp(zamestnanec[i].udaje.meno, meno) != 0) zamestnanec[i].udaje.meno[0] = '\0';
		}
	}
	j = 0;

	//////////////////////////////TOTO JE DATUM 

	if (datum[0] != '\0')
	{
		for (i = 0;i < strlen(datum);i++) //zistujem co chcem robit s datumom,aky mam prikaz
		{
			if (datum[i] == '<')
			{
				memmove(&datum[i], &datum[i + 1], strlen(datum) - i); //odstrani zmanieko z datumu
				decide2 = 1;
			}
			if (datum[i] == '=')
			{
				memmove(&datum[i], &datum[i + 1], strlen(datum) - i);
				decide2 = 2;
			}
			if (datum[i] == '>')
			{
				memmove(&datum[i], &datum[i + 1], strlen(datum) - i);
				decide2 = 3;
			}
		}

		for (i = 0;i < strlen(datum);i++) //hladam / v datume aby som si ho vedel rozdelit
		{
			if (datum[i] == '/')
			{
				miesta2[j] = i;
				j = j + 1;
			}
		}


		strncpy(den, datum, miesta2[0]); // rozkuskovanie stringu
		den[miesta2[0]] = '\0';
		strncpy(mesiac, datum + miesta2[0] + 1, miesta2[1] - miesta2[0]); // rozkuskovanie stringu
		mesiac[miesta2[1] - miesta2[0] - 1] = '\0';
		strncpy(rok, datum + miesta2[1] + 1, strlen(datum) - miesta2[1]); // rozkuskovanie stringu
		rok[strlen(datum) - miesta2[1] - 1] = '\0';



		denI = atoi(den);
		mesiacI = atoi(mesiac);
		rokI = atoi(rok);

		cisticdatum(zamestnanec, decide2, denI, mesiacI, rokI);	
	}

	//////////// SORT 
	o = 0;
	p = 0;
	printf("Prikaz vo formate 'sort [plat|pozicia|meno|datum]' : ");
	fgets(prikaz3, 200, stdin);
	/*	for (i = 0;i < strlen(prikaz3);i++)
		{
			if (prikaz3[i] == '[') pozicia1[1] = i;
			if (prikaz3[i] == ']') pozicia2[1] = i;
		}
		strncpy(sort, prikaz3 + pozicia1[1] + 1,pozicia2[1] -  pozicia1[1] - 1);
		sort[pozicia2[1] - pozicia1[1] - 1] = '\0';
		printf("%s", sort);
	*/
	j = 0;

	for (i = 0;i < strlen(prikaz3);i++)
	{
		if (prikaz3[i] == '|')
		{
			miesta[j] = i;
			j = j + 1;
		}
		else if (prikaz3[i] == '[')
		{
			pozicia1[1] = i;
			o = 1;
		}
		else if (prikaz3[i] == ']')
		{
			pozicia2[1] = i;
			p = 1;
		}
	}
	if ((j != 3) || (o==0) ||(p==0))
	{
		printf("Nepoznam");
		return 0;
	}

	strncpy(splat, prikaz3 + pozicia1[1] + 1, miesta[0] - pozicia1[1] - 1); // rozkuskovanie stringu
	splat[miesta[0] - pozicia1[1] - 1] = '\0';

	strncpy(spozicia, prikaz3 + miesta[0] + 1, miesta[1] - miesta[0] - 1); // rozkuskovanie stringu
	spozicia[miesta[1] - miesta[0] - 1] = '\0';

	strncpy(smeno, prikaz3 + miesta[1] + 1, miesta[2] - miesta[1] - 1); // rozkuskovanie stringu
	smeno[miesta[2] - miesta[1] - 1] = '\0';

	strncpy(sdatum, prikaz3 + miesta[2] + 1, pozicia2[1] - miesta[2] - 1); // rozkuskovanie stringu
	sdatum[pozicia2[1] - miesta[2] - 1] = '\0';
	
	if (strcmp(splat, vacsi) != 0)
	{
		bubleplatnaopak(zamestnanec);
		return k;
	}
	if (strcmp(splat, mensi) != 0)
	{
		bubleplat(zamestnanec);
		return k;
	}

	if (strcmp(spozicia, vacsi) != 0)
	{
		bublepozicia(zamestnanec);
		return k;
	}
	if (strcmp(spozicia, mensi) != 0)
	{
		bublepozicianaopak(zamestnanec);
		return k;
	}
	

	if (strcmp(smeno, vacsi) != 0)
	{
		bublemeno(zamestnanec);
		return k;
	}
	if (strcmp(smeno, mensi) != 0)
	{
		bublemenonaopak(zamestnanec);
		return k;
	}
	
	if (strcmp(sdatum, vacsi) != 0)
	{
		bublerok(zamestnanec);
		return k;
	}
	if (strcmp(sdatum, mensi) != 0)
	{
		bubleroknaopak(zamestnanec);
		return k;
	}
		
	return k;
}

void cisticplat(struct Zamestnanec *zamestnanec, int decide,int platI)
{
	int i = 0;
	if (decide == 1) //pokial bolo znamienko mensie odstranim ich
	{
		for (i = 0;i < MAX_ZAMESTNANCOV;i++)
		{
			if (zamestnanec[i].plat > platI) zamestnanec[i].plat = 0;
		}
	}

	if (decide == 2)
	{
		for (i = 0;i < MAX_ZAMESTNANCOV;i++)
		{
			if (zamestnanec[i].plat == platI) zamestnanec[i].plat = 0;
		}
	}

	if (decide == 3)
	{
		for (i = 0;i < MAX_ZAMESTNANCOV;i++)
		{
			if (zamestnanec[i].plat < platI) zamestnanec[i].plat = 0;
		}
	}
}

void cisticdatum(struct Zamestnanec *zamestnanec, int decide, int den, int mesiac, int rok)
{
	int i;
	if (decide == 2)
	{
		for (i = 0;i < MAX_ZAMESTNANCOV;i++)
		{
			if ((zamestnanec[i].udaje.narodenie.den != den) || (zamestnanec[i].udaje.narodenie.mesiac != mesiac) || (zamestnanec[i].udaje.narodenie.rok != rok)) zamestnanec[i].udaje.narodenie.rok = 0;
		}
	}

	if (decide == 1)
	{
		for (i = 0;i < MAX_ZAMESTNANCOV;i++)
		{
			if (zamestnanec[i].udaje.narodenie.rok>rok) zamestnanec[i].udaje.narodenie.rok = 0;
			if ((zamestnanec[i].udaje.narodenie.rok==rok) && (zamestnanec[i].udaje.narodenie.mesiac>mesiac)) zamestnanec[i].udaje.narodenie.rok = 0;
			if ((zamestnanec[i].udaje.narodenie.rok == rok) && (zamestnanec[i].udaje.narodenie.mesiac == mesiac) && (zamestnanec[i].udaje.narodenie.den > den)) zamestnanec[i].udaje.narodenie.rok = 0;;
		}
	}
	if (decide == 3)
	{
		for (i = 0;i < MAX_ZAMESTNANCOV;i++)
		{
			if (zamestnanec[i].udaje.narodenie.rok < rok) zamestnanec[i].udaje.narodenie.rok = 0;
			if ((zamestnanec[i].udaje.narodenie.rok == rok) && (zamestnanec[i].udaje.narodenie.mesiac < mesiac)) zamestnanec[i].udaje.narodenie.rok = 0;
			if ((zamestnanec[i].udaje.narodenie.rok == rok) && (zamestnanec[i].udaje.narodenie.mesiac == mesiac) && (zamestnanec[i].udaje.narodenie.den < den)) zamestnanec[i].udaje.narodenie.rok = 0;;
		}
	}
}

void bubleplat(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV])
{
	int i, j;
	struct Zamestnanec temp;
	for (i = 0;i < MAX_ZAMESTNANCOV - 1;i++)
	{
		for (j = 0;j < (MAX_ZAMESTNANCOV- i - 1);j++)
		{
			if (zamestnanec[j].plat < zamestnanec[j + 1].plat) //porovnavam hodnoty ale menim zaznamy
			{
				temp = zamestnanec[j];
				zamestnanec[j] = zamestnanec[j + 1];
				zamestnanec[j + 1] = temp;
			}
		}
	}
}

void bubleplatnaopak(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV])
{
	int i, j;
	struct Zamestnanec temp;
	for (i = 0;i < MAX_ZAMESTNANCOV - 1;i++)
	{
		for (j = 0;j < (MAX_ZAMESTNANCOV - i - 1);j++)
		{
			if (zamestnanec[j].plat > zamestnanec[j + 1].plat) //porovnavam hodnoty ale menim zaznamy
			{
				temp = zamestnanec[j];
				zamestnanec[j] = zamestnanec[j + 1];
				zamestnanec[j + 1] = temp;
			}
		}
	}
}

void bubleroknaopak(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV])
{
	int i, j;
	struct Zamestnanec temp;
	for (i = 0;i < MAX_ZAMESTNANCOV - 1;i++)
	{
		for (j = 0;j < (MAX_ZAMESTNANCOV - i - 1);j++)
		{
			if ((zamestnanec[j].udaje.narodenie.rok) < zamestnanec[j + 1].udaje.narodenie.rok) //porovnavam hodnoty ale menim zaznamy
			{
				temp = zamestnanec[j];
				zamestnanec[j] = zamestnanec[j + 1];
				zamestnanec[j + 1] = temp;
			}
		}
	}
}

void bublerok(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV])
{
	int i, j;
	struct Zamestnanec temp;
	for (i = 0;i < MAX_ZAMESTNANCOV - 1;i++)
	{
		for (j = 0;j < (MAX_ZAMESTNANCOV - i - 1);j++)
		{
			if ((zamestnanec[j].udaje.narodenie.rok) > zamestnanec[j + 1].udaje.narodenie.rok) //porovnavam hodnoty ale menim zaznamy
			{
				temp = zamestnanec[j];
				zamestnanec[j] = zamestnanec[j + 1];
				zamestnanec[j + 1] = temp;
			}
		}
	}
}

void bublemeno(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV])
{
	int i, j;
	struct Zamestnanec temp;
	for (i = 0;i < MAX_ZAMESTNANCOV - 1;i++)
	{
		for (j = 0;j < (MAX_ZAMESTNANCOV - i - 1);j++)
		{
			if ((strlen(zamestnanec[j].udaje.meno)) > strlen(zamestnanec[j + 1].udaje.meno)) //porovnavam hodnoty ale menim zaznamy
			{
				temp = zamestnanec[j];
				zamestnanec[j] = zamestnanec[j + 1];
				zamestnanec[j + 1] = temp;
			}
		}
	}
}

void bublemenonaopak(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV])
{
	int i, j;
	struct Zamestnanec temp;
	for (i = 0;i < MAX_ZAMESTNANCOV - 1;i++)
	{
		for (j = 0;j < (MAX_ZAMESTNANCOV - i - 1);j++)
		{
			if ((strlen(zamestnanec[j].udaje.meno)) < strlen(zamestnanec[j + 1].udaje.meno)) //porovnavam hodnoty ale menim zaznamy
			{
				temp = zamestnanec[j];
				zamestnanec[j] = zamestnanec[j + 1];
				zamestnanec[j + 1] = temp;
			}
		}
	}
}

void bublepozicia(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV])
{
	int i, j;
	struct Zamestnanec temp;
	for (i = 0;i < MAX_ZAMESTNANCOV - 1;i++)
	{
		for (j = 0;j < (MAX_ZAMESTNANCOV - i - 1);j++)
		{
			if ((strlen(zamestnanec[j].pozicia)) > strlen(zamestnanec[j + 1].pozicia)) //porovnavam hodnoty ale menim zaznamy
			{
				temp = zamestnanec[j];
				zamestnanec[j] = zamestnanec[j + 1];
				zamestnanec[j + 1] = temp;
			}
		}
	}
}

void bublepozicianaopak(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV])
{
	int i, j;
	struct Zamestnanec temp;
	for (i = 0;i < MAX_ZAMESTNANCOV - 1;i++)
	{
		for (j = 0;j < (MAX_ZAMESTNANCOV - i - 1);j++)
		{
			if ((strlen(zamestnanec[j].pozicia)) < strlen(zamestnanec[j + 1].pozicia)) //porovnavam hodnoty ale menim zaznamy
			{
				temp = zamestnanec[j];
				zamestnanec[j] = zamestnanec[j + 1];
				zamestnanec[j + 1] = temp;
			}
		}
	}
}

void kopirka(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV], struct Zamestnanec kopia[MAX_ZAMESTNANCOV])
{
	int i;
	for (i = 0;i < MAX_ZAMESTNANCOV;i++)
	{
		kopia[i].ID = zamestnanec[i].ID;
		kopia[i].udaje.narodenie.den = zamestnanec[i].udaje.narodenie.den;
		kopia[i].udaje.narodenie.mesiac = zamestnanec[i].udaje.narodenie.mesiac;
		kopia[i].udaje.narodenie.rok = zamestnanec[i].udaje.narodenie.rok;
		kopia[i].plat = zamestnanec[i].plat;

		strcpy(kopia[i].pozicia,zamestnanec[i].pozicia);
		strcpy(kopia[i].udaje.meno, zamestnanec[i].udaje.meno);
	}
}