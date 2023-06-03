
#include "pch.h"
#include <iostream>
#include <stdio.h>      
#include <math.h>
#define M_PI 3.14159265358979323846
#pragma warning(disable:4996)

int main()
{
	float EPSILONF;
	double EPSILOND;
	EPSILONF = 1.0;
	EPSILOND = 1.0;

	while ((1.0 + 0.5*float(EPSILONF)) != (1.0))
	{
		float EPSILONF = 0.5* float EPSILONF;
	}
	printf("EPSILON FLOAT = %12.5e\n", EPSILONF);

	while ((1.0 + 0.5*EPSILOND) != (1.0))
	{
		EPSILOND = 0.5*EPSILOND;
	}
	printf("EPSILON DOUBLE = %12.5e\n", EPSILOND);
}




