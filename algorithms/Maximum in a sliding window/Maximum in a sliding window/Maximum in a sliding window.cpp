// Maximum in a sliding window.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include <stack>
#include <algorithm>
using namespace std;

stack<pair<int, int>> L_stack;
stack<pair<int, int>> R_stack;
int N;
int* m;
char offset;
int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	input >> N;
	m = new int[N];

	for (int i = 0; i < N; ++i)
	{
		input >> m[i];
	}
	
	int j = 1;
	L_stack.push(make_pair(m[0], m[0]));
	 input >> N;
	 for (int i = 0; i < N; ++i)
	 {
		 input >> offset;
		 if (offset == 'R') {
			 if (!L_stack.empty()) {
				 L_stack.push(make_pair(m[j], max(m[j], L_stack.top().second)));
			 }
			 else {
				 L_stack.push(make_pair(m[j], m[j]));
			 }
			 j++;
		 }
		 else
		 {
			 if (R_stack.empty()) {
				 while (!L_stack.empty())
				 {
					 if (!R_stack.empty()) {
						 R_stack.push(make_pair(L_stack.top().first, max(L_stack.top().first, R_stack.top().second)));
					 }
					 else {
						 R_stack.push(make_pair(L_stack.top().first, L_stack.top().first));
					 }
			
					 L_stack.pop();
				 }
			 }
			 R_stack.pop();
		 }
		 if (L_stack.empty()) {
			 output << R_stack.top().second << " ";
			 continue;
		 }
		 if (R_stack.empty()) {
			 output << L_stack.top().second << " ";
		 }
		 else
		 {
			 output << max(R_stack.top().second, L_stack.top().second) << " ";
		 }
		
	 }
    return 0;
}

