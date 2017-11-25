#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
using namespace std;

class Complex {
	public:
		double Real, Imaginary;

		Complex() : Real(0), Imaginary(0) {};
		Complex(double re) : Real(re), Imaginary(0) {};
		Complex(double re, double im) : Real(re), Imaginary(im) {};
		
		Complex& operator=(const Complex&);
		Complex& operator=(double);
		Complex operator-();
		Complex& operator-=(Complex);
		Complex& operator+=(Complex);
		Complex& operator*=(Complex);
		Complex& operator/=(Complex);
		bool operator== (Complex);
		double getAmplitude();
		double getPhase();
};
Complex operator-(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator+(const Complex&, const Complex&);
ostream& operator<<(ostream&, const Complex&);
Complex conjugate(Complex number);
#endif /* __Complex_H__ */
