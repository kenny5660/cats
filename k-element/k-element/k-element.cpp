// k-element.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<stdio.h>

int main()
{
	int N, K;
	static int data[1000000];
	FILE* f_input = fopen("input.txt", "r");
	fscanf(f_input, "%d %d", N, K);
	for (int i = 0; i < N; ++i) {
		fscanf(f_input, "%d", data[i]);
	}
	FILE* f_output = fopen("output.txt", "w");
	fprintf(f_output,"%d", data[K]);

	fcloseall();
    return 0;
}

