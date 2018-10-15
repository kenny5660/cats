#include "stdafx.h"
#include "CppUnitTest.h"
#include"../ComplexNum/ComplexNum.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexNumUnitTests
{		
	TEST_CLASS(ComplexNumTest)
	{
	public:
		
		TEST_METHOD(Constructors_test)
		{
			double re = 12.2;
			double im = -13.5;
			ComplexNum c1(re, im);
			Assert::AreEqual(re, c1.getRe());
			Assert::AreEqual(im, c1.getIm());

			im = 0;
			ComplexNum c2(re);
			Assert::AreEqual(re, c2.getRe());
			Assert::AreEqual(im, c2.getIm());
		}

	};
}