// Standard (system) header files
#include <iostream>
#include <stdlib.h>

using namespace std;

// Add your project's header files here
// #include "CFraction.h"

#include "ModuloNCounter.h"
#include "ModuloNDigit.h"

/** \brief Take the input from the user for the
 * Initialization of constructors as substitutes of the functions.
 * @param digit_value to read the digit value from the user input.
 * @param base_value to read the base value from the user input.
 * Implementation of multi-digit counter using the pre-increment and post-increment operator overloading *
 * */

int main (void)
{
	int digit_value = 0, base_value = 0;
	//Modulo N Single-Digit Counter implementation
	cout << "single digit moduloNCounter started." << endl ;
	cout << "Please enter the parameters of your counter:" << endl ;
	cout << "count Value: " << endl;
	cin >> digit_value;
	cout << "Base Value: " << endl;
	cin >> base_value;
	ModuloNDigit v1;
	v1.sdc_init(digit_value ,base_value);
	for(int i=0;i< 20; i++)
	{
		v1.sdc_count();
		v1.sdc_print();
	}
	cout << "\n";

	//Modulo N Multi-Digit Counter implementation
	cout << "Please enter the parameters of your counter:" << endl ;
	cout << "number of digits " << endl;
	cin >> digit_value;
	cout << "type (2/8/10/16): " << endl;
	cin >> base_value;
	ModuloNCounter counter(digit_value ,base_value );
	ModuloNCounter res;
	cout << digit_value  <<" digit " << base_value << "counter" <<"\n";
	for(int i=0;i< 255; i++)
	{
		res = ++counter;
		res.mdc_print();
	}

	/*char temp[25];
	sprintf(temp, "%02d:%02d", hour, min);
	std::string stringTimestamp = temp;*/
	return 0;
}
