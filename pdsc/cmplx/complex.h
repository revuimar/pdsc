#ifndef __Complex_H__
#define __Complex_H__
#include <iostream>
using namespace std;

class Complex {
	public:
		double Real, Imaginary;

		Complex(double re = 0, double im = 0) : Real(re), Imaginary(im) {};
		
		Complex operator-();
		Complex& operator-=(const Complex&);
		Complex& operator+=(const Complex&);
		Complex& operator*=(const Complex&);
		Complex& operator/=(const Complex&);
		bool operator== (const Complex&);
		double getAmplitude();
		double getPhase();
};
Complex operator-(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator+(const Complex&, const Complex&);
ostream& operator<<(ostream&, const Complex&);
Complex conjugate(const Complex&);
#endif /* __Complex_H__ */
