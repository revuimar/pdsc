#include "matrix.h"
#include <string>
using namespace std;

string matrix::sizesNotCoherent::constructMessage(unsigned lhsR, unsigned lhsC, unsigned rhsR, unsigned rhsC){
	string msg;
	msg.append("Not coherent sizes : \n");
	msg.append(to_string(lhsR));
	msg.append(" by ");
	msg.append(to_string(lhsC));
	msg.append(" and ");
	msg.append(to_string(rhsR));
	msg.append(" by ");
	msg.append(to_string(rhsC));
	return msg;
}

string matrix::indexesOutOfRange::constructMessage(unsigned row, unsigned collumn) {
	string msg;
	msg.append("Indexes out of range : (");
	msg.append(to_string(row));
	msg.append(",");
	msg.append(to_string(collumn));
	msg.append(")");
	return msg;
}

string matrix::sizesForMultiplyingNotAllowed::constructMessage(unsigned lhsC, unsigned rhsR){
	string msg;
	msg.append("Indexes of components do not coincide :\n");
	msg.append("No of collumns of left operand : ");
	msg.append(to_string(lhsC));
	msg.append("\nNo of rows of right operand : ");
	msg.append(to_string(rhsR));
	return msg;
}
