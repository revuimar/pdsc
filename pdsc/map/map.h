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
			Pair() = default;
			Pair(const Pair&) = default;// Copy constructor
  			Pair(Pair&&) = default;                    // Move constructor
			Pair& operator=(const Pair&) & = default;  // Popy assignment operator
			Pair& operator=(Pair&&) & = default;       // Move assignment operator
			~Pair(){
				K.~Key();
				M.~Member();
			} 
			Key K;
			Member M;
		};
		Map();
		Map<Key,Member>(const Map<Key,Member>& m);
  		Map(Map<Key,Member>&&) = default;                    // Move constructor
  		Map<Key,Member>& operator=(Map<Key,Member>&&) & = default;       // Move assignment operator
  		~Map();

		template <typename k, typename m> 
		friend ostream& operator<<(ostream& out, const Map<k,m>& map);
		Map<Key,Member>& operator=(const Map<Key,Member>& m);
		void add(Key k,Member m);
		Member* find(const Key& k);
	
		unsigned int size;
		list<Pair> data;
};
template <typename Key, typename Member> Member* Map<Key, Member>::find (const Key& k){
	Member* temp;
	data.goToHead();
	for(; data.moreData(); data.advance()){
		if (data.getCurrentData()->K == k) {
			temp = &data.getCurrentData()->M;
		}	
	}
	return temp;
}

template <typename Key, typename Member> Map<Key, Member>& Map<Key, Member>::operator= (const Map<Key,Member>& m) {
    data = m.data;
    size = m.size;
    return *this;
}

template <typename k, typename m>  ostream& operator<<(ostream& out, Map<k,m>& map) {
	
	map.data.goToHead();
	for(; map.data.moreData(); map.data.advance()){
		out<<"ID :"<<map.data.getCurrentData()->K;
		out<<" PARAMETERS: "<<map.data.getCurrentData()->M;
	}
	map.data.goToHead();
	return out;
}

template <typename Key, typename Member> Map<Key,Member>::Map() {
	size = 0;
}
template <typename Key, typename Member> Map<Key,Member>::~Map() {
	data.goToHead();
	delete data.getCurrentData();
	size--;
}

template<typename Key, typename Member> Map<Key,Member>::Map(const Map<Key,Member>& m) {
	data = m.data;
    size = m.size;
}


//friend ostream& operator<<(ostream& out, const Map& m);
//Map& operator=(const map& m);
template<typename Key, typename Member> void Map<Key,Member>::add(Key k,Member m){
	//auto* temp;// Map<Key, Member>::Pair
	auto* temp = new Pair(k,m);
	data.insert(temp);
	size++;

}


#endif