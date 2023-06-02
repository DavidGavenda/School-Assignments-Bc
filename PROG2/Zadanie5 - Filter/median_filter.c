#include "median_filter.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>


int loadData(double* input, int n)
{
	int i = 0; //hodnota do ktorej pridavam aby som vedel pocet hodnot
	double val;
	while (scanf("%lf", &val) > 0) // nacitavam po prvy neuspesny pokus
	{
		input[i] = val;  // dosadzujem hodnoty do pola
		i++;
	}
    return i;
}

int compare(const void * a, const void * b)
{
	if (*(double*)a > *(double*)b) return 1;
	else if (*(double*)a < *(double*)b) return -1;
	else return 0;
}

void filterData(double *input, double* output, int k, int w)
{
	w = 2 * w + 1;
	int i, j = w - 1, stred = (w/2),f=stred-1;
	int h,s;
	for (s = 0;s < w;s++)
	{
		output[0 + s] = input[0 + s];
		output[k - 1 - s] = input[k - 1 - s];
	}
	double pomocnik[MAX_W];
	while (j < k)
	{

		j = j - (w-1); // aby som stale stupal o jedno
		for (i = 0;i < w;i++)
		{
			pomocnik[i] = input[j];
			j++;
		}

		qsort(pomocnik, w, sizeof(double), compare);
		f = f + 1 ;
		output[f] = pomocnik[(stred)];
		i = 0;
	}
}

void printData(double *data, int n)
{
	int i = 0;
	for (i = 0;i < n;i++)
	{
		printf("%.*lf\n",PRECISION, data[i]); //vypis s PRECISION
	}
}
