#ifndef __Matrix_H__
#define __Matrix_H__
#include <iostream>
#include <map>
using namespace std;

class matrix{
  class container;
  container* data;
  public:
	class sizeOutOfRange{};
  class sizeNotCoherent{};
  class sizeForMultiplyingNotAllowed{};
	class Creference;
	matrix();
	matrix(unsigned int i, unsigned int j);
  matrix(unsigned int i, unsigned int j, double n);
	matrix(const matrix& m);
  double read(unsigned int i, unsigned int j) const;
  void write(unsigned int i, unsigned int j, double n);
	//matrix(FILE* f);
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
  inline void checkSize (unsigned int i,unsigned int j) const;
  inline void checkMultiplying (unsigned int i) const;
	friend ostream& operator<<(ostream& out, const matrix& m);
	//matrix& (FILE* f);
  Creference operator() (unsigned int i, unsigned int j);

};
class matrix::Creference {
  friend class matrix;

  matrix& matrix_cref;
  unsigned int rows_cref;
  unsigned int collumns_cref;

  Creference(matrix& m, unsigned int i, unsigned int j): matrix_cref(m), rows_cref(i), collumns_cref(j) {};
public:
	operator double() const {
    return matrix_cref.read(rows_cref,collumns_cref); 
  }
	Creference& operator= (double n) {
		matrix_cref.write(rows_cref,collumns_cref, n);
		return *this;
	};
  Creference& operator= (const Creference& r)
  {
    return operator= ((double)r);
  };
	
};
class matrix::container {
  public:
  friend class matrix;
  double** content;
  unsigned int rows;
  unsigned int collumns;
  unsigned int ref;
  container(unsigned int i, unsigned int j, double** ncontent)
  {
    ref = 1;
    rows = i;
    collumns = j;
    content = new double*[rows];
    for (unsigned y=0; y<rows; y++) {
        content[y] = new double[collumns];
    }
    for (unsigned y = 0; y < rows; y++) {
      	for (unsigned x = 0; x < collumns; x++) {
        	content[y][x] = ncontent[y][x];
      }
    }
  };
  ~container(){
    for (unsigned y = 0; y < rows; y++) {
        delete [] content[y];
    }
    delete [] content;
  };
  container* detach()
  {
    if(ref == 1)
      return this;
    container* temp = new container(rows, collumns, content);
    ref--;
    return temp;
  };
  void assign(unsigned int i, unsigned int j, double** ncontent)
  {
    for (unsigned y = 0; y < rows; y++) {
      for (unsigned x = 0; x < collumns; x++) {
        content[y][x] = ncontent[y][x];
      }
    }
  };
  container(const container&);
  container& operator=(const container&);
};

#endif