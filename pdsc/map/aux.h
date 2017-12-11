#include <string>
#include "list.h"
#include "map.h"
using namespace std;
typedef unsigned int ID;
class Employee {
	public:
		string name;
		string position;
		unsigned int age;
		Employee();
		/*~Employee(){
			name.~string();
			position.~string();
			delete this;
		}*/
		Employee(const Employee& m) {
			name = m.name;
			position = m.position;
			age = m.age;
		}
		Employee(string n, string p, unsigned a): name(n), position(p), age(a){};
		friend ostream& operator<<(ostream& out, const Employee& m) {
			out<<m.name<<", ";
			out<<m.position<<", ";
			out<<m.age<<endl;
			return out;
		}

		Employee& operator= (const Employee& m) {
			name = m.name;
			position = m.position;
			age = m.age;
			return *this;
		}
	
};