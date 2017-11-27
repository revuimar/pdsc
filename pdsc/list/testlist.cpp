#include <iostream>
using namespace std;
#include "list.h"


void PrintList(list toPrint, ostream & Out) {
	int nextValue;
	Out << "Printing list contents: " << endl;
	Out << "Current node val:" << ((toPrint.moreData()) ?  (toPrint.getCurrentData()) : NULL)<< endl;
	toPrint.goToHead();
	if (!toPrint.moreData()) {
		Out << "List is empty" << endl;
		return;
	}
	while (toPrint.moreData()) {
		nextValue = toPrint.getCurrentData();
		Out << nextValue << " ";
		toPrint.advance();
	}
	Out << endl;
}

int main() {
	list l;
	l.insert (1);
	l.insert (2);
	l.insert (3);
	l.goToHead();
	l.advance();
	PrintList (l, cout);
	list l2, l3, l4, l5;
	l2 = l;
	PrintList (l2,cout);
	l3.insert (4);
	l3.insert (5);
	l3.insert (6);
	l2 = l3;
	PrintList (l2,cout);
	PrintList (l3,cout);
	l4 = l2;
	l4.insert(7);
	PrintList (l4,cout);
	l4 = l;
	PrintList(l4,cout);
	l4 = l5;
	PrintList(l5,cout);
}
