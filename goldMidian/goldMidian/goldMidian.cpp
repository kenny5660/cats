 // goldMidian.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

void heap_max_add(vector<int> &m,int a);
void heap_min_add(vector<int> &m, int a);
int heap_min_remove_root(vector<int> &m);
int heap_max_remove_root(vector<int> &m);
int main()
{
	int N;
	ifstream input("input.txt");
	ofstream output("output.txt");

	input >> N;
	vector<int> max_left_heap, min_right_heap;
	int a,b;
	input >> a >> b;
	output << a << " ";
	if (N == 1) {
		return 0; 
	}
	if (a > b) {
		heap_max_add(max_left_heap, b);
		heap_min_add(min_right_heap, a);
		output << b <<" ";
	}
	else
	{
		heap_max_add(max_left_heap, a);
		heap_min_add(min_right_heap, b);
		output << a << " ";
	}
	for (int i = 0; i < N-2; i++) {
		input >> a;
		if (a < max_left_heap[0]) {
			heap_max_add(max_left_heap, a);
		}
		else {
			heap_min_add(min_right_heap, a);
		}
		int diff = max_left_heap.size() - min_right_heap.size();
		if (diff > 1) {
			heap_min_add(min_right_heap, heap_max_remove_root(max_left_heap));
		}
		if (diff <-1) {
			heap_max_add(max_left_heap, heap_min_remove_root(min_right_heap));
		}
		 diff = max_left_heap.size() - min_right_heap.size();
		if (diff < 0) {
			output << min_right_heap[0] << " ";
		}
		else {
			output << max_left_heap[0] << " ";
		}
	}

	input.close();
	output.close();
    return 0;
}

void heap_max_add(vector<int> &m, int a) {
	m.insert(m.end(), a);
	int i = m.size() - 1;
	int parent = (i - 1) / 2;

	while (i > 0 && m[parent] < m[i])
	{
		int temp = m[i];
		m[i] = m[parent];
		m[parent] = temp;
		i = parent;
		parent = (i - 1) / 2;
	}
}

void heap_min_add(vector<int> &m, int a) {
	m.insert(m.end(), a);
	int i = m.size() - 1;
	int parent = (i - 1) / 2;

	while (i > 0 && m[parent] > m[i])
	{
		int temp = m[i];
		m[i] = m[parent];
		m[parent] = temp;
		i = parent;
		parent = (i - 1) / 2;
	}
}
int heap_max_remove_root(vector<int> &m) {
	int root_elm = m[0];
	m[0] = m.back();
	m.pop_back();
	int i = 0;
	while (true)
	{
		int child_1 = 2 * i + 1;
		int child_2 = 2 * i + 2;
		if (child_1 >= m.size()) {
			child_1 = i;
		}
		if (child_2 >= m.size()) {
			child_2 = i;
		}
		if (m[i] >= m[child_1] && m[i] >= m[child_2]) {
			break;
		}
		int temp,swap_child;
		if (m[child_1] > m[child_2]) {
			swap_child = child_1;
		}
		else
		{
			swap_child = child_2;
		}
		temp = m[i];
		m[i] = m[swap_child];
		m[swap_child] = temp;
		i = swap_child;
	}
	return root_elm;
}

int heap_min_remove_root(vector<int> &m) {
	int root_elm = m[0];
	m[0] = m.back();
	m.pop_back();
	int i = 0;
	while (true)
	{
		int child_1 = 2 * i + 1;
		int child_2 = 2 * i + 2;
		if (child_1 >= m.size()) {
			child_1 = i;
		}
		if (child_2 >= m.size()) {
			child_2 = i;
		}
		if (m[i] <= m[child_1] && m[i] <= m[child_2]) {
			break;
		}
		int temp, swap_child;
		if (m[child_1] < m[child_2]) {
			swap_child = child_1;
		}
		else
		{
			swap_child = child_2;
		}
		temp = m[i];
		m[i] = m[swap_child];
		m[swap_child] = temp;
		i = swap_child;
	}
	return root_elm;
}