// KMP.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <algorithm>
using namespace std;
int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");

	string t, s, kmp_s;
	int pos = -1;
	getline(input, t);
	getline(input, s);

	kmp_s = s + "@" + t;

	vector<uint64_t> p(kmp_s.length());

	for (int i = 1; i < kmp_s.length(); ++i) {
		int j = p[i - 1];
		while (j > 0 && kmp_s[i] != kmp_s[j]) {
			j = p[j - 1];
		}
		if (kmp_s[i] == kmp_s[j]) {
			++j;
		}
		p[i] = j;
		if (p[i] == s.size() && i > s.size()) {
			pos = i - 2 * s.size() + 1;
			break;
		}
	}

	output << pos;
	return 0;
}