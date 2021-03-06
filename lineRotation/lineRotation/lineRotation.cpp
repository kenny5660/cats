// lineRotation.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
struct point {
	double x;
	double y;
};

point rotate_point(point a, point O, double angle) {
	point c = a;
	double phi = angle * M_PI / 180;
	c.x = (a.x - O.x)*cos(phi) - (a.y - O.y)*sin(phi) + O.x;
	c.y = (a.x - O.x)*sin(phi) + (a.y - O.y) *cos(phi) + O.y;
	return c;
}

int main()
{
	ifstream input("input.txt");
	freopen("output.txt", "w", stdout);
	point a, b, O;
	double angle;
	input >> a.x >> a.y >> b.x >> b.y >> O.x >> O.y >> angle;
	a = rotate_point(a, O, angle);
	b = rotate_point(b, O, angle);

	printf("%.3lf %.3lf %.3lf %.3lf", a.x, a.y, b.x, b.y);
	return 0;
}