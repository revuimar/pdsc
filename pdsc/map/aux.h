#include <string>
using namespace std;

class Member {
	public:
		string name;
		string position;
		unsigned int age;
		Member();
		Member(string n, string p, unsigned a): name(n), position(p), age(a){};
		friend ostream& operator<<(ostream& out, const Member& m) {
			out<<m.name<<", ";
			out<<m.position<<", ";
			out<<m.age<<endl;
			return out;
		}
	
};
/*class Key {
	public:
	unsigned int key;
	Key(unsigned int k): key(k){};
	~Key();
};*/