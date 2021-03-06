// k-element.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int qselect(int* data, size_t size, int K);
int N, K;
int compare(const void * x1, const void * x2);
int main()
{
	for (int j = 0; j < 100000; ++j) {
		
//		FILE* f_inputT = fopen("input.txt", "w");
		srand(time(NULL));
		N = 100000;
		K = rand() % 100000;
		int* data = (int*)malloc(N * sizeof(int));
	//	fprintf(f_inputT, "%d %d\n", 100000, rand() % 10000);
		for (int i = 0; i < 100000; ++i) {
			data[i] = rand() % 10000 - 50;
		}
		//fclose(f_inputT);

	/*	FILE* f_input = fopen("input.txt", "r");
		fscanf(f_input, "%d %d", &N, &K);*/
		K--;
		
		/*for (int i = 0; i < N; ++i) {
			fscanf(f_input, "%d ", &data[i]);
		}*/
	//	FILE* f_output = fopen("output.txt", "w");
		int y = qselect(data, N - 1, K);
		qsort(data, N, sizeof(int), compare);
		if ( y != data[K]) {
			printf("bad((");
			break;
			FILE* f_inputT = fopen("input.txt", "w");
			fprintf(f_inputT, "%d %d\n", N, K);
			for (int i = 0; i < 100000; ++i) {
				fprintf(f_inputT, "%d ", data[i]);
			}
			fclose(f_inputT);


		}
	//	fprintf(f_output, "%d ", qselect(data, N - 1, K));

		//fprintf(f_output, "%d ", data[K]);
		fcloseall();
		free(data);
	}
	return 0;
}
int compare(const void * x1, const void * x2)   // функция сравнения элементов массива
{
	return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}
int partition(int* data, int l, int r) {
		int mid = data[l + (r - l) / 2];
		int i = l;
		int j = r;
		int t;
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
