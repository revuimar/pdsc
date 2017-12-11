#include <string>
#include "list.h"
#include "map.h"
using namespace std;
typedef string Title;

class Book {
	public:
		string author;
		unsigned noOfPages;
		bool isOnShelf;
		Book();
		/*~Book(){
			name.~string();
			position.~string();
			delete this;
		}*/
		Book(const Book& m) {
			author = m.author;
			noOfPages = m.noOfPages;
			isOnShelf = m.isOnShelf;
		}
		Book(string a, unsigned n, bool s): author(a), noOfPages(n), isOnShelf(s){};
		friend ostream& operator<<(ostream& out, const Book& m) {
			out<<m.author<<", ";
			out<<m.noOfPages<<", ";
			if(m.isOnShelf){
				out << "on the shelf";
			}
			else{
				out << "borrowed" << endl;
			}
			return out;
		}

		Book& operator= (const Book& m) {
			author = m.author;
			noOfPages = m.noOfPages;
			isOnShelf = m.isOnShelf;
			return *this;
		}
};