#include <iostream>		
#include <string>										
#include "map.h"	
#include "aux.h"
using namespace std;

int main(int argc, char const *argv[]) {
	typedef unsigned int Key;

	Map<Key, Member> database;											

	database.add(761028073, Member("Jan Kowalski", "salesman", 28)); 	
	database.add(510212881, Member("Adam Nowak", "storekeeper", 54));	
	database.add(730505129, Member("Anna Zaradna", "secretary", 32));	

	cout << database << endl;									

	Map<Key, Member> newDatabase = database;							
	
	Member* pE;
	pE = newDatabase.find(510212881);									
	pE->position = "salesman";											
	pE = newDatabase.find(761028073);									
	pE->age = 29;														

	database = newDatabase;												
	
	cout << database << endl;
	//delete *database;
	return 0;									
}
