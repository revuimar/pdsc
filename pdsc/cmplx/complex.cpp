#include <iostream>
#include <math.h>
#include "complex.h"
using namespace std;

Complex Complex::operator-() {
	return Complex(0 - Real,0 - Imaginary);/*preventing getting output like "-0"*/
}

Complex& Complex::operator-=(const Complex& number) {
	Real -= number.Real;
	Imaginary -= number.Imaginary;
	return *this;
}

Complex& Complex::operator+=(const Complex& number) {
	Real += number.Real;
	Imaginary += number.Imaginary;
	return *this;
}

Complex& Complex::operator*=(const Complex& number) {
	Complex temp(Real,Imaginary);
	Real = number.Real * temp.Real - (number.Imaginary * temp.Imaginary);
	Imaginary = temp.Imaginary * number.Real + temp.Real * number.Imaginary;
	return *this;
}
Complex& Complex::operator/=(const Complex& number) {
	double temp = (number*conjugate(number)).Real;
	*this *= conjugate(number);
	Real /= temp;
	Imaginary /= temp;
	return *this;
}


bool Complex::operator==(const Complex& number){
	return (this->Real == number.Real && this->Imaginary == number.Imaginary);
}

double Complex::getAmplitude() {
	return sqrt(pow(this->Real,2)+pow(this->Imaginary,2));
}

double Complex::getPhase() {
	return acos(this->Real/this->getAmplitude());
}


Complex operator-(const Complex& left, const Complex& right) {
	Complex n;
	n.Real = left.Real - right.Real;
	n.Imaginary = left.Imaginary - right.Imaginary;
	return n;
}

Complex operator/(const Complex& left, const Complex& right) {
	Complex n;
	double temp = (right*conjugate(right)).Real;
	n = conjugate(right) * left;
	n.Real /= temp;
	n.Imaginary /= temp;
	return n;
}

Complex operator*(const Complex& left, const Complex& right) {
	Complex n;
	n.Real = right.Real * left.Real - (right.Imaginary * left.Imaginary);
	n.Imaginary = left.Imaginary * right.Real + left.Real * right.Imaginary;
	return n;
}

ostream& operator<<(ostream& stream, const Complex& number) {
	stream << "(" << number.Real;
	if(number.Imaginary >= 0){
		stream << "+";
	}
	stream << number.Imaginary << "i)";
	return stream;
}

Complex conjugate(const Complex& number) {
	Complex n (number);
	n.Imaginary = 0 - number.Imaginary;
	return n;
}

Complex operator+(const Complex& left, const Complex& right) {
	Complex n;
	n.Real = left.Real + right.Real;
	n.Imaginary = left.Imaginary + right.Imaginary;
	return n;
}