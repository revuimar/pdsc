#ifndef __Matrix_H__
#define __Matrix_H__
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

class matrix{
private:
	double read(unsigned int i, unsigned int j) const;
	void write(unsigned int i, unsigned int j, double n);
	inline void checkRange (unsigned int i,unsigned int j) const;
	inline void checkSize (const matrix& rhsM) const;
	inline void checkMultiplying (unsigned int i) const;
	class container;
	container* data;
public:
	class indexesOutOfRange;
	class sizesNotCoherent;
	class sizesForMultiplyingNotAllowed;
	class Creference;
	matrix(const char filepath[]);
	matrix(unsigned int i, unsigned int j);
	matrix(unsigned int i, unsigned int j, double n);
	matrix(unsigned int i, unsigned int j, double** ncontent);
	matrix(const matrix& m);
	
	void displayReference();
	~matrix();
	matrix operator*(double n) const;
	matrix& operator=(const matrix& m);
	matrix& operator+=(const matrix & m);
	matrix& operator-=(const matrix & m);
	matrix& operator*=(const matrix & m);
	matrix operator+(const matrix & m) const;
	matrix operator-(const matrix & m) const;
	matrix operator*(const matrix & m) const;
	bool operator==(const matrix & m) const;
	
	friend ostream& operator<<(ostream& out, const matrix& m);
	friend istream& operator>>(istream& in, matrix& m);
	Creference operator() (unsigned int i, unsigned int j);

};

class matrix::Creference {
	friend class matrix;
	matrix& matrix_cref;
	unsigned int rows_cref;
	unsigned int collumns_cref;
	Creference(matrix& m, unsigned int i, unsigned int j): matrix_cref(m), rows_cref(i), collumns_cref(j) {};
public:
	operator double() const;
	Creference& operator= (double n);
	Creference& operator= (const Creference& r);
};

class matrix::container {
public:
	friend class matrix;
	double** content;
	unsigned int rows;
	unsigned int collumns;
	unsigned int ref;
	container(unsigned int i, unsigned int j, double** ncontent);
	container(unsigned int i, unsigned int j, double n);
	container(unsigned int i, unsigned int j);
	container(const char filepath[]);
	~container();
	container* detach();
};

class matrix::sizesNotCoherent: public runtime_error {
private:
	static string constructMessage(unsigned lhsR, unsigned lhsC, unsigned rhsR, unsigned rhsC);
public:
	sizesNotCoherent(unsigned lhsR, unsigned lhsC, unsigned rhsR, unsigned rhsC):
	runtime_error(constructMessage(lhsR, lhsC, rhsR, rhsC)) {};
};  

class matrix::indexesOutOfRange: public runtime_error {
private:
	static string constructMessage(unsigned row, unsigned collumn);
public:
	indexesOutOfRange(unsigned row, unsigned collumn): runtime_error(constructMessage(row, collumn)) {};
}; 

class matrix::sizesForMultiplyingNotAllowed: public runtime_error {
private:
	static string constructMessage(unsigned lhsC, unsigned rhsR);
public:
	sizesForMultiplyingNotAllowed(unsigned lhsC, unsigned rhsR): runtime_error(constructMessage(lhsC, rhsR)) {};
};

#endif