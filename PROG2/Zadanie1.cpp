
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <time.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif


int get_speed(int v_old) 
{
	if (v_old ==0)
	{
		v_old= rand() % 100 + 350;
	}
	else 
	{
		v_old = v_old + rand() % 25 - 5;
	}
	return v_old;

}


int kontrola(int vzd, int rych)
{
	if ((vzd%5000)==0)
	{
		if ((vzd != 0) and (vzd != 40000))
		{
			printf("Hrac spadol\n");
			rych = 0;
		}
	}
	return rych;
}




int main()
{
	srand(time(NULL));
	int rych1, rych2, vzd1, vzd2,s;
	rych1 = 0; rych2 = 0; vzd1 = 0;vzd2 = 0,s=0;
	while (vzd1<=40000 and vzd2<=40000) 
	{
		rych1 = get_speed(rych1);
		rych2 = get_speed(rych2);
		s++;
		printf("Zacina %d. sekunda behu\n", s);
		vzd1 = vzd1 + rych1;
		vzd2 = vzd2 + rych2;
		printf("Rychlost na prveho bezca: %d\ cm/s a zatial ubehol %d cm\n", rych1, vzd1);
		printf("Rychlost na druheho bezca: %d cm/s a zatial ubehol %d cm\n", rych2, vzd2);


		rych1 = kontrola(vzd1, rych1);
		rych2 = kontrola(vzd2, rych2);


		if (vzd1 >= 40000)
		{
			printf("Vyhral prvy bezec");
		}
		if (vzd2 >= 40000)
		{
			printf("Vyhral druhy bezec");
		}
		Sleep(1000);
	}
     
}

