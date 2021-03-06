// Biconnectivity.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include<fstream>
#include <algorithm>
#include <set>
#pragma comment(linker, "/STACK:10437184")
using namespace std;

const int white = 0;
const int grey = 1;
const int black = 2;
const int is_root = -1;

typedef vector<vector<int>> graph;
graph G;
vector<uint8_t> used;
set<int> bicons;
vector<int>tin, fup;
int timer = 0;

void bicon_rec(int node, int prev) {
	used[node] = grey;
	tin[node] = fup[node] = timer++;
	int childs = 0;
	for (int i = 0; i < G[node].size(); ++i) {
		int to = G[node][i];
		if (to == prev)  continue;
		if (used[to] != white)
			fup[node] = min(fup[node], tin[to]);
		else {
			bicon_rec(to, node);
			fup[node] = min(fup[node], fup[to]);
			if (fup[to] >= tin[node] && prev != is_root) {
				bicons.insert(node);
			}
			childs++;
			used[node] = black;
		}
	}
	if (prev == is_root && childs > 1) {
		bicons.insert(node);
	}
}

void bicon() {
	used.resize(G.size() + 1, white);
	tin.resize(G.size() + 1, 0);
	fup.resize(G.size() + 1, 0);
	for (int i = 0; i < used.size() - 1; ++i) {
		if (used[i] == white) {
			bicon_rec(i, is_root);
		}
	}
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
		G[End - 1].push_back(St - 1);
	}
	if (N == 0) {
		output << 0;
		return 0;
	}

	bicon();

	output << bicons.size() << " ";
	if (bicons.size() > 0) {
		for (auto it = bicons.begin(); it != bicons.end(); ++it) {
			output << *it + 1 << " ";
		}
	}
	return 0;
}