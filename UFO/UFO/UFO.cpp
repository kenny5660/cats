// UFO.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	double a, b;
	input >> a >> b;
	double x;
	double y;
	int signA = 1;
	signA = a >= 180 ? signA * -1 : signA;
	int signB = 1;
	signB = b >= 180 ? signB * -1 : signB;
	int sign = 1;
	sign = signA < 0 && signB < 0 ? -1 : 1;

	if (a == 90) {
		x = 0;
		y = tan(b* M_PI / 180)*-100;
	}
	else {
		if (b == 90) {
			x = 100;
			y = tan(a* M_PI / 180) * 100;
		}
		else {
			double k1 = tan(a* M_PI / 180);
			double	k2 = tan(b* M_PI / 180);
			double	b2 = k2 * (-100);

			x = b2 / (k1 - k2);
			y = k1 * x * sign;
		}
	}

	if (a == b || (signA*signB) < 0 || y < 0) {
		output << "0 0";
	}
	else {
		output << x << " " << y * sign;
	}
	return 0;
}