#include "pch.h"

#include "ComplexNum.h"

#include <cmath>

ComplexNum::ComplexNum() {}

ComplexNum::ComplexNum(double _re) : re_(_re), im_(0) {}

ComplexNum::ComplexNum(double _re, double _im) : re_(_re), im_(_im) {}

ComplexNum::ComplexNum(const ComplexNum& rv)
    : re_(rv.re_), im_(rv.im_) {}  // copy

double ComplexNum::getRe() const { return re_; }

void ComplexNum::setRe(double _re) { re_ = _re; }

double ComplexNum::getIm() const { return im_; }

void ComplexNum::setIm(double _im) { im_ = _im; }

double ComplexNum::abs() const { return std::sqrt(re_ * re_ + im_ * im_); }
double ComplexNum::arg() const {
  return (re_ > 0 ? 0 : M_PI) + atan(im_ / re_);
}

ComplexNum ComplexNum::operator+(const ComplexNum& rv) const {
  return ComplexNum(re_ + rv.re_, im_ + rv.im_);
}

ComplexNum operator+(const double rv, const ComplexNum& lv) {
  return ComplexNum(lv.re_ + rv, lv.im_);
}

ComplexNum ComplexNum::operator-(const ComplexNum& rv) const {
  return ComplexNum(re_ - rv.re_, im_ - rv.im_);
}

ComplexNum operator-(const double lv, const ComplexNum& rv) {
  return ComplexNum(lv - rv.re_, -rv.im_);
}

ComplexNum ComplexNum::operator-() const { return ComplexNum(-re_, -im_); }

ComplexNum ComplexNum::operator*(const ComplexNum& rv) const {
  return ComplexNum(re_ * rv.re_ - im_ * rv.im_, re_ * rv.im_ + im_ * rv.re_);
}

ComplexNum operator*(const double rv, const ComplexNum& lv) {
  return ComplexNum(lv.re_ * rv, lv.im_ * rv);
}

ComplexNum ComplexNum::operator/(const ComplexNum& rv) const {
  ComplexNum temp;

  double r = rv.re_ * rv.re_ + rv.im_ * rv.im_;
  temp.re_ = (re_ * rv.re_ + im_ * rv.im_) / r;
  temp.im_ = (im_ * rv.re_ - re_ * rv.im_) / r;

  return temp;
}

bool ComplexNum::operator==(const ComplexNum& rv) const {
  return re_ == rv.re_ && im_ == rv.im_;
}

bool ComplexNum::operator!=(const ComplexNum& rv) const {
  return !((*this) == rv);
}

ComplexNum& ComplexNum::operator=(ComplexNum& rv) {
  re_ = rv.re_;
  im_ = rv.im_;
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
    : phi_(rv.phi_), r_(rv.r_) {}

ComplexNumPolar::ComplexNumPolar(double _r, double _phi) : phi_(_phi), r_(_r) {}

ComplexNumPolar::ComplexNumPolar(double re) : ComplexNumPolar(ComplexNum(re)) {}

ComplexNumPolar::ComplexNumPolar(const ComplexNum& rv)
    : r_(std::sqrt(rv.getRe() * rv.getRe() + rv.getIm() * rv.getIm())),
      phi_((rv.getRe() > 0 ? 0 : M_PI) + atan(rv.getIm() / rv.getRe())) {}

double ComplexNumPolar::getR() const { return r_; }

void ComplexNumPolar::setR(double _r) { r_ = _r; }

double ComplexNumPolar::getPhi() const { return phi_; }

void ComplexNumPolar::setPhi(double _phi) { phi_ = _phi; }

double ComplexNumPolar::abs() const { return r_; }
double ComplexNumPolar::arg() const { return phi_; }

ComplexNum ComplexNumPolar::toComplexNum() const {
  return ComplexNum(cos(phi_) * r_, sin(phi_) * r_);
}

ComplexNumPolar ComplexNumPolar::sqrt() const {
  return ComplexNumPolar(std::sqrt(r_), phi_ / 2);
}

ComplexNumPolar ComplexNumPolar::pow(double a) const {
  return ComplexNumPolar(std::pow(r_, a), phi_ * a);
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
  return ComplexNumPolar(r_ * rv.r_, phi_ + rv.phi_);
}

ComplexNumPolar operator*(const double lv, const ComplexNumPolar& rv) {
  return ComplexNumPolar(rv.r_ * lv, rv.phi_);
}

ComplexNumPolar ComplexNumPolar::operator/(const ComplexNumPolar& rv) const {
  return ComplexNumPolar(r_ / rv.r_, phi_ - rv.phi_);
}

ComplexNumPolar& ComplexNumPolar::operator=(const ComplexNumPolar& rv) {
  r_ = rv.r_;
  phi_ = rv.phi_;
  return (*this);
}

ComplexNumPolar& ComplexNumPolar::operator=(ComplexNum& rv) {
  ComplexNumPolar temp(rv);
  r_ = temp.r_;
  phi_ = temp.phi_;
  return (*this);
}

bool ComplexNumPolar::operator==(const ComplexNumPolar& rv) const {
  return r_ == rv.r_ && phi_ == rv.phi_;
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
