#ifndef __Polynomial_H__
#define __Polynomial_H__
#include <iostream>
#include <map>
using namespace std;


class Polynomial {
	private:
		map<unsigned int,double> expression;
		double read(unsigned int);
		void write(unsigned int,double);
	public:
		class Creference;
		Polynomial(const double n = 0){
			if(n) expression[0] = n;
		};
		double operator()(double) const;
		Polynomial operator-() const;
		Polynomial& operator+=(const Polynomial&);
		Polynomial& operator-=(const Polynomial&);
		Polynomial& operator*=(const Polynomial&);
		friend Polynomial operator+(const Polynomial&, const Polynomial&);
		friend Polynomial operator-(const Polynomial&, const Polynomial&);
		friend Polynomial operator*(const Polynomial&, const Polynomial&);
		friend ostream& operator<<(ostream&, const Polynomial&);
		Creference operator[] (unsigned int);
};

class Polynomial::Creference {
public:
	operator double() { return expression_cref.read(index_cref); }
	Polynomial::Creference& operator= (double coef) {
		expression_cref.write(index_cref, coef);
		return *this;
	};
private:
	friend class Polynomial;
	Polynomial& expression_cref;
	unsigned int index_cref;
	Creference(Polynomial& e, unsigned int i): expression_cref(e), index_cref(i) {};
};


#endif /* __Polynomial_H__ */