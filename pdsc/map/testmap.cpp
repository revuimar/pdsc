#include <iostream>
#include <fstream>
#include <string>										
#include "map.h"	
#include "aux.h"
#include "library.h"
using namespace std;

int main(int argc, char const *argv[]) {
	Map<ID, Employee> database;											

try{
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	
}catch(const exception& e){
	cerr << e.what() << endl;
}
	cout << database << endl;									

	Map<ID, Employee> newDatabase = database;							
	
	Employee* pE;
	pE = newDatabase.find(510212881);									
	pE->position = "salesman";											
	pE = newDatabase.find(761028073);									
	pE->age = 29;														

	database = newDatabase;												
	
	cout << database << endl;

	Map<Title,Book> Library1;
try{
	Library1.add("His_Master's_Voice", Book("Stanisław_Lem", 105, 1));
	Library1.add("Kill_The_Mockingbird", Book("Harper_Lee", 281, 0));
	Library1.add("C++_Language_Tutorial", Book("Juan_Soulie", 144, 0));
}catch(const exception& e){
	cerr << e.what() << endl;
}
	cout << Library1 << endl;
	/*ifstream lib1("library.db");
	lib1>>Library1;
	lib1.close();
	cout<<"\nvalues passed from file\n"<<Library1<<endl;
*/


	return 0;									
}
