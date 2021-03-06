// CircleCollision.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	double R, x1, y1, dx1, dy1, dx2, dy2, x2, y2;
	input >> R >> x1 >> y1 >> dx1 >> dy1 >> x2 >> y2 >> dx2 >> dy2;
	double t1, t2;
	//(dx1-dx2)^2T^2+((x1 - x2) * (dx1 - dx2) + (y1 - y2) * (dy1 - dy2))T + (x1 - x2)^2 + (y1 - y2)^2 - 4 * r * r = 0;
	double a = (dx1 - dx2)*(dx1 - dx2) + (dy1 - dy2)*(dy1 - dy2);
	double b = (x1 - x2) * (dx1 - dx2) + (y1 - y2) * (dy1 - dy2);
	double c = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) - 4 * R * R;
	double D = 4 * b*b - 4 * a*c;
	if (D >= 0) {
		t1 = (-b + sqrt(b*b - a*c)) / a;
		t2 = (-b - sqrt(b*b - a*c)) / a;
		if (min(t1, t2) > 0) {
			output << setprecision(8)<< min(t1, t2);
		}
		else
		{
			output << "-1";
		}
	}
	else
	{
		output << "-1";
	}


	return 0;
}

