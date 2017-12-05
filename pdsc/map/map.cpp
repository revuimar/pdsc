#include <iostream>
#include "map.h"
using namespace std;

template<typename Key, typename Member> Map<Key,Member>::Map() {
	data = NULL;
	size = 0;
}
template<typename Key, typename Member> Map<Key,Member>::Map(const Map& m) {
	list<Pair> temp = new Pair(m.Key,m.Member);
	this->data->insert(temp);
}


//friend ostream& operator<<(ostream& out, const Map& m);
//Map& operator=(const map& m);
template<typename Key, typename Member> void Map<Key,Member>::add(const Key& k, const Member& m){
	list<Pair> temp = new Pair(k,m);
	data.insert(temp);
	size++;

}



//Member& find(const Key& k);

