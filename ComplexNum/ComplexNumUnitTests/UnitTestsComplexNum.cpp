#include "!stdafx.h"
#include "../ComplexNum/ComplexNum.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsComplexNum {
TEST_CLASS(ComplexNumTest){public :

                               TEST_METHOD(Constructors_test){double re = 12.2;
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

TEST_METHOD(GetRe_GetIm_test) {
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
  ComplexNum a(12, -13);
  ComplexNum b(10, 1);
  ComplexNum right_val(22, -12);
  ComplexNum c = a + b;

  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_pluse_null_test) {
  ComplexNum a(12, -13);
  ComplexNum b(0);
  ComplexNum right_val(12, -13);
  ComplexNum c = a + b;

  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_pluse_double_test) {
  ComplexNum a(12, -13);
  ComplexNum right_val(24.7, -13);
  ComplexNum c = a + 12.7;
  Assert::IsTrue(right_val == c);
}


TEST_METHOD(op_sub_test) {
  ComplexNum a(12, -13);
  ComplexNum b(10, 1);
  ComplexNum right_val(2, -14);
  ComplexNum c = a - b;

  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_sub_double_test) {
  ComplexNum a(12, -13);
  ComplexNum right_val(0.5, -13);
  ComplexNum c = a - 11.5;
  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_sub_double_lv_test) {
  ComplexNum a(12, -13);
  ComplexNum right_val(-0.5, 13);
  ComplexNum c = 11.5-a;
  Assert::IsTrue(right_val == c);
}
TEST_METHOD(op_sub_double_unar_test) {
  ComplexNum a(12, -13);
  ComplexNum right_val(-0.5, 13);
  ComplexNum c = 11.5 +(-a);
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

TEST_METHOD(op_mul_to_double_test) {
  ComplexNum a(12, -13);
  ComplexNum right_val(30, -32.5);
  ComplexNum c = 2.5 * a;
  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_div_test) {
  ComplexNum a(24, 42);
  ComplexNum b(3, 2);
  ComplexNum right_val(12, 6);
  ComplexNum c = a / b;

  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_div_double_test) {
  ComplexNum a(24, 42);
  ComplexNum right_val(9.6, 16.8);
  ComplexNum c = a / 2.5;
  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_equality_test) {
    
    ComplexNum a(24, 42); 
    ComplexNum b(24, 42); 
    ComplexNum c(24, -42); 
    Assert::IsTrue(a == b);
    Assert::IsFalse(a == c);
    Assert::IsTrue(a != c);
    Assert::IsFalse(a != b);
}

TEST_METHOD(op_assignment_test) {
  double re = 12.2;
  double im = -13.5;
  ComplexNum c1(re, im);
  Assert::AreEqual(re, c1.getRe());
  Assert::AreEqual(im, c1.getIm());

  ComplexNum c3(10,10);
  c3 = c1;
  Assert::AreEqual(re, c3.getRe());
  Assert::AreEqual(im, c3.getIm());
  double im2 = 10;
  c3.setIm(im2);
  Assert::AreEqual(im2, c3.getIm());
  Assert::AreEqual(im, c1.getIm());
}
TEST_METHOD(stdcout_minus_i_test) {
  std::string right_val = "12.2-13.5i";
  ComplexNum c1(12.2, -13.5);
  std::stringstream str_stream;
  str_stream << c1;
  Assert::AreEqual(right_val, str_stream.str());
}
TEST_METHOD(stdcout_test) {
  std::string right_val = "12.2+13.5i";
  ComplexNum c1(12.2, 13.5);
  std::stringstream str_stream;
  str_stream << c1;
  Assert::AreEqual(right_val, str_stream.str());
}
TEST_METHOD(stdcin_test)  {
  double re_right = 12.2;
  double im_right = -13.5;
  ComplexNum c1;
  std::stringstream str_stream;
  str_stream << "12.2 -13.5";
  str_stream >> c1;
  Assert::AreEqual(re_right, c1.getRe());
  Assert::AreEqual(im_right, c1.getIm());
}
}
;
}  // namespace ComplexNumUnitTests