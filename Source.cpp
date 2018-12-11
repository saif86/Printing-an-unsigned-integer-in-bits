// Fig. 18.5: fig18_05.cpp
// Printing an unsigned integer in bits.
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

void displayBits(unsigned);  // prototype

void main(){
	unsigned inputValue;
	
	cout << "Enter an unsigned integer: ";
	cin >> inputValue;
	displayBits(inputValue);

	system("pause");

} // end main

// display bits of an unsigned integer value
void displayBits(unsigned value){
	const int SHIFT = 8 * sizeof(unsigned) - 1;
	const unsigned MASK = 1 << SHIFT;
	
	cout << setw(10) << value << " = ";

	for (unsigned i = 1; i <= SHIFT + 1; i++) {
		cout << (value & MASK ? '1' : '0');
		value <<= 1;  // shift value left by 1
		
		if (i % 8 == 0)  // output a space after 8 bits
			cout << ' ';
	} // end for
	
	cout << endl;
} // end function displayBits