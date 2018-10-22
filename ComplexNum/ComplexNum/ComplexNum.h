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

  //	ComplexNum operator+();
  ComplexNum operator+(const ComplexNum& rv);
  friend ComplexNum operator+(const double, const ComplexNum& rv);
  ComplexNum operator-(const ComplexNum& rv);
  friend ComplexNum operator-(const double lv, const ComplexNum& rv);
  ComplexNum operator-();
  ComplexNum operator*(const ComplexNum& rv);
  friend ComplexNum operator*(const double, const ComplexNum& rv);
  ComplexNum operator/(const ComplexNum& rv);
  ComplexNum& operator=(ComplexNum& rv);
  bool operator==(const ComplexNum& rv);
  bool operator!=(const ComplexNum& rv);
  friend std::ostream& operator<<(std::ostream&, ComplexNum&);
  friend std::istream& operator>>(std::istream&, ComplexNum&);

 private:
  double re;
  double im;
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

  ComplexNumPolar& operator=(ComplexNum& rv);
  ComplexNumPolar operator+(const ComplexNumPolar& rv);
  friend ComplexNumPolar operator+(const double lv, const ComplexNumPolar& rv); 
  ComplexNumPolar operator-(const ComplexNumPolar& rv);
  ComplexNumPolar operator-();
  friend ComplexNumPolar operator-(const double lv, const ComplexNumPolar& rv);
  ComplexNumPolar operator*(const ComplexNumPolar& rv);
  friend ComplexNumPolar operator*(const double lv, const ComplexNumPolar& rv);
  ComplexNumPolar operator/(const ComplexNumPolar& rv);
  ComplexNumPolar& operator=(ComplexNumPolar& rv);
  bool operator==(const ComplexNumPolar& rv);
  bool operator!=(const ComplexNumPolar& rv);
  friend std::ostream& operator<<(std::ostream&, ComplexNumPolar&);
  friend std::istream& operator>>(std::istream&, ComplexNumPolar&);

 private:
  double r;
  double phi;
};
