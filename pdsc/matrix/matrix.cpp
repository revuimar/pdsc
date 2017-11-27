#include "matrix.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
matrix::matrix(const char filepath[]) {
	data = new container(filepath);
}
matrix::matrix(unsigned int i, unsigned int j) {
	data = new container(i,j);
}
matrix::matrix(unsigned int i, unsigned int j, double n) {
	data = new container(i,j,n);
}
matrix::matrix(unsigned int i, unsigned int j, double** ncontent) {
	data = new container(i,j,ncontent);
}
matrix::~matrix() {
	if(--data->ref == 0) {
    	delete data;
	}
}
matrix::matrix(const matrix& m){
	m.data->ref++;
	data = m.data;
}
matrix& matrix::operator=(const matrix& m)
{
	m.data->ref++;
  	if(--data->ref == 0){
    	delete data;
	}
  	data = m.data;
  	return *this;
}
double matrix::read(unsigned int i, unsigned int j) const
{
	checkRange(i,j);
 	return data->content[i][j];
}
void matrix::write(unsigned int i, unsigned int j, double n)
{
	checkRange(i,j);
  	data = data->detach();
  	data->content[i][j] = n;
}
void matrix::displayReference() {
	cout<<"reference: "<<this->data->ref<<endl;
}
matrix::Creference matrix::operator()(unsigned int i, unsigned int j){
	return Creference(*this,i,j);
}
ostream& operator<<(ostream& out, const matrix& m) {
	for (unsigned i = 0; i < m.data->rows; ++i)
	{
		for (unsigned j = 0; j < m.data->collumns; ++j)
		{
			out<<"["<<m.data->content[i][j]<<"]";
		}
		out<<endl;
	}
	return out;
}
inline void matrix::checkRange (unsigned int i, unsigned int j) const {
  if(data->rows < i || data->collumns < j){
    throw indexesOutOfRange(i,j);
  }
}
inline void matrix::checkSize (const matrix& rhsM) const {
	if(data->rows != rhsM.data->rows || data->collumns != rhsM.data->collumns){
    	throw sizesNotCoherent(data->rows, data->collumns, rhsM.data->rows, rhsM.data->collumns);
  	}
}
inline void matrix::checkMultiplying (unsigned int i) const{
	if(this->data->collumns != i){
		throw sizesForMultiplyingNotAllowed(this->data->collumns, i);
	}
}
matrix matrix::operator+(const matrix& m) const{
	checkSize(m);
	matrix temp(m.data->rows,m.data->collumns);
	for (unsigned i = 0; i < temp.data->rows; ++i)
	{
		for (unsigned j = 0; j < temp.data->collumns; ++j)
		{
			temp.data->content[i][j] = this->data->content[i][j] + m.data->content[i][j];
		}
	}
	return temp;
}
matrix matrix::operator-(const matrix& m) const{
	checkSize(m);
	matrix temp(m.data->rows,m.data->collumns);
	for (unsigned i = 0; i < temp.data->rows; ++i)
	{
		for (unsigned j = 0; j < temp.data->collumns; ++j)
		{
			temp.data->content[i][j] = this->data->content[i][j] - m.data->content[i][j];
		}
	}
	return temp;
}
matrix& matrix::operator+=(const matrix& m) {
	return *this = *this + m;
}
matrix& matrix::operator-=(const matrix& m) {
	return *this = *this - m;
}
bool matrix::operator==(const matrix& m) const{
	if(this->data->rows != m.data->rows || this->data->collumns != m.data->collumns){
		return false;
	}
	for (unsigned i = 0; i < this->data->rows; ++i)
	{
		for (unsigned j = 0; j < this->data->collumns; ++j)
		{
			if(!(this->data->content[i][j] == m.data->content[i][j])){
				return false;
			}
		}
	}
	return true;
}
matrix matrix::operator*(const matrix& m) const {
	checkMultiplying(m.data->rows);
	matrix temp(this->data->rows,m.data->collumns);
	for (unsigned i = 0; i < temp.data->rows; ++i) {
		for (unsigned j = 0; j < temp.data->collumns; ++j) {
			for(unsigned sideCount = 0; sideCount < m.data->rows; sideCount++){
				temp.data->content[i][j] += 
				this->data->content[i][sideCount] * m.data->content[sideCount][j];
			}
		}
	}
	return temp;
}
matrix& matrix::operator*=(const matrix & m) {
	return *this = (*this) * (m);
}
matrix matrix::operator*(double n) const {
	for (unsigned i = 0; i < this->data->rows; ++i) {
		for (unsigned j = 0; j < this->data->collumns; ++j) {	
			this->data->content[i][j] *= n;
		}
	}
	return *this;
}


matrix::Creference::operator double() const {
    return matrix_cref.read(rows_cref,collumns_cref); 
}

matrix::Creference& matrix::Creference::operator= (double n) {
	matrix_cref.write(rows_cref,collumns_cref, n);
	return *this;
}

matrix::Creference& matrix::Creference::operator= (const Creference& r) {
	return operator= ((double)r);
}


matrix::container::container(unsigned int i, unsigned int j, double** ncontent) {
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
}
matrix::container::container(unsigned int i, unsigned int j, double n) {
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
}
matrix::container::container(unsigned int i, unsigned int j) {
    ref = 1;
    rows = i;
    collumns = j;
    content = new double*[rows];
    for (unsigned y=0; y<rows; y++) {
        content[y] = new double[collumns]();
    }
}
matrix::container::container(const char filepath[]) {
	ifstream file(filepath);
	if(file.good()){
	ref=1;
	file>>rows>>collumns;
	content = new double*[rows];
    for (unsigned y=0; y<rows; y++) {
        content[y] = new double[collumns];
    }
	for (unsigned r = 0; r < rows; r++) {
		for(unsigned c = 0; c < collumns; c++) {
			file>>content[r][c];
		}
	}
	}
	file.close();
}
matrix::container::~container() {
    for (unsigned y = 0; y < rows; y++) {
        delete [] content[y];
    }
    delete [] content;
}
matrix::container* matrix::container::detach() {
    if(ref == 1)
      return this;
    container* temp = new container(rows, collumns, content);
    ref--;
    return temp;
}
