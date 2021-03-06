// Reduction_polynomial.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

uint64_t mod_sum(uint64_t a, uint64_t b, uint64_t p) {
	if (a < (p - b)) {
		return a + b;
	}
	else {
		return b - (p - a);
	}
}
uint64_t mod_mul(uint64_t a, uint64_t b, uint64_t p) {
	uint64_t k = a, c = 0;
	while (b != 0)
	{
		if (b % 2 == 1) {
			c = mod_sum(c, k,p);
		}
		b = b / 2;
		k = mod_sum(k, k, p);
	}
	return c;
}

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");

	vector<uint64_t> pol;
	uint64_t p;
	int n;
	input >> p >> n;
	n++;
	mod_mul(6, 5, 100);
	for (int i = 0; i < n; ++i) {
		uint64_t C;
		input >> C;
		pol.push_back(C);
	}
	if (pol.size() > 1) {
		uint64_t last= 1, cur = pol[0];
		pol[1] = mod_mul(p - pol[1], pol[0], p);

		for (int i = 2; i < n; ++i) {
			cur = pol[0];
			for (int j = 1; j < i ; ++j) {
				last = cur;
				cur =  pol[j];
				pol[j] = mod_sum(cur,mod_mul(p-pol[i], last, p), p);
				
			}
			pol[i] = mod_mul(p - pol[i], cur, p);
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		output << pol[i] << endl;
	}
    return 0;
}
