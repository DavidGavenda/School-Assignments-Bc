#include <stdio.h>
#include "robot_race.h"
#include <time.h>
#include <stdlib.h>


int main(int argc, char* argv[])
{
	int n = 5;
	srand(time(NULL));
	struct Track track;
	struct Robot robots[MAX_ROBOTS];
	initTrack(&track);
	initRobots(&robots, n, &track);
	while (1)
	{	
		CLEAR_SCREEN();
		if ((updateRobotPosition(&robots, n, &track)) == 0)
		{
			getch();
			break;
		}
		print(&robots, n, &track);
		//getch();
		SLEEP(200);
	}




	// 1. Vytvorenie pola robotov a jednej zavodnej trate
	//  a) Vytvorte pole zavodnych robotov. Pole bude mat
	//     kapacitu danu konstantou MAX_ROBOTS.
	//  b) Vytvorte jednu zavodnu trat


	// 2. Inicializacia trate a robotov
	//  a) Inicializujte zavodnu trat ... zavolanim funkcie initTrack()
	//  b) Inicializujte vsetkych robotov v poli ... zavolanim funkcie initRobots()

	// 3. Zavod
	do {
		// getchar() alebo SLEEP(...)

		// Pre kazdeho robota v poli sa zopakuju kroky 'a' a 'b':
			// a) kontrola, ci pohyb i-teho robota nesposobi koliziu
			// ... zavolanim funkcie isCollision()

			// b) ak pohyb i-teho robota sposobuje koliziu
			//    ---> potom: aktualizuj smer i-teho robota tak, aby sa vyhol kolizii
			//                ... zavolanim funkcie updateRobotDirection()
			//    --->  inak: robot sa pohne
			//                ... zavolanim funkcie updateRobotPosition()

		// Vypise sa zavodna trat ... zavolanim funkcie print()

	} while (0 /*...pokial ziadny robot nevyhral...*/);

	return 0;
}