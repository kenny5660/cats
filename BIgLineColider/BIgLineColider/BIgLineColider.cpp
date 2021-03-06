// BIgLineColider.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int compare(const void * x1, const void * x2);

int main()
{
	int N,Nt,t,Np = 0,Ne = 0,X,V;
	FILE* fInput = fopen("linear.in", "r");
	fscanf(fInput, "%d", &N);

	int*  electrons= (int*)malloc(sizeof(int)*(N));
	int*  times = (int*)malloc(sizeof(int)*(N/2));
	int*  protons = (int*)malloc(sizeof(int)*(N));
	
	for (int i = 0; i < N; ++i) {
		fscanf(fInput, "%d %d", &X, &V);
		if (V > 0) { protons[Np] = X; ++Np; }
		if (V < 0) { electrons[Ne] = X; ++Ne; }
	}
	
	int ie = 0,times_size = 0, ip = 0,dist;
	while (ie<Ne && ip<Np)
	{
		dist = electrons[ie]-protons[ip];
		if (dist <= 0) {
			++ie;
		}
		else
		{
			times[times_size] = dist;
			++ip;
			++ie;
			++times_size;
		}
	}
	FILE* fOut  = fopen("linear.out", "w");
	fscanf(fInput, "%d", &Nt);

	qsort(times, times_size, sizeof(int), compare);
	int answ;
	int j = 0;
	for (int i = 0; i < Nt; ++i) {
		fscanf(fInput,"%d", &t);

		while (times[j] == t*2 | times[j] == t * 2 - 1)
		{
			j++;
		}
		answ = N - j*2;
		if (answ < 0) {
			answ = 0;
		}
		fprintf(fOut,"%d ", answ);
	}

	fclose(fInput); fclose(fOut);
    return 0;
}
int compare(const void * x1, const void * x2)
{
	return (*(int*)x1 - *(int*)x2);
}
