#include "map.h"

template<typename Key, typename Member> Map<Key,Member>::Map() {
	data = nullptr;
	size = 0;
}

/*
friend ostream& operator<<(ostream& out, const Map& m);
Map& operator=(const map& m);
void add(const Key& k, const Member& m);
Member& find(const Key& k);*/