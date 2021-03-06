// SpaceForPupils.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
int compare(const void * x1, const void * x2);
int main()
{
	int N;
	bool isWrite = false;
	FILE* fInput = fopen("input.txt", "r");
	fscanf(fInput,"%d",&N);
	int* times = (int*)malloc(sizeof(int)*(N+2));
	int hour, min;
	for (int i = 1; i < N+1; ++i) {
		fscanf(fInput, "%d:%d", &hour,&min);
		times[i] = hour * 60 + min;
	}
	fclose(fInput) ;
	times[0] = -1;
	times[N + 1] = 1440;
	qsort(times, N+2, sizeof(int), compare);

	FILE* fOut = fopen("output.txt", "w");
	for (int i = 0; i < N+1; ++i) {
		if (times[i+1] - times[i] == 2) {
			fprintf(fOut, "%02d:%02d\n", (times[i]+1) / 60, (times[i]+1) % 60);
			isWrite = true;
			continue;
		}
		if (times[i+1] - times[i] > 2) {
			fprintf(fOut, "%02d:%02d - %02d:%02d\n", (times[i]+1) / 60, (times[i]+1) % 60,(times[i+1]-1)/60, (times[i + 1] - 1) % 60);
			isWrite = true;
			continue;
		}
	}
	if(!isWrite){
		fprintf(fOut,"NONE");
	}
	fclose(fOut);
    return 0;
}

int compare(const void * x1, const void * x2)
{
	return (*(int*)x1 - *(int*)x2);     
}