#ifndef __Map_H__
#define __Map_H__
#include <iostream>
#include <string>
#include "list.h"
using namespace std;


template<typename Key, typename Member> class Map {
	public:
		struct Pair {
			Pair(const Key& k, const Member& m): K(k), M(m){};
			Pair(const Pair& pair): K(pair.K), M(pair.M){};
			Pair() = default;
			Key K;
			Member M;
		};
		list<Pair> data;
	//public:
		template <typename T> friend class list;
		Map() = default;
		Map(const Map& m);
  		
		template <typename _k, typename _m> friend ostream& operator<<(ostream& out, const Map<_k,_m>& map);
		Map& operator=(const Map& m);

		void add(Key k,Member m);

		Member* find(const Key& k);
	
	//private:
		
};
template <typename Key, typename Member> Member* Map<Key, Member>::find (const Key& k){
	data.goToHead();
	for(; data.moreData(); data.advance()){
		if (data.getCurrentData()->K == k) {
			return &data.getCurrentData()->M;
		}	
	}
	data.goToHead();
	return nullptr;
}

template <typename Key, typename Member> 
Map<Key,Member>& Map<Key,Member>::operator= (const Map<Key,Member>& m) {
    data = m.data;
    return *this;
}

template <typename _k, typename _m>
ostream& operator<<(ostream& out, Map<_k,_m>& map) {
	map.data.goToHead();
	if(!map.data.moreData()) {
		out<<"map empty";
		return out;
	}
	for(; map.data.moreData(); map.data.advance()){
		out<<"ID :"<<map.data.getCurrentData()->K;
		out<<" PARAMETERS: "<<map.data.getCurrentData()->M;
	}
	map.data.goToHead();
	return out;
}

template<typename Key,typename Member>
Map<Key,Member>::Map(const Map<Key,Member>& m) {
	data = m.data;
}

template<typename Key,typename Member>
void Map<Key,Member>::add(Key k,Member m) {
	auto temp = new Pair(k,m);
	data.insert(temp);
}


#endif