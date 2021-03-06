#include "stdafx.h"
#include <stdio.h>
#include <list>
#include<iterator>
using namespace std;

const int TABLE_SIZE  = 1057; // simple number
const double hkoef = 0.618033;
list<int> hash_tabel[TABLE_SIZE];

void add_to_hash_table(int a);
void del_from_hash_table(int a);
void print_table(FILE* f_out);
int hash_(int a);
void free_hash_table();

int main()
{
	int a;
	FILE* fInput;
	//fInput = fopen("input.txt", "w");
	//for (int i = 0; i < 1000000; i++) {

	//	fprintf(fInput, "%d ", (rand() - 1000) % 100000);
	//	//fprintf(fInput, "%d ", -rand());
	//}
	//fprintf(fInput, "%d", 0);
	//fclose(fInput);
	fInput = fopen("input.txt", "r");
	FILE* fOut = fopen("output.txt", "w");
		fscanf(fInput, "%d", &a);
		while (a != 0)
		{
			if (a > 0) {
				add_to_hash_table(a);
			}
			else
			{
				del_from_hash_table(-a);
			}
			fscanf(fInput, "%d", &a);
		}
		print_table(fOut);
	fclose(fInput);
	fclose(fOut);


    return 0;
}

//int hash_(int a) { 
//	return (int)(TABLE_SIZE * fmod(a*hkoef, 1)); 
//}
int hash_(int a) {
		return a % TABLE_SIZE;
}

void add_to_hash_table(int a) {
	int _hash = hash_(a);
	if (!hash_tabel[_hash].empty()) {
		list<int>::iterator it = hash_tabel[_hash].begin();
		list<int>::iterator it_end = hash_tabel[_hash].end();
		while (it != it_end)
		{
			if (*it == a) {
				return;
			}
			++it;
		}
		hash_tabel[_hash].push_front(a);
	}
	else
	{
		hash_tabel[_hash].push_front(a);
	}
}

void del_from_hash_table(int a) {
	int _hash = hash_(a);
	if (!(hash_tabel[_hash].empty())) {
		list<int>::iterator it = hash_tabel[_hash].begin();
		list<int>::iterator it_end = hash_tabel[_hash].end();
		while (it != it_end)
		{
			if (*it == a) {
			  hash_tabel[_hash].erase(it);
			break;
			}
			++it;
		}
	}
}
void print_table(FILE* f_out) {
	list<int> all_hash_tabel;
	for (int i = 0; i < TABLE_SIZE;++i) {
		if (!hash_tabel[i].empty()) {
			all_hash_tabel.insert(all_hash_tabel.end(),hash_tabel[i].begin(), hash_tabel[i].end());
		}
	}
	all_hash_tabel.sort();
	list<int>::iterator it = all_hash_tabel.begin();
	list<int>::iterator it_end = all_hash_tabel.end();
	while (it != it_end)
	{
		fprintf(f_out, "%d ", *it);
		++it;
	}
	all_hash_tabel.clear();
}
void free_hash_table() {
	for (int i = 0; i < TABLE_SIZE; ++i) {
		hash_tabel[i].clear();
	}
}