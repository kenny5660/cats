// Altitude_and_visibility.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <algorithm>
using namespace std;
int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	int N;
	input >> N;

	int* m = new int[N];
	int* m_ptrs_L = new int[N];
	int* m_ptrs_R = new int[N];
	for (int i = 0; i < N; ++i) {
		input >> m[i];
	}
	m_ptrs_L[0] = 0;
	for (int i = 1; i < N; ++i) {
		int j = i - 1;
		while (m[i] >= m[j] && j != m_ptrs_L[j]) {
			j = m_ptrs_L[j];
		}
		if (m[j]>m[i]) {
			m_ptrs_L[i] = j;
		}
		else
		{
			m_ptrs_L[i] = i;
		}
	}

	m_ptrs_R[N - 1] = N - 1;
	for (int i = N - 2; i >= 0; --i) {
		int j = i + 1;
		while (m[i] >= m[j] && j != m_ptrs_R[j]) {
			j = m_ptrs_R[j];
		}
		if (m[j]>m[i]) {
			m_ptrs_R[i] = j;
		}
		else
		{
			m_ptrs_R[i] = i;
		}
	}

	for (int i = 0; i < N; ++i) {
		if (i-m_ptrs_L[i] == 0) {
			output << m_ptrs_R[i] - i << " ";
			continue;
		}
		if (m_ptrs_R[i]-i == 0) {
			output << i - m_ptrs_L[i] << " ";
			continue;
		}

		output << min(i-m_ptrs_L[i],m_ptrs_R[i]-i) << " ";
	}
	return 0;
}

