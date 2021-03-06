// BigNum_pow.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include<fstream>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> big_num;
const int base = 1000 * 1000 * 1000;
const int base_nums = 9;

big_num a, c;
string s;

void big_num_read(big_num &a, istream &input);
void big_num_print(big_num &a, ostream &out);
big_num big_num_pow(big_num &a, int n);

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	big_num_read(a, input);
	int n = 0;
	input >> n;
	c = big_num_pow(a, n);
	big_num_print(c, output);
	return 0;
}
big_num big_num_mul(big_num &a, big_num &b) {
	big_num c(a.size() + b.size());
	for (size_t i = 0; i<a.size(); ++i)
		for (int j = 0, carry = 0; j<(int)b.size() || carry; ++j) {
			long long cur = c[i + j] + a[i] * 1ll * (j < (int)b.size() ? b[j] : 0) + carry;
			c[i + j] = int(cur % base);
			carry = int(cur / base);
		}
	while (c.size() > 1 && c.back() == 0)
		c.pop_back();
	return c;
}
big_num big_num_pow(big_num &a, int n) {
	big_num c(a);
	for (int m = 1; m < n; ++m) {
		c = big_num_mul(c, a);
	}
	return c;
}
void big_num_read(big_num &a, istream &input) {
	input >> s;
	for (int i = (int)s.length(); i>0; i -= base_nums)
		if (i < base_nums)
			a.push_back(atoi(s.substr(0, i).c_str()));
		else
			a.push_back(atoi(s.substr(i - base_nums, base_nums).c_str()));
}
void big_num_print(big_num &a, ostream &out) {
	out << (int)(a.empty() ? 0 : a.back());
	for (int i = (int)a.size() - 2; i >= 0; --i) {
		out << setfill('0') << setw(base_nums) << a[i];
	}
	out << endl;
}

