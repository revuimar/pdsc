#include <iostream>
#include <string>
#include "list.h"
using namespace std;


template<class Key, class Member> class Map {
	
	public:
		struct Pair {
			Pair(Key k, Member m): K(k), M(m){};
			Pair();
			Key K;
			Member M;
		};
		
		unsigned int size;
		list<Pair> data;
		Map();
		Map(const Map& m);
		~Map();

		friend ostream& operator<<(ostream& out, const Map& m) {
			for(m.data->goToHead(); m.data->moreData(); m.data->advance()){
				out<<"ID :"<<m.data->getCurrentData().K;
				out<<"PARAMETERS: "<<m.data.getCurrentData().M;
			}
			return out;
		}
		//Map& operator=(const map& m);
		void add(const Key& k, const Member& m);
		//Member& find(const Key& k);
};
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
class Key {
	public:
	unsigned int key;
	Key(unsigned int k): key(k){};
	~Key();
};