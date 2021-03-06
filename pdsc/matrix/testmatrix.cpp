#include "matrix.h"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char const *argv[])
{
	matrix m(5,5,5);
	matrix b(m);
	cout<<"matrix m filled with 5\'s\n"<<m;
	m.displayReference();
	cout<<"matrix b constructed from m\n"<<b;
	b.displayReference();
	m(2,2)=0;
	cout<<"matrix m after setting middle to 0\n"<<m<<endl;
	matrix m1(5,5,1);
	matrix m2(5,5,2);
	cout<<"adding matrix m filled with 5\'s and 0 int he middle\n, m1 filled with 1\'s and m2 filled with 2\'s\n"<<m+m1+m2<<endl;
	cout<<"substraction of matrix m filled with 5\'s and 0 int he middle\n, m1 filled with 1\'s\n"<<m-m1<<endl;
	matrix p(2,3,2);
	matrix p1(3,2,1);

	cout<<"multiplying matrices 2x3 filled with 2\'s and 3x2 with 1\'s\n"<<p*p1<<endl;
	cout<<"multiplying in reversed order\n"<<p1*p<<endl;

	matrix g(2,2,4);
	matrix d(2,2,3);
	matrix s(2,2,5);

	g+=d+=s;
	cout<<g<<"+=\n"<<d<<"+=\n"<<s<<endl;

	g-=d-=s;
	cout<<g<<"-=\n"<<d<<"-=\n"<<s<<endl;

	g*=d*=s;
	cout<<g<<"*=\n"<<d<<"*=\n"<<s<<endl;

	

	try{
		cout<< m+p <<endl;
	}
	catch(const exception& e) {
		cerr << e.what() << endl;
	}

	try{
		cout<< m(10,1)<<endl;
	}
	catch(const exception& e) {
		cerr << e.what() << endl;
	}
	
	try{
		cout<< p*m1 <<endl;
	}
	catch(const exception& e) {
		cerr << e.what() << endl;
	}

	matrix test("matrix.txt");
	cout<<"\nopen from file\n"<<test<<endl;

	matrix test2(5,5);
	ifstream test2file("matrix2.txt");
	test2file>>test2;
	test2file.close();
	cout<<"\nvalues passed from file\n"<<test2<<endl;


	return 0;

}

