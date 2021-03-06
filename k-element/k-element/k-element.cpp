// k-element.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int qselect(int* data, size_t size, int K);
int N, K;

int main()
{
		FILE* f_input = fopen("input.txt", "r");
		fscanf(f_input, "%d %d", &N, &K);
		K--;
		int* data = (int*)malloc(N * sizeof(int));
		for (int i = 0; i < N; ++i) {
			fscanf(f_input, "%d ", &data[i]);
		}
		FILE* f_output = fopen("output.txt", "w");

		fprintf(f_output, "%d ", qselect(data, N - 1, K));
		
		fcloseall();
		free(data);

	return 0;
}

int partition(int* data, int l, int r) {
		int mid = data[l + (r - l) / 2];
		int i = l, j = r, t;
		while (i <= j) {
			while (data[i] < mid) { i++; }
			while (data[j] > mid) { j--; }
			if (i >= j) {
				break;
			}
			t = data[i];
			data[i] = data[j];
			data[j] = t;
			++i;
			--j;
		}
		return j;
}

int qselect(int* data, size_t size, int K) {
	int l = 0, r = size, m;
	while (1) {
		m = partition(data, l, r);
		if (K == m) {
			return data[m];
		}
		if (K < m) {
			r = m;
		}
		else {
			//K -= m + 1;
			l = m + 1;
		}
	}
}