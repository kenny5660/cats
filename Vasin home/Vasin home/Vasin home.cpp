// Vasin home.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	int NS, WE, t;
	FILE* fInput = fopen("input.txt", "r");
		fscanf(fInput, "%d %d %d", &NS, &WE, &t);
	fclose(fInput);

	t = t % (NS * 2 + WE * 2);
	FILE* fOut = fopen("output.txt", "w");
	if (t < NS) {
		fprintf(fOut, "S");
		fclose(fOut);
		return 0;
	}
		t -= NS;
	if(t<WE){
		fprintf(fOut, "E");
		fclose(fOut);
		return 0;
	}
	t -= WE;
	if (t<NS) {
		fprintf(fOut, "N");
		fclose(fOut);
		return 0;
	}
	t -= NS;
	if (t<WE)
	{
		fprintf(fOut, "W");
		fclose(fOut);
		return 0;
	}
		
	fclose(fOut);
    return 0;
}

