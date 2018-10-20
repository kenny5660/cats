#include "pch.h"
#define _USE_MATH_DEFINES
#include "ComplexNum.h"


#include <cmath> 

ComplexNum::ComplexNum() {
}

ComplexNum::ComplexNum(double _re) :re(_re), im(0) {

}

ComplexNum::ComplexNum(double _re, double _im) : re(_re), im(_im) {

}

ComplexNum::ComplexNum(const ComplexNum &rv) : re(rv.re), im(rv.im) { //copy
}

double ComplexNum::getRe() {
	return re;
}

void ComplexNum::setRe(double _re) {
	re = _re;
}

double ComplexNum::getIm() {
	return im;
}

void ComplexNum::setIm(double _im) {
	im = _im;
}

ComplexNum ComplexNum::operator+(const ComplexNum& rv) {
	return ComplexNum(re + rv.re, im + rv.im);
}

ComplexNum ComplexNum::operator-(const ComplexNum& rv) {
	return ComplexNum(re - rv.re, im - rv.im);
}

ComplexNum ComplexNum::operator*(const ComplexNum& rv) {
	return ComplexNum(re * rv.re - im * rv.im, re * rv.im + im * rv.re);
}

ComplexNum ComplexNum::operator/(const ComplexNum& rv) {

	ComplexNum temp;

	double r = rv.re * rv.re + rv.im * rv.im;
	temp.re = (re * rv.re + im * rv.im) / r;
	temp.im = (im * rv.re - re * rv.im) / r;

	return temp;
}

bool ComplexNum::operator==(const ComplexNum& rv) {
	return re == rv.re && im == rv.im;
}

ComplexNum& ComplexNum::operator=(ComplexNum& rv) {
	re = rv.re;
	im = rv.re;
	return (*this);
}

std::ostream& operator<< (std::ostream &out,  ComplexNum &rv) {
	double Im = rv.getIm();
	out << rv.getRe() << (Im < 0 ? "-" : "+") << (Im < 0 ? -Im : Im) << "i";
	return out;
}

std::istream& operator>> (std::istream &in, ComplexNum &rv) {
	double re;
	double im;
	in >> re >> im;
	rv.setRe(re);
	rv.setIm(im);
	return in;
}

//ComplexNum

ComplexNumPolar::ComplexNumPolar() {

}

ComplexNumPolar::ComplexNumPolar(ComplexNumPolar &rv) {
	setRe(rv.getRe());
	setIm(rv.getIm());
}

ComplexNumPolar::ComplexNumPolar(double r, double phi) : ComplexNum(r*cos(phi), r*sin(phi)) {

}

double ComplexNumPolar::getR() {
	return sqrt(getRe()*getRe() + getIm()*getIm());
}

void ComplexNumPolar::setR(double r) {
	double Phi = getPhi();
	setRe(cos(Phi)*r);
	setIm(sin(Phi)*r);
}

double ComplexNumPolar::getPhi() {
	return atan(getIm() / getRe());
}

void ComplexNumPolar::setPhi(double phi) {
	double R = getR();
	setRe(cos(phi)*R);
	setIm(sin(phi)*R);
}

ComplexNumPolar& ComplexNumPolar::operator=(ComplexNum& rv) {
	setRe(rv.getRe());
	setIm(rv.getIm());
	return (*this);
}

std::ostream& operator<< (std::ostream &out, ComplexNumPolar &rv) {
	double phi = rv.getPhi() * 180 / M_PI;
	out << rv.getR() << "(cos(" << phi << ")" << "isin(" << phi << "))";
	return out;
}

std::istream& operator>> (std::istream &in, ComplexNumPolar &rv) {
	double r;
	double phi;
	in >> r >> phi;
	rv.setR(r);
	rv.setPhi(phi);
	return in;
}
