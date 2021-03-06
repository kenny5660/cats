// Dijkstra.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <algorithm>
#include <set>
using namespace std;


typedef vector <vector<pair<int, int> > > graph;


int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	int N;//vertices
	int	M;//Edges
	int S;
	input >> N >> M >> S;
	S--;
	graph G(N);
	int St, End, weight;
	for (int i = 0; i < M; ++i) {
		input >> St >> End >> weight;
		G[St - 1].push_back(pair<int, int>(End - 1, weight));
	}
	vector<int> dists(N, INT_MAX);
	dists[S] = 0;
	set < pair<int, int> > q;
	q.insert(make_pair(dists[S], S));
	while (!q.empty()) {
		int v_cur = q.begin()->second;
		q.erase(q.begin());
		for (size_t j = 0; j < G[v_cur].size(); ++j) {
			int to = G[v_cur][j].first,
				len = G[v_cur][j].second;
			if (dists[v_cur] + len < dists[to]) {
				q.erase(make_pair(dists[to], to));
				dists[to] = dists[v_cur] + len;
				q.insert(make_pair(dists[to], to));
			}
		}
	}
	for (auto it = dists.begin(); it != dists.end(); ++it) {
		if (*it == INT_MAX) {
			output << -1 << " ";
		}
		else {
			output << *it << " ";
		}
	}

	return 0;
}

