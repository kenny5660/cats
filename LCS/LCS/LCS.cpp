// LCS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <algorithm>
using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	string a, b;
	input >> a >> b;
	vector<vector<int>> dists(a.size() + 1, vector<int>(b.size() + 1, 0));

	for (int i = a.size()-1; i >= 0; i--) {
		for (int j = b.size()-1; j >= 0; j--) {
			if (a[i] == b[j]) {
				dists[i][j] = dists[i + 1][j + 1] + 1;
			}
			else {
				dists[i][j] = max(dists[i + 1][j], dists[i][j + 1]);
			}
		}
	}
	
	string answ;
	int i = 0;
	int j = 0;
	while (i < a.size() && j < b.size()) {
		if (a[i] == b[j]) {
			answ.push_back(a[i]);
			i++;
			j++;
		}
		else {
			if (dists[i + 1][j] >= dists[i][j+1]) {
				i++;
			}
			else {
				j++;
			}
		}
	}
	output << answ;
	return 0;
}