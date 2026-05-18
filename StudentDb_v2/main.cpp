// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include "SimpleUI.h"
#include "StudentDb.h"


int main ()
{
	//Student Database execution start
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl ;
	std::cout << "              STUDENT DATABASE              " << std::endl;

	//StudentDb object creation
	StudentDb db;

	//passing StudentDb object as reference to SimpleUI object.
	SimpleUI test(db);
	while(1)
	test.run();

	return 0;
}
