// Ford-Bellman.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <algorithm>
#include <set>
using namespace std;

typedef struct {
	int s, end, cost;
}edge_t;

typedef vector <edge_t> graph;

const int inf = 1000000;
int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	int N;//vertices
	int	M;//Edges
	int S;
	input >> N >> M >> S;
	S--;
	graph G;
	int St, End, weight;
	for (int i = 0; i < M; ++i) {
		input >> St >> End >> weight;
		G.push_back({ St - 1,End - 1,weight });
	}

	vector<int> dists(N, inf);
	dists[S] = 0;
	while (true) {
		bool stop = false;
		for (int j = 0; j < M; ++j) {
			if (dists[G[j].s] < inf) {
				if (dists[G[j].end] > dists[G[j].s] + G[j].cost) {
					dists[G[j].end] = dists[G[j].s] + G[j].cost;
					stop = true;
				}
			}
		}
		if (!stop)  break;
	}

	for (auto it = dists.begin(); it != dists.end(); ++it) {
		if (*it == inf) {
			output << " " << " ";
		}
		else {
			output << *it << " ";
		}
	}
	return 0;
}