#ifndef DATABAZA_H
#define DATABAZA_H

#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

// MAKRA na vymazanie obsahu konzoly a uspanie programu
#ifdef _WIN32
#include <windows.h>
#define CLEAR_SCREEN() system("cls")
#define SLEEP(sleepMs) Sleep(sleepMs)
#else
#include <unistd.h>
#define CLEAR_SCREEN() system("clear")
#define SLEEP(sleepMs) usleep(sleepMs * 1000)
#endif

// KONSTANTY
#define MAX_ZAMESTNANCOV 100 // max. pocet zamestnancov
#define MAX_LENGTH 20
struct Narodenie
{
	int den;
	int mesiac;
	int rok;
};

struct Udaje
{
	char meno[MAX_LENGTH];
	struct Narodenie narodenie;
};

struct Zamestnanec 
{
	int ID;
	int plat;
	char pozicia[MAX_LENGTH];
	struct Udaje udaje;
};


void generovanie(struct Zamestnanec *zamestnanec);
void zamestnanci(struct Zamestnanec *zamestnanec);
void vypis(struct Zamestnanec *zamestnanec,int pocet);
int nacitanie(struct Zamestnanec *zamestnanec);
void cisticplat(struct Zamestnanec *zamestnanec, int decide, int platI);
void cisticdatum(struct Zamestnanec *zamestnanec, int decide, int den, int mesiac, int rok);
void bubleplat(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV]);
void bubleplatnaopak(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV]);
void bublerok(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV]);
void bubleroknaopak(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV]);
void bublemeno(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV]);
void bublemenonaopak(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV]);
void bublepozicia(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV]);
void bublepozicianaopak(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV]);
void kopirka(struct Zamestnanec zamestnanec[MAX_ZAMESTNANCOV], struct Zamestnanec kopia[MAX_ZAMESTNANCOV]);
#endif