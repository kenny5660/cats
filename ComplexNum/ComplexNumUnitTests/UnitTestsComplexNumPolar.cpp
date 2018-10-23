#include "!stdafx.h"
#include "../ComplexNum/ComplexNum.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestsComplexNumPolar {
TEST_CLASS(ComplexNumPolarTest){
  public :

      TEST_METHOD(Constructors_test){double r = 12.2;
double phi = 3.14;
ComplexNumPolar c1(r, phi);
Assert::AreEqual(r, c1.getR());
Assert::AreEqual(phi, c1.getPhi());

ComplexNumPolar c3(c1);
Assert::AreEqual(r, c3.getR());
Assert::AreEqual(phi, c3.getPhi());
double r2 = 10;
c3.setR(r2);
Assert::AreEqual(r2, c3.getR());
Assert::AreEqual(r, c1.getR());

ComplexNumPolar c2(0);
Assert::AreEqual(0.0, c2.getR());
Assert::IsTrue(isnan(c2.getPhi()));

ComplexNum a(3, 3);
ComplexNumPolar c4(a);
c4.setR(std::round(c4.getR() * 100) / 100);
c4.setPhi(std::round(c4.getPhi() * 100) / 100);
Assert::IsTrue(c4 == ComplexNumPolar(4.24, 0.79));
}  // namespace UnitTestsComplexNumPolar

TEST_METHOD(GetR_GetPhi_test) {
  ComplexNum c1(12.2, -2.5);
  Assert::AreEqual(12.2, c1.getRe());
  Assert::AreEqual(-2.5, c1.getIm());
}

TEST_METHOD(SetRe_SetIm_test) {
  ComplexNumPolar c1;
  c1.setR(13.5);
  c1.setPhi(-1);
  Assert::AreEqual(13.5, c1.getR());
  Assert::AreEqual(-1.0, c1.getPhi());
}

TEST_METHOD(pow_test) {
  ComplexNumPolar c1(2, 10);
  Assert::IsTrue((c1 * c1 * c1) == c1.pow(3));
}

TEST_METHOD(sqrt_test) {
  ComplexNumPolar c1(4, 10);
  Assert::IsTrue(ComplexNumPolar(2, 5) == c1.sqrt());
}

TEST_METHOD(toComplexNum_test) {
  ComplexNum a(12, -13);
  Assert::IsTrue(ComplexNumPolar(a).toComplexNum() == a);
}

TEST_METHOD(op_pluse_test) {
  ComplexNum a(12, -13);
  ComplexNum b(1, 1);
  ComplexNum right_val(13, -12);
  ComplexNum c = (ComplexNumPolar(a) + ComplexNumPolar(b)).toComplexNum();

  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_pluse_null_test) {
  ComplexNum a(12, -13);
  ComplexNum b(0);
  ComplexNum right_val(12, -13);
  ComplexNum c = (ComplexNumPolar(a) + ComplexNumPolar(b)).toComplexNum();

  Assert::IsTrue(isnan(c.getRe()));
  Assert::IsTrue(isnan(c.getIm()));
}

TEST_METHOD(op_pluse_double_test) {
  ComplexNum a(12, -13);
  ComplexNum right_val(24.7, -13);
  ComplexNum c = (ComplexNumPolar(a) + 12.7).toComplexNum();
  c.setRe(std::round(c.getRe() * 100) / 100);
  c.setIm(std::round(c.getIm() * 100) / 100);
  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_sub_test) {
  ComplexNum a(12, -13);
  ComplexNum b(1, 1);
  ComplexNum right_val(11, -14);
  ComplexNum c = (ComplexNumPolar(a) - ComplexNumPolar(b)).toComplexNum();
  c.setRe(std::round(c.getRe() * 100) / 100);
  c.setIm(std::round(c.getIm() * 100) / 100);
  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_sub_double_test) {
  ComplexNum a(12, -13);
  ComplexNum right_val(0.5, -13);
  ComplexNum c = (ComplexNumPolar(a) - 11.5).toComplexNum();
  c.setRe(std::round(c.getRe() * 100) / 100);
  c.setIm(std::round(c.getIm() * 100) / 100);
  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_sub_double_lv_test) {
  ComplexNum a(12, -13);
  ComplexNum right_val(-0.5, 13);
  ComplexNum c = (11.5 - ComplexNumPolar(a)).toComplexNum();
  c.setRe(std::round(c.getRe() * 100) / 100);
  c.setIm(std::round(c.getIm() * 100) / 100);
  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_sub_double_unar_test) {
  ComplexNum a(12, -13);
  ComplexNum right_val(-0.5, 13);
  ComplexNum c = (11.5 + (-ComplexNumPolar(a))).toComplexNum();
  c.setRe(std::round(c.getRe() * 100) / 100);
  c.setIm(std::round(c.getIm() * 100) / 100);
  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_mul_test) {
  ComplexNumPolar a(12, 6);
  ComplexNumPolar b(3, 2);
  ComplexNumPolar right_val(36, 8);
  ComplexNumPolar c = a * b;
  ComplexNum a1 = a.toComplexNum();
  ComplexNum b1 = b.toComplexNum();
  ComplexNum c1 = a1 * b1;
  ComplexNum c2 = c.toComplexNum();
  c1.setRe(std::round(c1.getRe() * 100) / 100);
  c1.setIm(std::round(c1.getIm() * 100) / 100);
  c2.setRe(std::round(c2.getRe() * 100) / 100);
  c2.setIm(std::round(c2.getIm() * 100) / 100);
  Assert::IsTrue(right_val == c);
  Assert::IsTrue(c2 == c1);
}

TEST_METHOD(op_mul_to_null_test) {
  ComplexNum a(12, 6);
  ComplexNum b(0);
  ComplexNum right_val(0, 0);
  ComplexNum c = (ComplexNumPolar(a) * ComplexNumPolar(b)).toComplexNum();
  Assert::IsTrue(isnan(c.getRe()));
}

TEST_METHOD(op_mul_to_double_test) {
  ComplexNumPolar a(12, -13);
  ComplexNumPolar right_val(30, -13);
  ComplexNumPolar c = 2.5 * a;
  c.setR(std::round(c.getR() * 100) / 100);
  c.setPhi(std::round(c.getPhi() * 100) / 100);
  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_div_test) {
  ComplexNumPolar a(24, 42);
  ComplexNumPolar b(3, 2);
  ComplexNumPolar right_val(8, 40);
  ComplexNumPolar c = a / b;

  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_div_double_test) {
  ComplexNumPolar a(25, 42);
  ComplexNumPolar right_val(10, 42);
  ComplexNumPolar c = a / 2.5;

  Assert::IsTrue(right_val == c);
}

TEST_METHOD(op_assignment_test) {
  double r = 12.2;
  double phi = -13.5;
  ComplexNumPolar c1(r, phi);
  Assert::AreEqual(r, c1.getR());
  Assert::AreEqual(phi, c1.getPhi());

  ComplexNumPolar c3(10, 10);
  c3 = c1;
  Assert::AreEqual(r, c3.getR());
  Assert::AreEqual(phi, c3.getPhi());
  double r2 = 10;
  c3.setR(r2);
  Assert::AreEqual(r2, c3.getR());
  Assert::AreEqual(phi, c1.getPhi());

  ComplexNum c4(12, 12);
  c3 = c4;
  ComplexNum c3notPolar = c3.toComplexNum();
  c3notPolar.setRe(std::round(c3notPolar.getRe() * 100) / 100);
  c3notPolar.setIm(std::round(c3notPolar.getIm() * 100) / 100);
  Assert::IsTrue(c3notPolar == c4);
}
TEST_METHOD(stdcout_test) {
  std::string right_val = "12.2(cos(-773.493)+isin(-773.493))";
  ComplexNumPolar c1(12.2, -13.5);
  std::stringstream str_stream;
  str_stream << c1;
  Assert::AreEqual(right_val, str_stream.str());
}

TEST_METHOD(op_equality_test) {
  ComplexNumPolar a(24, 42);
  ComplexNumPolar b(24, 42);
  ComplexNumPolar c(24, -42);
  Assert::IsTrue(a == b);
  Assert::IsFalse(a == c);
  Assert::IsTrue(a != c);
  Assert::IsFalse(a != b);
}

TEST_METHOD(stdcin_test) {
  double re_right = 12.2;
  double im_right = -13.5;
  ComplexNumPolar c1;
  std::stringstream str_stream;
  str_stream << "12.2 -13.5";
  str_stream >> c1;
  Assert::AreEqual(re_right, c1.getR());
  Assert::AreEqual(im_right, c1.getPhi());
}
}
;
}  // namespace ComplexNumUnitTests