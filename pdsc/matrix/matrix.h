#ifndef __Matrix_H__
#define __Matrix_H__
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class matrix{
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
  double read(unsigned int i, unsigned int j) const;
  void write(unsigned int i, unsigned int j, double n);
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
	inline void checkRange (unsigned int i,unsigned int j) const;
  inline void checkSize (const matrix& rhsM) const;
  inline void checkMultiplying (unsigned int i) const;
	friend ostream& operator<<(ostream& out, const matrix& m);
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
    unsigned leftRows, leftCollumns;
    unsigned rightRows, rightCollumns;
    string msg;
  public:
    sizesNotCoherent(unsigned leftRows, unsigned leftCollumns, unsigned rightRows, unsigned rightCollumns);
    virtual const char* what() const noexcept override;
};  

class matrix::indexesOutOfRange: public runtime_error {
  private:
    unsigned rows, collumns;
    string msg;
  public:
    indexesOutOfRange(unsigned r, unsigned c);
    virtual const char* what() const noexcept override;
}; 

class matrix::sizesForMultiplyingNotAllowed: public runtime_error {
  private:
    unsigned leftCollumns, rightRows;
    string msg;
  public:
    sizesForMultiplyingNotAllowed(unsigned lhsC, unsigned rhsR);
    virtual const char* what() const noexcept override;
};

#endif