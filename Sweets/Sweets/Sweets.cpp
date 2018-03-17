// Sweets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
int main()
{
	int S,K;
	char* c;
	scanf("%s", c);

	FILE* fInput = fopen("input.txt", "r");
	fscanf(fInput, "%d %d", &S,&K);
	fclose(fInput);
	long long K2 = (long long)(K + 1)*(long long)(K + 1);
	long long D =K2 - S * 4;
	long long M;
	if (D < 0)
		M = K / 2+1;
	else
	    M = ((K + 1)-sqrt(D)) / 2;
	if (M < 1)
		M++;
	FILE* fOut = fopen("output.txt", "w");
	fprintf(fOut, "%d",M);


	fclose(fOut);
    return 0;
}

