// Rabbit.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int M, A, B, C;
	FILE* fInput = fopen("input.txt", "r");
	fscanf(fInput, "%d %d %d %d", &M,&A,&B,&C);
	fclose(fInput);

	A *= 2; B *= 3, C *= 4;
	FILE* fOut = fopen("output.txt", "w");
	if (A >= B && B >= C) {
		fprintf(fOut, "%d",M+A+B+C);
	}
	else
	{
		fprintf(fOut, "-1");
	}


	fclose(fOut);
    return 0;
}

