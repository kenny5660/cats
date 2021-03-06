// palindrom.cpp: определяет точку входа для консольного приложения.
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
	input >> s;
	string rev_s = s;
	reverse(rev_s.begin(), rev_s.end());
	string kmp_s = rev_s + "@" + s;

	vector<uint64_t> prefix(kmp_s.length());
	prefix_func(kmp_s, prefix);
	rev_s = rev_s.substr(prefix[prefix.size() - 1]);
	output << rev_s;
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