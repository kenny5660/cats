#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare(const void * x1, const void * x2);
int compare_r(const void* x1, const void* x2);
bool read_string(char** data, FILE* file);
int main(int argc, char* argv[])
{
	FILE* f_input;
	char** str_input;
	const int lines_buf_size_increment = 10000;
    int lines_buf_size = 10000;
	int lines = 0;
	int(*comparator)(const void*, const void*) = compare;
	if (argc > 1) {
		for (int i = 0; i < argc - 1; ++i) {
			if (strcmp(argv[i], "-r")) {
				comparator = compare_r;
			}
		}
		f_input = fopen(argv[argc-1], "r");
	}
	else
	{
		return -1;
	}
	str_input = (char**)malloc(lines_buf_size * sizeof(char*));
	while (read_string(&(str_input[lines]),f_input))
	{
		lines++;
		if (lines >= lines_buf_size) {
			lines_buf_size += lines_buf_size_increment;
			str_input = (char**)realloc(str_input,lines_buf_size * sizeof(char*));
		}
	}
	lines++;
	qsort(str_input,lines,sizeof(char**),comparator);
	for (int i = 0; i < lines; ++i) {
		fputs(str_input[i], stdout);
	}

	for (int i = 0; i < lines; ++i) {
		free(str_input[i]);
	}
	free(str_input);
	fclose(f_input);
    return 0;
}

bool read_string(char** data, FILE* file) {
	const int str_buf_size_inc = 10000;
	int str_buf_size = 10000;
	int  i = 0;
	char *string = *data;
	char c;
	string = (char*)malloc(str_buf_size * sizeof(char));
	while ((c = fgetc(file)) != '\n') {
		if (c == EOF) { 
			string[i] = '\0';
			*data = string;
			return false; 
		}
		if (i >= str_buf_size-2) {
			str_buf_size += str_buf_size_inc;
			string = (char*)realloc(string, str_buf_size);
		}
		string[i] = c;
		++i;
	}
	string[i] = '\n';
	string[i+1] = '\0';
	*data = string;
	return true;
}
// strcmp
int compare(const void* x1, const void* x2)
{
	char*  a = (*((char**)x1));
	char*  b = (*((char**)x2));
	int i;
	for (i = 0; a[i] != '\0' && b[i] != '\0' && a[i]==b[i]; ++i);
	return a[i] - b[i];
}

int compare_r(const void* x1, const void* x2)
{
	char*  a = (*((char**)x1));
	char*  b = (*((char**)x2));
	int i;
	for (i = 0; a[i] != '\0' && b[i] != '\0' && a[i] == b[i]; ++i);
	return b[i] - a[i];
}