#include "stdafx.h"
#include <stdio.h>
#include <math.h>

long long  C, P, N;
bool comparator(long long m); 

int main()
{
	FILE* fInput = fopen("input.txt", "r");
	fscanf(fInput, "%lld %lld %lld", &N, &P, &C);
	fclose(fInput);
	N *= 12;
	long long l = 1, r = C, mid;

	while ((r-l)>1)
	{
		mid = (l+r)/2;	
		if (comparator(mid)) 
		{ 
			l = mid;
		}
		else
		{
			r = mid;
		}
	}

	FILE* fOut = fopen("output.txt", "w");
	if (comparator(l)) {
		fprintf(fOut, "%lld", r);
	}
	else
	{
		fprintf(fOut, "%lld", l);
	}

	fclose(fOut);
    return 0;
}

bool comparator(long long m) {
	long long s = C;
	for (long long i = 0; i < N; ++i)
	{
		s = (long long)ceill((s - m)*1.0*(P*1.0 / 100.0 + 1));
		if (s >= C) {
			return true;
		}
		if (s < 0) {
			return false;
		}
	}
	return s > 0;
}