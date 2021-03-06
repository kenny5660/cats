// Topological sorting.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <algorithm>
#pragma comment(linker, "/STACK:4437184")
using namespace std;

const int white = 0;
const int grey = 1;
const int black = 2;

typedef vector<vector<int>> graph;
graph G;
vector<uint8_t> used;
vector<int> stack_tp;

bool topologic_sort_rec(int node) {
	used[node] = grey;
	for (int i = 0; i < G[node].size(); ++i) {
		if (used[G[node][i]] == grey)return true;
		if (used[G[node][i]] != black) {
			if (topologic_sort_rec(G[node][i])) return true;
		}
	}
	used[node] = black;
	stack_tp.push_back(node);
	return false;
}
bool topologic_sort() {
	used.resize(G.size(), white);
	bool cycle = false;
	for (int i = 0; i < used.size(); ++i) {
		if (used[i] == white) {
			cycle = topologic_sort_rec(i);
			if (cycle) {
				return cycle;
			}
		}
	}
	return cycle;
}
int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	int N;//vertices
	int	M;//Edges
	input >> N >> M;
	G.resize(N);
	int St, End;
	for (int i = 0; i < M; ++i) {
		input >> St >> End;
		G[St - 1].push_back(End - 1);
	}
	if (N == 0) {
		output << -1;
		return 0;
	}

	if (topologic_sort() || stack_tp.size() != N) {
		output << -1;
	}
	else {
		for (int i = N - 1; i >= 0; --i) {
			output << stack_tp[i] + 1 << " ";
		}
	}
	return 0;
}