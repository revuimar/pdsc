#include "matrix.h"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	matrix m(5,5,5);
	cout<<m<<endl;
	m(2,2)=0;
	cout<<m<<endl;
	matrix m1(5,5,1);
	matrix m2(5,5,2);
	cout<<m+m1+m2<<endl;
	return 0;
}
