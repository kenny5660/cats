// Floyd-Warshall.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <algorithm>
using namespace std;

typedef vector<vector<int>> graph;

const int inf = INT_MAX / 2;
int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	int N;//vertices
	int	M;//Edges
	input >> N >> M;
	graph G(N, vector<int>(N, inf));
	int St, End, C;
	for (int i = 0; i < M; ++i) {
		input >> St >> End >> C;
		G[St - 1][End - 1] = C;
	}
	for (int i = 0; i < N; ++i) {
		G[i][i] = 0;
	}


	vector<vector<int>> dists(G);
	for (int k = 0; k < N; ++k) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (dists[i][k] < inf && dists[k][j] < inf) {
					dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
				}
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (dists[i][j] == inf) {
				output << "  ";
			}
			else {
				output << dists[i][j] << " ";
			}
		}
		output << endl;
	}
	return 0;
}

