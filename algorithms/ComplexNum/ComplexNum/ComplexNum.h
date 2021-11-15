#pragma once
#include <iostream>
class ComplexNum {
 public:
  ComplexNum();
  ComplexNum(double _re);
  ComplexNum(double _re, double _im);
  ComplexNum(const ComplexNum& rv);  // copy

  double getRe() const;
  void setRe(double _re);
  double getIm() const;
  void setIm(double _im);

  double abs() const;
  double arg() const;

  //	ComplexNum operator+();
  ComplexNum operator+(const ComplexNum& rv) const;
  friend ComplexNum operator+(const double, const ComplexNum& rv);
  ComplexNum operator-(const ComplexNum& rv) const;
  friend ComplexNum operator-(const double lv, const ComplexNum& rv);
  ComplexNum operator-() const;
  ComplexNum operator*(const ComplexNum& rv) const;
  friend ComplexNum operator*(const double, const ComplexNum& rv);
  ComplexNum operator/(const ComplexNum& rv) const;
  ComplexNum& operator=(ComplexNum& rv);
  bool operator==(const ComplexNum& rv) const;
  bool operator!=(const ComplexNum& rv) const;
  friend std::ostream& operator<<(std::ostream&, ComplexNum&);
  friend std::istream& operator>>(std::istream&, ComplexNum&);

 private:
  double re_;
  double im_;
};

class ComplexNumPolar {
 public:
  ComplexNumPolar();
  ComplexNumPolar(const ComplexNum& rv);
  ComplexNumPolar(double re);
  ComplexNumPolar(double _r, double _phi);
  ComplexNumPolar(const ComplexNumPolar& rv);  // copy

  double getR() const;
  void setR(double _r);
  double getPhi() const;
  void setPhi(double _phi);
  ComplexNum toComplexNum() const;
  double abs() const;
  double arg() const;

  ComplexNumPolar pow(double a) const;
  ComplexNumPolar sqrt() const;
  ComplexNumPolar& operator=(ComplexNum& rv);
  ComplexNumPolar operator+(const ComplexNumPolar& rv) const;
  friend ComplexNumPolar operator+(const double lv, const ComplexNumPolar& rv);
  ComplexNumPolar operator-(const ComplexNumPolar& rv) const;
  ComplexNumPolar operator-() const;
  friend ComplexNumPolar operator-(const double lv, const ComplexNumPolar& rv);
  ComplexNumPolar operator*(const ComplexNumPolar& rv) const;
  friend ComplexNumPolar operator*(const double lv, const ComplexNumPolar& rv);
  ComplexNumPolar operator/(const ComplexNumPolar& rv) const;
  ComplexNumPolar& operator=(const ComplexNumPolar& rv);
  bool operator==(const ComplexNumPolar& rv) const;
  bool operator!=(const ComplexNumPolar& rv) const;
  friend std::ostream& operator<<(std::ostream&, ComplexNumPolar&);
  friend std::istream& operator>>(std::istream&, ComplexNumPolar&);

 private:
  double r_;
  double phi_;
};
