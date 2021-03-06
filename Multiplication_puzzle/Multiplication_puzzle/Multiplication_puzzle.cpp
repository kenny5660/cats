// Multiplication_puzzle.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <algorithm>
using namespace std;

int min_sum(vector<int> &cards);

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	int n;
	input >> n;
	vector<int> cards;
	vector<bool> mask(n, 1);
	for (int i = 0; i < n; ++i) {
		int card;
		input >> card;
		cards.push_back(card);
	}
	output << min_sum(cards);
	return 0;
}

int min_sum(vector<int> &cards) {

	vector<vector<int>> m(cards.size(), vector<int>(cards.size(), INT_MAX));
	for (int i = 1; i < cards.size(); ++i) {
		m[i][i] = 0;
	}
	for (int l = 2; l < cards.size(); ++l) {
		for (int i = 1; i < cards.size() - l + 1; ++i) {
			int j = i + l - 1;
			for (int k = i; k <= j - 1; k++) {
				m[i][j] = min(m[i][j], m[i][k] + m[k + 1][j] + cards[i - 1] * cards[k] * cards[j]);
			}
		}
	}
	return m[1][cards.size() - 1];
}

