// nearest number.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	int N;
	input >> N;
	
	int* m = new int[N];
	int* m_ptrs = new int[N];
	for (int i = 0; i < N; ++i) {
		input >> m[i];
	}
	m_ptrs[N - 1] = N - 1;
	for (int i = N-2; i >=0; --i) {
		int j = i + 1;
		while (m[i] >= m[j] && j != m_ptrs[j]) {
			j = m_ptrs[j];
		}
		if (m[j]>m[i]) {
			m_ptrs[i] = j;
		}
		else
		{
			m_ptrs[i] = i;
		}
	}
	for (int i = 0; i < N; ++i) {
		output << m[m_ptrs[i]] << " ";
	}
    return 0;
}

