#include "matrix.h"
#include <string>
using namespace std;

matrix::sizesNotCoherent::sizesNotCoherent
(unsigned lhsR, unsigned lhsC, unsigned rhsR, unsigned rhsC):
runtime_error(""), leftRows(lhsR), leftCollumns(lhsC), rightRows(rhsR), rightCollumns(rhsC) {
	msg.append("Not coherent sizes : \n");
	msg.append(to_string(leftRows));
	msg.append(" by ");
	msg.append(to_string(leftCollumns));
	msg.append(" and ");
	msg.append(to_string(rightRows));
	msg.append(" by ");
	msg.append(to_string(rightCollumns));
}
const char* matrix::sizesNotCoherent::what() const noexcept {
	return (msg.c_str());
}

matrix::indexesOutOfRange::indexesOutOfRange
(unsigned r, unsigned c):
runtime_error(""), rows(r), collumns(c) {
	msg.append("Indexes out of range : (");
	msg.append(to_string(r));
	msg.append(",");
	msg.append(to_string(c));
	msg.append(")");
}
const char* matrix::indexesOutOfRange::what() const noexcept {
	return (msg.c_str());
}

matrix::sizesForMultiplyingNotAllowed::sizesForMultiplyingNotAllowed
(unsigned lhsC, unsigned rhsR):
runtime_error(""), leftCollumns(lhsC), rightRows(rhsR) {
	msg.append("Indexes of components do not coincide :\n");
	msg.append("No of collumns of left operand : ");
	msg.append(to_string(leftCollumns));
	msg.append("\nNo of rows of right operand : ");
	msg.append(to_string(rightRows));
}
const char* matrix::sizesForMultiplyingNotAllowed::what() const noexcept {
	return (msg.c_str());
}
