#include <iostream>
#include "complex.h"
using namespace std;

int main()
{
  Complex a(1,1),b(2,2),c;

  cout << "########## addition check ##########" << endl;
  c = a + b;
  cout << a << " + " << b << " = " << c << endl;

  c = 10.0 + a;
  cout << "10" << " + " << a << " = " << c << endl;

  c = a + 10.0;
  cout << a << " + " << "10" << " = " << c << endl;

  cout << c << " += " << a << " += " << b << endl;
  c += a += b;
  cout << c << "; "<< a << "; " << b << endl;

  cout << a << " += " << b;
  a += b;
  cout << " = " << a << endl;

  cout << a << " += " << "10";
  a += 10.0;
  cout << " = " << a << endl;
  cout << "####################################" << endl << endl;

  a = Complex(1,1);
  b = Complex(2,2);
  c = Complex(0,0);

  cout << "########## substracion check ##########" << endl;
  c = a - b;
  cout << a << " - " << b << " = " << c << endl;

  c = 10.0 - a;
  cout << "10" << " - " << a << " = " << c << endl;

  c = a - 10.0;
  cout << a << " - " << "10" << " = " << c << endl;

  cout << c << " -= " << a << " -= " << b << endl;
  c -= a -= b;
  cout << c << "; "<< a << "; " << b << endl;

  cout << a << " -= " << b;
  a -= b;
  cout << " = " << a << endl;

  cout << a << " -= " << "10";
  a -= 10.0;
  cout << " = " << a << endl;
  cout << "#######################################" << endl;

  a = Complex(1,1);
  b = Complex(2,2);
  c = Complex(0,0);

  cout << "########## multiplication check ##########" << endl;
  c = a * b;
  cout << a << " * " << b << " = " << c << endl;

  c = 10.0 * a;
  cout << "10" << " * " << a << " = " << c << endl;

  c = a * 10.0;
  cout << a << " * " << "10" << " = " << c << endl;

  cout << c << " *= " << a << " *= " << b << endl;
  c *= a *= b;
  cout << c << "; "<< a << "; " << b << endl;

  cout << a << " *= " << b;
  a *= b;
  cout << " = " << a << endl;

  cout << a << " *= " << "10";
  a *= 10.0;
  cout << " = " << a << endl;
  cout << "##########################################" << endl;

  a = Complex(1,1);
  b = Complex(2,2);
  c = Complex(0,0);

  cout << "########## division check ##########" << endl;
  c = a / b;
  cout << a << " / " << b << " = " << c << endl;

  c = 10.0 / a;
  cout << "10" << " / " << a << " = " << c << endl;

  c = a / 10.0;
  cout << a << " / " << "10" << " = " << c << endl;

  cout << c << " /= " << a << " /= " << b << endl;
  c /= a /= b;
  cout << c << "; "<< a << "; " << b << endl;

  cout << a << " /= " << b;
  a /= b;
  cout << " = " << a << endl;

  cout << a << " /= " << "10";
  a /= 10.0;
  cout << " = " << a << endl;
  cout << "####################################" << endl;

  a = Complex(1,1);
  b = Complex(2,2);
  c = Complex(0,0);

  cout << "does " << a << " equal to " << b << " answer: " << (a==b) << endl;
  cout << "does 2 * " << a << " equal to " << b << " answer: " << ((2*a)==b) << endl;

  cout << a << " Phase: " << a.getPhase() << "[rad]" << " Amplitude: " << a.getAmplitude() << endl;
  cout << "Real part: " << a.Real << " Imaginary part: " << a.Imaginary << endl;
}
