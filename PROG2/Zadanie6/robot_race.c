#include <stdio.h>
#include "robot_race.h"
#include <time.h>
#include <stdlib.h>

#define M_PI 3.14159265358979323846




// POPIS:
// Funkcia 'initTrack' inicializuje trat pred zavodom.
// Nahodne sa vygeneruju prekazky na trati 'track'.
// Pocet prekazok ako aj algoritmus generovania prekazok
// si urcite sami.
// VSTUP:
//      * track - smernik na zavodnu trat
// VYSTUP:
//      * funkcia nic nevrati

/* ...ODKOMENTUJTE ked budete mat hotovu deklaraciu funkcie v subore robot_race.h

void initTrack(Track* track){
	// TODO
}

*/
void initTrack(struct Track *track)
{
	track->sirka = MAX_TRACK_WIDTH;
	track->vyska = MAX_TRACK_HEIGHT;
	track->pocetprekazok = MAX_OBSTACLES;
	int x, y, pvtrati = 0, a = 0, sektor = 1, randomik;
	for (x = 0;x < track->vyska;x++)
	{
		for (y = 0;y < track->sirka;y++)
		{
			track->pole[x][y] = 0; //vytvorim si praznde pole, sluzi na vypis
		}
	}

	while (pvtrati < track->pocetprekazok)
	{
		track->prekazky[a].x = (rand() % (((MAX_TRACK_HEIGHT / 10)*sektor) + 10 * sektor) + a) % MAX_TRACK_HEIGHT;
		track->prekazky[a].vyska = rand() % (MAX_TRACK_HEIGHT / 10) + 1;

		track->prekazky[a].y = rand() % (MAX_TRACK_WIDTH);
		track->prekazky[a].sirka = rand() % (MAX_TRACK_WIDTH / 10) + 1;
		sektor = sektor + 1;
		if (sektor >= 5) sektor = 1;
		pvtrati = pvtrati + (track->prekazky[a].vyska*track->prekazky[a].sirka);;

		for (x = track->prekazky[a].x;x < track->prekazky[a].x + track->prekazky[a].vyska;x++) //doplni mi to vypisu
		{
			for (y = track->prekazky[a].y;y < track->prekazky[a].y + track->prekazky[a].sirka;y++)
			{
				if ((x > MAX_TRACK_HEIGHT) || (y > MAX_TRACK_WIDTH)) break;
				track->pole[x][y] = 1;
			}
		}
		a = a + 1;
	}
}


void initRobots(struct Robot *robots, int n, struct Track *track)
{
	int i,k=0;
	for (i = 0;i < n;i++)
	{
		robots[i].x = 0;
		robots[i].y = rand() % (MAX_TRACK_WIDTH/n)+k;
		k = k + MAX_TRACK_WIDTH/n; //aby boli rozdeleny po celom
		track->pole[robots[i].x][robots[i].y] = i+97;
		//printf("%d,%d\n", robots[i].x, robots[i].y);
	}
}



void print(struct Robot *robots, int n, struct Track *track)
{
	int x, y, stred = MAX_TRACK_WIDTH / 2;;
	char *ptr1 = "START";
	printf("%*s\n", stred - 1, ptr1);
	for (x = 0;x < track->vyska;x++)
	{
		printf("|");
		for (y = 0;y < track->sirka;y++)
		{

			if (track->pole[x][y] > 9) printf("%c", track->pole[x][y]);
			else if (track->pole[x][y] == 1) printf("X");
			else if (track->pole[x][y] == -1) printf(".");
			else printf(" ");
		}
		printf("|\n");
	}
	char *ptr2 = "END";
	printf("%*s\n", stred, ptr2);

}

int updateRobotPosition(struct Robot *robots, int n,struct Track* track)
{
	double ret, rad, rot;
	int i;
	for (i = 0;i < n;i++)
	{	
		//printf("%d,%d\n", robots[i].x, robots[i].y);
		track->pole[robots[i].x][robots[i].y] = -1;
		robots[i].smer = 270;
		/*rad = robots[i].smer * M_PI / 180.0;
		ret = cos(rad);
		robots[i].x =(int)(robots[i].x + ROBOT_SPEED * ret);
		rot = sin(rad);
		robots[i].y =(robots[i].y + ROBOT_SPEED * rot);*/
		if (track->pole[robots[i].x + ROBOT_SPEED][robots[i].y] == 0)
		{
			(track->pole[robots[i].x + ROBOT_SPEED][robots[i].y] = 15);
			robots[i].x = robots[i].x + ROBOT_SPEED;
		}
		else
		{
			track->pole[robots[i].x][robots[i].y + ROBOT_SPEED] = 15;
			robots[i].y = robots[i].y + ROBOT_SPEED;
			if (robots[i].x >= MAX_TRACK_HEIGHT - 1)
			{
				printf("Vyhral %c", i+97);
				return 0;
			}
		}
		//printf("%d,%d\n",robots[i].x, robots[i].y);
	}
	return 1;
}

// POPIS:
// Funkcia 'updateRobotPosition' aktualizuje poziciu robota
// (t.j. robot sa pohne z jeho starej pozicie v jeho aktualnom
// smere a aktualnou rychlostou).
// VSTUP:
//      * robot - smernik na robota, ktoreho poziciu ideme aktualizovat
// VYSTUP:
//      * funkcia nic nevrati


/* ...ODKOMENTUJTE ked budete mat hotovu deklaraciu funkcie v subore robot_race.h

void updateRobotPosition(Robot* robot)
{
	// TODO
}

*/







// POPIS:
// Funkcia 'updateRobotDirection' aktualizuje smer robota a to tak,
// aby sa vyriesila kolizna situacia s hranicou zavodnej trate
// alebo s prekazkou (to zavisi od parametra 'obstacle_id').
// VSTUP:
//      * robot - smernik na robota, ktory je v koliznej situacii
//      * track - smernik na zavodnu trat
//      * obstacle_id - identifikator koliznej situacie
// VYSTUP:
//      * funkcia nic nevracia

/* ...ODKOMENTUJTE ked budete mat hotovu deklaraciu funkcie v subore robot_race.h

void updateRobotDirection(Robot* robot, Track* track, int obstacle_id)
{
	// TODO
}

*/









// POPIS:
// Funkcia 'isCollision' zisti, ci sa robot moze zo svojej aktualnej pozicie
// pohnut aktualnym smerom a aktualnou rychlostou alebo dochadza ku kolizii
// (prekazka alebo hranica trate).
// VSTUP:
//      * robot - smernik na robota
//      * track - smernik na zavodnu trat
// VYSTUP:
//      * vrati -2: pohyb robota bude platny
//      * vrati -1: pohyb sposobi koliziu s hranicou trate
//      * vrati 0...n: pohyb robota sposobi koliziu s 'i'-tou prekazkou v poli prekazok

/* ...ODKOMENTUJTE ked budete mat hotovu deklaraciu funkcie v subore robot_race.h

int isCollision(Robot* robot, Track* track)
{
	// TODO
}

*/
