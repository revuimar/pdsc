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
			for(m.data.goToHead(); m.data.moreData(); m.data.advance()){
				out<<"ID :"<<m.data.getCurrentData().K;
				out<<"PARAMETERS: "<<m.data.getCurrentData().M;
			}
			return out;
		}
		//Map& operator=(const map& m);
		void add(const Key& k, const Member& m);
		//Member& find(const Key& k);
};
