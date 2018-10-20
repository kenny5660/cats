//#include "stdafx.h"
#include "CppUnitTest.h"

#include"../ComplexNum/ComplexNum.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexNumUnitTests
{		
	TEST_CLASS(ComplexNumTest){
	public:
		
		TEST_METHOD(Constructors_test){
			double re = 12.2;
			double im = -13.5;
			ComplexNum c1(re, im);
			Assert::AreEqual(re, c1.getRe());
			Assert::AreEqual(im, c1.getIm());

			ComplexNum c3(c1);
			Assert::AreEqual(re, c3.getRe());
			Assert::AreEqual(im, c3.getIm());
			double im2 = 10;
			c3.setIm(im2);
			Assert::AreEqual(im2, c3.getIm());
			Assert::AreEqual(im, c1.getIm());

			im = 0;
			ComplexNum c2(re);
			Assert::AreEqual(re, c2.getRe());
			Assert::AreEqual(im, c2.getIm());
		}

		TEST_METHOD(GetRe_GetIm_test){
			double re = 12.2;
			double im = -13.5;
			ComplexNum c1(re, im);
			Assert::AreEqual(re, c1.getRe());
			Assert::AreEqual(im, c1.getIm());
		}

		TEST_METHOD(SetRe_SetIm_test) {
			double re = 12.2;
			double im = -13.5;
			ComplexNum c1;
			c1.setRe(re);
			c1.setIm(im);
			Assert::AreEqual(re, c1.getRe());
			Assert::AreEqual(im, c1.getIm());
		}
		TEST_METHOD(op_pluse_test) {
	
			ComplexNum a(12,-13);
			ComplexNum b(10, 1);
			ComplexNum right_val(22,-12);
			ComplexNum c = a+b;
			
			Assert::IsTrue(right_val == c);
		}
		TEST_METHOD(op_pluse_null_test) {

			ComplexNum a(12, -13);
			ComplexNum b(0);
			ComplexNum right_val(12, -13);
			ComplexNum c = a + b;

			Assert::IsTrue(right_val == c);
		}

		TEST_METHOD(op_sub_test) {

			ComplexNum a(12, -13);
			ComplexNum b(10, 1);
			ComplexNum right_val(2, -14);
			ComplexNum c = a - b;

			Assert::IsTrue(right_val == c);
		}

		TEST_METHOD(op_mul_test) {

			ComplexNum a(12, 6);
			ComplexNum b(3, 2);
			ComplexNum right_val(24, 42);
			ComplexNum c = a * b;

			Assert::IsTrue(right_val == c);
		}

		TEST_METHOD(op_mul_to_null_test) {

			ComplexNum a(12, 6);
			ComplexNum b(0);
			ComplexNum right_val(0, 0);
			ComplexNum c = a * b;

			Assert::IsTrue(right_val == c);
		}

		TEST_METHOD(op_div_test) {

			ComplexNum a(24, 42);
			ComplexNum b(3,2);
			ComplexNum right_val(12, 6);
			ComplexNum c = a / b;

			Assert::IsTrue(right_val == c);
		}

	};
}