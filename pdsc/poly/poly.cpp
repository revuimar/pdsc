#include "poly.h"
#include <iostream>
#include <cmath>
using namespace std;

double Polynomial::read(unsigned int i) {
	return expression.at(i);
}
void Polynomial::write(unsigned int i, double c) {
	expression[i] = c;
}

double Polynomial::operator()(double x) const{
	double y = 0;
	for(auto component : this->expression){
			y += component.second * pow(x,component.first);
	}
	return y;
}
Polynomial Polynomial::operator-() const {
	Polynomial temp(*this);
	for(auto rightComponent : temp.expression){
		temp[rightComponent.first] = -temp[rightComponent.first];
	}
	return temp;
}
Polynomial& Polynomial::operator+=(const Polynomial& poly) {
	return *this = *this + poly;
}
Polynomial& Polynomial::operator-=(const Polynomial& poly){
	return *this = *this - poly;
}
Polynomial& Polynomial::operator*=(const Polynomial& poly){
	return *this = *this * poly;
}

Polynomial operator+(const Polynomial& leftPoly, const Polynomial& rightPoly) {
	Polynomial temp(leftPoly);
	for(auto component : rightPoly.expression){
		if(!(temp.expression[component.first] +=  component.second)){
			temp.expression.erase(component.first);
		}		
	}
	return temp;
}

Polynomial operator-(const Polynomial& leftPoly, const Polynomial& rightPoly) {
	return (-rightPoly + leftPoly);
}

Polynomial operator*(const Polynomial& leftPoly, const Polynomial& rightPoly) {
	Polynomial temp(leftPoly);
	for(auto rightComponent : rightPoly.expression){
		for(auto leftComponent : leftPoly.expression){
			if(!(temp[leftComponent.first + rightComponent.first] = 
				leftComponent.second * rightComponent.second)){
				temp.expression.erase(leftComponent.first + rightComponent.first);
			}
			
		}
	}
	return temp;
}

ostream& operator<<(ostream& stream, const Polynomial& poly){
	bool firstLoop = true; 
	for(auto component = poly.expression.rbegin(); component != poly.expression.rend(); ++component) {
		if(component->second > 0){
			stream << ((firstLoop)? ("") : ("+"));
		}
		stream << component->second;
		if(component->first != 0) {
			stream << "x";
			if(component->first != 1) {
				stream << "^" << component->first;
			}
		}
		firstLoop = false;
	}
	return stream;
}

Polynomial::Creference Polynomial::operator[](unsigned int i) {
	return{*this, i};
}