// trimSpaces1.18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
int main()
{
	char c;
	FILE* fInput = fopen("input.txt", "r");
	FILE* fOut = fopen("output.txt", "w");
	while ((c = fgetc(fInput)) != EOF)
	{
		if (c == ' ' || c == '\t') {
			if (c == '\t') {
				c = ' ';
			}
			fputc(c, fOut);
			while ((c = fgetc(fInput)) != EOF && (c == ' ' || c == '\t'));
		}
		fputc(c,fOut);
	}
	fclose(fInput);
	fclose(fOut);
    return 0;
}

