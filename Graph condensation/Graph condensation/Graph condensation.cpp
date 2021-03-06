// Graph condensation.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include<fstream>
#include <algorithm>
#pragma comment(linker, "/STACK:6437184")
using namespace std;

const int white = 0;
const int grey = 1;
const int black = 2;

typedef vector<vector<int>> graph;
typedef vector<int>Component_t;
graph G, Gt;

void topologic_sort_rec(graph &g, vector<int> &stack_tp, vector<uint8_t> &used, int node) {
	used[node] = grey;
	for (int i = 0; i < g[node].size(); ++i) {
		if (used[g[node][i]] == white) {
			topologic_sort_rec(g, stack_tp, used, g[node][i]);
		}
	}
	used[node] = black;
	stack_tp.push_back(node);
}

void topologic_sort(graph &g, vector<int> &stack_tp, int S) {
	vector<uint8_t>  used(G.size(), white);
	topologic_sort_rec(g, stack_tp, used, S);
	for (int i = 0; i < used.size(); ++i) {
		if (used[i] == white) {
			topologic_sort_rec(g, stack_tp, used, i);
		}
	}
}

void Get_Componets(graph &g, vector<vector<int>> &Cs, vector<int> &order) {
	vector<uint8_t>  used(G.size(), white);
	vector<int> C;
	for (int i = 0; i < order.size(); ++i) {
		int v = order[order.size() - 1 - i];
		if (!used[v]) {
			topologic_sort_rec(g, C, used, v);
			Cs.push_back(C);
			C.clear();
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
	Gt.resize(N);
	int St, End;
	for (int i = 0; i < M; ++i) {
		input >> St >> End;
		G[St - 1].push_back(End - 1);
		Gt[End - 1].push_back(St - 1);
	}
	vector<int> order;
	topologic_sort(G, order, 0);

	vector<vector<int>> Cs;
	Get_Componets(Gt, Cs, order);

	vector<int> answ(N);
	for (int i = 0; i < Cs.size(); i++) {
		for (int j = 0; j < Cs[i].size(); j++) {
			answ[Cs[i][j]] = i + 1;
		}
	}

	output << Cs.size() << endl;
	for (int i = 0; i < answ.size(); ++i) {
		output << answ[i] << " ";
	}
	return 0;
}