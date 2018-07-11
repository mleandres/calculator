#include "calc.h"




// Ctor
Calc::Calc() : error{false}, display{0}, oper{0}, result{0}, memory{0} {}

// Copy Ctor
Calc::Calc(const Calc &other)
	: error{other.error}, display{other.display}, result{other.result},
		memory{other.memory} {}

// adds digit (which must be between 0 and 9, inclusive) to the end of the
// display value
void Calc::digit(int digit) {
	display = display*10 + digit;
}

// sets the operator field. If the operator field previously contained an
// operator, it combines display and result with that operator, and stores the
// result. If not, display is copied to result. In either case, display is
// cleared (reset to 0)
void Calc::op(char opera) {
	// operator is NOT HERE
	if (oper == 0) {
		result = display;
	}
	// operator is present
	else {
		equals();
	}
	oper = opera;
	display = 0;
}

// combines result and display using operator, and stores the result in
// result and display. Clears the operator field
void Calc::equals() {
	if (oper == '+') {
		result = result + display;
	}
	else if (oper == '-') {
		result = result - display;
	}
	else if (oper == '*') {
		result = result * display;
	}
	else if (oper == '/') {
			if (display == 0) {
				error = true;
				result = 0;
			}
			else {
				result = result / display;
		}
	}
	display = result;
	oper = 0;
}

// adds the displayed value to the contents of memory, and stores the result
// in memory
void Calc::memPlus() {
	memory += display;
}
// clears the contents of the memory (sets it to 0)
void Calc::memClear() {
	memory = 0;
}

// copies the contents of memory to the display
void Calc::memRecall() {
	display = memory;
}

// answers true if the error flag is set (because of division by 0)
bool Calc::isError() {
	return error;
}

// resets all memory to 0, clears the operator, and resets the error flag
void Calc::allClear() {
	memory = 0;
	display = 0;
	result = 0;
	oper = 0;
	error = false;
}

// overload << operator
std::ostream &operator<<(std::ostream &out, const Calc &c) {
	out << c.display;
	if (c.memory != 0) out << " M: " << c.memory;
	if(c.error) out << " E";
	return out;
}

