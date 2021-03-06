// Knapsack problem.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	int N, W;
	input >> N >> W;
	vector<int> a;
	a.push_back(0);
	for (int i = 0; i < N; ++i) {
		int num;
		input >> num;
		a.push_back(num);
	}

	vector<vector<int>> F(N + 1, vector<int>(W + 1, 0));
	for (int i = 1; i < N + 1; ++i) {
		for (int j = 1; j < W + 1; ++j) {
			if (j >= a[i]) {
				F[i][j] = max(F[i - 1][j], F[i - 1][j - a[i]] + a[i]);
			}
			else {
				F[i][j] = F[i - 1][j];
			}
		}
	}
	if (F[N][W] != W) {
		output << "-1";
		return 0;
	}
	stack<pair<int, int>> stack_ans;
	vector<bool> answ(N + 1, 0);
	int answ_size = 0;
	stack_ans.push(make_pair(N, W));

	while (!stack_ans.empty())
	{
		pair<int, int> cur_pair = stack_ans.top();
		stack_ans.pop();

		if (F[cur_pair.first][cur_pair.second] == 0) {
			continue;
		}
		if (F[cur_pair.first - 1][cur_pair.second] == F[cur_pair.first][cur_pair.second]) {
			stack_ans.push(make_pair(cur_pair.first - 1, cur_pair.second));
		}
		else {
			stack_ans.push(make_pair(cur_pair.first - 1, cur_pair.second - a[cur_pair.first]));
			answ[cur_pair.first] = 1;
			answ_size++;
		}
	}
	for (int i = 1; i < N + 1; ++i) {
		output << answ[i] << " ";
	}
	return 0;
}
