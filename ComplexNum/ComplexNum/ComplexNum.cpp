#include "pch.h"

#include "ComplexNum.h"

#include <cmath>

ComplexNum::ComplexNum() {}

ComplexNum::ComplexNum(double _re) : re(_re), im(0) {}

ComplexNum::ComplexNum(double _re, double _im) : re(_re), im(_im) {}

ComplexNum::ComplexNum(const ComplexNum& rv) : re(rv.re), im(rv.im) {  // copy
}

double ComplexNum::getRe() const { return re; }

void ComplexNum::setRe(double _re) { re = _re; }

double ComplexNum::getIm() const { return im; }

void ComplexNum::setIm(double _im) { im = _im; }

ComplexNum ComplexNum::operator+(const ComplexNum& rv) const {
  return ComplexNum(re + rv.re, im + rv.im);
}

ComplexNum operator+(const double rv, const ComplexNum& lv) {
  return ComplexNum(lv.re + rv, lv.im);
}

ComplexNum ComplexNum::operator-(const ComplexNum& rv) const {
  return ComplexNum(re - rv.re, im - rv.im);
}

ComplexNum operator-(const double lv, const ComplexNum& rv) {
  return ComplexNum(lv - rv.re, -rv.im);
}

ComplexNum ComplexNum::operator-() const { return ComplexNum(-re, -im); }

ComplexNum ComplexNum::operator*(const ComplexNum& rv) const {
  return ComplexNum(re * rv.re - im * rv.im, re * rv.im + im * rv.re);
}

ComplexNum operator*(const double rv, const ComplexNum& lv) {
  return ComplexNum(lv.re * rv, lv.im * rv);
}

ComplexNum ComplexNum::operator/(const ComplexNum& rv) const {
  ComplexNum temp;

  double r = rv.re * rv.re + rv.im * rv.im;
  temp.re = (re * rv.re + im * rv.im) / r;
  temp.im = (im * rv.re - re * rv.im) / r;

  return temp;
}

bool ComplexNum::operator==(const ComplexNum& rv) const {
  return re == rv.re && im == rv.im;
}

bool ComplexNum::operator!=(const ComplexNum& rv) const {
  return !((*this) == rv);
}

ComplexNum& ComplexNum::operator=(ComplexNum& rv) {
  re = rv.re;
  im = rv.im;
  return (*this);
}

std::ostream& operator<<(std::ostream& out, ComplexNum& rv) {
  double Im = rv.getIm();
  out << rv.getRe() << (Im < 0 ? "-" : "+") << (Im < 0 ? -Im : Im) << "i";
  return out;
}

std::istream& operator>>(std::istream& in, ComplexNum& rv) {
  double re;
  double im;
  in >> re >> im;
  rv.setRe(re);
  rv.setIm(im);
  return in;
}

// ComplexNum

ComplexNumPolar::ComplexNumPolar() {}

ComplexNumPolar::ComplexNumPolar(const ComplexNumPolar& rv)
    : phi(rv.phi), r(rv.r) {}

ComplexNumPolar::ComplexNumPolar(double _r, double _phi) : phi(_phi), r(_r) {}

ComplexNumPolar::ComplexNumPolar(double re) : ComplexNumPolar(ComplexNum(re)) {}

ComplexNumPolar::ComplexNumPolar(const ComplexNum& rv)
    : r(std::sqrt(rv.getRe() * rv.getRe() + rv.getIm() * rv.getIm())),
      phi((rv.getRe() > 0 ? 0 : M_PI) + atan(rv.getIm() / rv.getRe())) {}

double ComplexNumPolar::getR() const { return r; }

void ComplexNumPolar::setR(double _r) { r = _r; }

double ComplexNumPolar::getPhi() const { return phi; }

void ComplexNumPolar::setPhi(double _phi) { phi = _phi; }

ComplexNum ComplexNumPolar::toComplexNum() const {
  return ComplexNum(cos(phi) * r, sin(phi) * r);
}

ComplexNumPolar ComplexNumPolar::sqrt() const {
  return ComplexNumPolar(std::sqrt(r), phi / 2);
}

ComplexNumPolar ComplexNumPolar::pow(double a) const {
  return ComplexNumPolar(std::pow(r, a), phi * a);
}

ComplexNumPolar ComplexNumPolar::operator+(const ComplexNumPolar& rv) const {
  return ComplexNumPolar(toComplexNum() + rv.toComplexNum());
}

ComplexNumPolar operator+(const double lv, const ComplexNumPolar& rv) {
  return ComplexNumPolar(lv + rv.toComplexNum());
}

ComplexNumPolar ComplexNumPolar::operator-(const ComplexNumPolar& rv) const {
  return ComplexNumPolar(toComplexNum() - rv.toComplexNum());
}

ComplexNumPolar ComplexNumPolar::operator-() const {
  ComplexNum c = (-toComplexNum());
  return ComplexNumPolar(c);
}

ComplexNumPolar operator-(const double lv, const ComplexNumPolar& rv) {
  return ComplexNumPolar(lv - rv.toComplexNum());
}

ComplexNumPolar ComplexNumPolar::operator*(const ComplexNumPolar& rv) const {
  return ComplexNumPolar(r * rv.r, phi + rv.phi);
}

ComplexNumPolar operator*(const double lv, const ComplexNumPolar& rv) {
  return ComplexNumPolar(rv.r * lv, rv.phi);
}

ComplexNumPolar ComplexNumPolar::operator/(const ComplexNumPolar& rv) const {
  return ComplexNumPolar(r / rv.r, phi - rv.phi);
}

ComplexNumPolar& ComplexNumPolar::operator=(ComplexNumPolar& rv) {
  r = rv.r;
  phi = rv.phi;
  return (*this);
}

ComplexNumPolar& ComplexNumPolar::operator=(ComplexNum& rv) {
  ComplexNumPolar temp(rv);
  r = temp.r;
  phi = temp.phi;
  return (*this);
}

bool ComplexNumPolar::operator==(const ComplexNumPolar& rv) const {
  return r == rv.r && phi == rv.phi;
}

bool ComplexNumPolar::operator!=(const ComplexNumPolar& rv) const {
  return !((*this) == rv);
}

std::ostream& operator<<(std::ostream& out, ComplexNumPolar& rv) {
  double phi = rv.getPhi() * 180 / M_PI;
  out << rv.getR() << "(cos(" << phi << ")+"
      << "isin(" << phi << "))";
  return out;
}

std::istream& operator>>(std::istream& in, ComplexNumPolar& rv) {
  double r;
  double phi;
  in >> r >> phi;
  rv.setR(r);
  rv.setPhi(phi);
  return in;
}
