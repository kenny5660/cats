#include "pch.h"
#include <iostream>

#include"ComplexNum.h"

int main()
{
	ComplexNumPolar zP(10, 1.2);
	ComplexNumPolar zP2(12, 1.3);
	ComplexNum zP3 = zP + zP2;
	std::cout << zP3 <<" " << zP << std::endl;
}
