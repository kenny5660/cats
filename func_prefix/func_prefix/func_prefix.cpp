// func_prefix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <algorithm>
using namespace std;
void prefix_func(string s, vector<uint64_t> &p);
int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	string s;
	uint64_t sum = 0;
	input >> s;

	vector<uint64_t> f(s.length());
	prefix_func(s, f);
	for (int i = 0; i < f.size(); ++i) {
		sum += f[i];
	}
	output << sum;
    return 0;
}

void prefix_func(string s, vector<uint64_t> &p) {
	for (int i = 1; i < s.length(); ++i) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) {
			j = p[j - 1];
		}
		if (s[i] == s[j]) {
			++j;
		}
		p[i] = j;
	}
}