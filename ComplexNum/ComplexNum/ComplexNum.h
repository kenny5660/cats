#pragma once
#include<iostream>
class ComplexNum
{
public:
	ComplexNum();
	ComplexNum(double _re);
	ComplexNum (double _re,double _im);
	ComplexNum(const ComplexNum &rv);//copy

	double getRe();
	void setRe(double _re);
	double getIm();
	void setIm(double _im);

	ComplexNum operator+(const ComplexNum& rv);
	ComplexNum operator-(const ComplexNum& rv);
	ComplexNum operator*(const ComplexNum& rv);
	ComplexNum operator/(const ComplexNum& rv);
	ComplexNum& operator=(const ComplexNum& rv);
	ComplexNum operator==(const ComplexNum& rv);
	// к личным (private) данным
	friend std::ostream& operator<< (std::ostream &,  ComplexNum &);
	friend std::istream& operator>> (std::istream &, ComplexNum &);


private:
	double re;
	double im;
};

class ComplexNumPolar : public ComplexNum
{
public:
	ComplexNumPolar();
	ComplexNumPolar(double r, double phi);
	ComplexNumPolar(ComplexNumPolar &rv);//copy

	double getR();
	void setR(double r);
	double getPhi();
	void setPhi(double phi);

	ComplexNumPolar& operator=(ComplexNum& rv);

	friend std::ostream& operator<< (std::ostream &,  ComplexNumPolar &);
	friend std::istream& operator>> (std::istream &, ComplexNumPolar &);
private:

};
