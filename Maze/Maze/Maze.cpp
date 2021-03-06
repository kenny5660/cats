// Maze.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include<fstream>
#include <algorithm>
#include <queue>
using namespace std;

typedef vector<vector<uint8_t>> graph;
typedef struct point_t
{
	int x;
	int y;
};

graph maze;
point_t p_start, p_end;
point_t ways_edges[4] = { {0,1},{1,0},{0,-1} ,{-1,0} };

int main() {
	ifstream input("input.txt");
	ofstream output("output.txt");
	int N;//vertices
	input >> N >> p_start.x >> p_start.y >> p_end.x >> p_end.y;
	p_start.x--;
	p_start.y--;
	p_end.x--;
	p_end.y--;
	maze.resize(N);
	char ch;
	for (int i = 0; i < N; ++i) {
		maze[i].resize(N);
		for (int j = 0; j < N; ++j) {
			input >> ch;
			maze[i][j] = ch == '.' ? 1 : 0;
		}
	}
	if (N == 0) {
		output << 0;
		return 0;
	}
	vector<vector<bool>> used(N, vector<bool>(N, 0));
	vector<vector<int>> d(N, vector<int>(N, 0));
	queue<point_t> q;
	q.push(p_start);
	used[p_start.y][p_start.x] = true;

	while (!q.empty()) {
		point_t p_cur = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			point_t p_near = { p_cur.x + ways_edges[i].x ,p_cur.y + ways_edges[i].y };

			if (p_near.x < N && p_near.y < N && p_near.x >= 0 && p_near.y >= 0) {
				if (maze[p_near.y][p_near.x] == 1 && !used[p_near.y][p_near.x]) {
					used[p_near.y][p_near.x] = true;
					q.push(p_near);
					d[p_near.y][p_near.x] = d[p_cur.y][p_cur.x] + 1;

					if (p_near.x == p_end.x && p_near.y == p_end.y) {
						output << d[p_end.y][p_end.x];
						return 0;
					}
				}
			}
		}
	}
	return 0;
}