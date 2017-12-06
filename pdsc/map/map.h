#ifndef __Map_H__
#define __Map_H__
#include <iostream>
#include <string>
#include "list.h"
using namespace std;


template<typename Key, typename Member> class Map {
	public:
		struct Pair {
			Pair(Key k, Member m): K(k), M(m){};
			Pair() = default;
			Key K;
			Member M;
		};
		Map();
		Map(const Map<Key,Member>& m);

		template <typename k, typename m> 
		friend ostream& operator<<(ostream& out, Map<k,m>& map);
		Map<Key,Member>& operator=(const Map<Key,Member>& m);
		void add(Key k,const Member& m);
		//Member& find(const Key& k);
	private:
		unsigned int size;
		list<Pair> data;
};
/*
template <typename Key, typename Member> Map<Key,Member>& Map<Key,Member>::operator= (const Map<Key,Member>& m) {
    data = m.data;
    size = m.size;
    return *this;
}

template <typename k, typename m> 
ostream& operator<<(ostream& out, Map<k,m>& map) {
	map.data.goToHead();
	for(; map.data.moreData(); map.data.advance()){
		out<<"ID :"<<map.data.getCurrentData()->K;
		out<<"PARAMETERS: "<<map.data.getCurrentData()->M;
	}
	return out;
}

template <typename Key, typename Member> Map<Key,Member>::Map() {
	size = 0;
}

template<typename Key, typename Member> Map<Key,Member>::Map(const Map<Key,Member>& m) {
	data = m.data;
    size = m.size;
}


//friend ostream& operator<<(ostream& out, const Map& m);
//Map& operator=(const map& m);
template<typename Key, typename Member> void Map<Key,Member>::add(Key k, Member m){
	Map<Key, Member>::Pair* temp;
	temp = new Pair(k,m);
	data.insert(temp);
	size++;

}*/
#endif