// bigNum_sum.cpp: определяет точку входа для консольного приложения.
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

big_num a, b,c;
string s;

void big_num_read(big_num &a, istream &input);
void big_num_print(big_num &a, ostream &out);
big_num big_num_sum(big_num &a, big_num &b);
int main()
{	 
	ifstream input("input.txt");
	ofstream output("output.txt");

	big_num_read(a, input);
	big_num_read(b, input);
	c = big_num_sum(a, b);
	big_num_print(c, output);
    return 0;
}
big_num big_num_sum(big_num &a, big_num &b) {


	vector<int> c(a);

	int carry = 0;
	for (size_t i = 0; i<max(c.size(), b.size()); ++i) {
		if (i == c.size())
			c.push_back(0);
		c[i] += carry + (i < b.size() ? b[i] : 0);
		carry = c[i] >= base;
		if (carry == 1)  c[i] -= base;
	}
	if (carry == 1)  c.push_back(carry);
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
void big_num_print(big_num &a,ostream &out) {
	out << (int)(a.empty() ? 0 : a.back());
	for (int i = (int)a.size() - 2; i >= 0; --i) {
		out << setfill('0') << setw(base_nums) << a[i];
	}
	out << endl;
}

