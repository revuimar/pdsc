#include <iostream>
#include "map.h"
using namespace std;


template <typename Key, typename Member> Map<Key, Member>& Map<Key, Member>::operator= (const Map<Key,Member>& m) {
    data = m.data;
    size = m.size;
    return *this;
}

template <typename k, typename m> ostream& operator<<(ostream& out, const Map<k,m>& map) {
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
template<typename Key, typename Member> void Map<Key,Member>::add(Key k, const Member& m){
	Map<Key, Member>::Pair* temp;
	temp = new Pair(k,m);
	data.insert(temp);
	size++;

}

