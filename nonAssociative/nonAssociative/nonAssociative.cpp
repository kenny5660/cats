// nonAssociative.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdio.h>
#include <math.h>

int f(int a, int b) {
	return abs(a - b);
}
int main()
{
	int a = 10;
	int b = 22;
	int c = 15;

	printf("f(a,b) = %d\n",f(a,b));
	printf("f(b,a) = %d\n", f(b, a));
	printf("commutativity, but \n");

	printf("f(f(a, b),c) = %d\n", f(f(a, b),c));
	printf("f(f(a,c),b) = %d\n", f(f(a, c), b));
	printf("non Associative \n");
	getchar();

	return 0;
}

