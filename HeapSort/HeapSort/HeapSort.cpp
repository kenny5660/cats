#include "stdafx.h"
#include <iostream>
#include <vector>
#include<fstream>

using namespace std;
void add_heap(vector<int> &vec, int value);

int main()
{
	vector<int> heap;
	ifstream input("heapsort.in");
	ofstream output("heapsort.out");
	int N;
	input >> N;
	for (int i = 2; i <= N; ++i) {
		add_heap(heap,i);
	}
	heap.push_back(1);

	for (int i = 0; i < N; ++i) {
		output  << heap[i]<< " ";
	}
    return 0;
}

void add_heap(vector<int> &vec,int value)
{
	vec.push_back(value);
	int i = vec.size() - 1;
	int parent = (i - 1) / 2;

	while (i > 0 && vec[parent] < vec[i])
	{
		int temp = vec[i];
		vec[i] = vec[parent];
		vec[parent] = temp;

		i = parent;
		parent = (i - 1) / 2;
	}
}
