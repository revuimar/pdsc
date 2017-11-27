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
  matrix(ifstream& f);
	matrix(unsigned int i, unsigned int j);
  matrix(unsigned int i, unsigned int j, double n);
  matrix(unsigned int i, unsigned int j, double** ncontent);
	matrix(const matrix& m);
  double read(unsigned int i, unsigned int j) const;
  void write(unsigned int i, unsigned int j, double n);
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
  container(unsigned int i, unsigned int j, double n)
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
          content[y][x] = n;
      }
    }
  };
  container(unsigned int i, unsigned int j)
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
          content[y][x] = 0;
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