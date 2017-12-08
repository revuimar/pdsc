#include <string>
#include "list.h"
#include "map.h"
using namespace std;

class Member {
	public:
		string name;
		string position;
		unsigned int age;
		Member();
		/*~Member(){
			name.~string();
			position.~string();
			delete this;
		}*/
		Member(const Member& m) {
			name = m.name;
			position = m.position;
			age = m.age;
		}
		Member(string n, string p, unsigned a): name(n), position(p), age(a){};
		Member(Member&&) = default;                    // Move constructor
		Member& operator=(Member&&) & = default;       // Move assignment operator
		virtual ~Member(){}; 		



		friend ostream& operator<<(ostream& out, const Member& m) {
			out<<m.name<<", ";
			out<<m.position<<", ";
			out<<m.age<<endl;
			return out;
		}

		Member& operator= (const Member& m) {
			name = m.name;
			position = m.position;
			age = m.age;
			return *this;
		}
	
};