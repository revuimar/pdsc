#include "matrix.h"
#include <iostream>
using namespace std;

matrix::matrix(unsigned int i, unsigned int j) {
	double** temp = new double*[i];
    for (unsigned y=0; y<i; y++) {
        temp[y] = new double[j];
    }
    for (unsigned y = 0; y < i; y++) {
      	for (unsigned x = 0; x < j; x++) {
        	temp[y][x] = 0;
      }
    }
	data = new container(i,j,temp);
}
matrix::matrix(unsigned int i, unsigned int j, double n) {
	double** temp = new double*[i];
    for (unsigned y=0; y<i; y++) {
        temp[y] = new double[j];
    }
    for (unsigned y = 0; y < i; y++) {
      	for (unsigned x = 0; x < j; x++) {
        	temp[y][x] = n;
      }
    }
	data = new container(i,j,temp);
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
    throw sizeOutOfRange();
  }
}
inline void matrix::checkSize (unsigned int i,unsigned int j) const {
	if(data->rows < i || data->collumns < j){
    	throw sizeOutOfRange();
  	}
}
inline void matrix::checkMultiplying (unsigned int i) const{
	if(this->data->collumns != i){
		throw sizeForMultiplyingNotAllowed();
	}
}
matrix matrix::operator+(const matrix& m) const{
	checkSize(m.data->rows,m.data->collumns);
	for (unsigned i = 0; i < this->data->rows; ++i)
	{
		for (unsigned j = 0; j < this->data->collumns; ++j)
		{
			this->data->content[i][j] += m.data->content[i][j];
		}
	}
	return *this;
}
matrix matrix::operator-(const matrix& m) const{
	checkSize(m.data->rows,m.data->collumns);
	for (unsigned i = 0; i < this->data->rows; ++i)
	{
		for (unsigned j = 0; j < this->data->collumns; ++j)
		{
			this->data->content[i][j] -= m.data->content[i][j];
		}
	}
	return *this;
}
matrix& matrix::operator+=(const matrix& m) {
	return *this = *this + m;
}
matrix& matrix::operator-=(const matrix& m) {
	return *this = *this + m;
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
