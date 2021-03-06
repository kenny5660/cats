// LIS.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include<fstream>
#include <algorithm>
using namespace std;

int bin_search(vector<int> &a, int val) {
	int l = -1;
	int r = a.size() - 1;
	int m = 0;
	while (l < (r - 1)) {
		m = (l + r) / 2;
		if (a[m] < val) {
			l = m;
		}
		else {
			r = m;
		}
	}
	return r;
}

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	vector<int> a;
	int n;
	input >> n;
	for (int i = 0; i < n; ++i) {
		int num;
		input >> num;
		a.push_back(num);
	}
	if (n == 1) {
		output << 1 << endl;;
		output << 1 << " ";
		return 0;
	}

	vector<int> dist(n + 1);
	vector<int> pos(n + 1);
	vector<int> prev(n + 1);
	int len = 0;
	int j = 0;
	pos[0] = -1;
	dist[0] = INT_MIN;
	for (int i = 1; i < n + 1; ++i) {
		dist[i] = INT_MAX;
	}

	for (int i = 0; i < n; ++i) {
		j = bin_search(dist, a[i]);
		if (dist[j - 1] < a[i] && a[i] <= dist[j]) {
			dist[j] = a[i];
			pos[j] = i;
			prev[i] = pos[j - 1];
			len = max(len, j);
		}
	}

	vector<int> ans;
	int p = pos[len];
	while (p != -1) {
		ans.push_back(p + 1);
		p = prev[p];
	}

	output << len << endl;;
	for (int i = ans.size() - 1; i >= 0; --i) {
		output << ans[i] << " ";
	}

	return 0;
}