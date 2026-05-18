/*
 * ModuloNDigit.h
 *
 *  Created on: 10-Nov-2021
 *      Author: 91819
 */

// Standard (system) header files
#include <iostream>
#include <stdlib.h>
using namespace std;

#ifndef ModuloNDigit_H_
#define ModuloNDigit_H_


/**
 * @brief Class creation for implementation of Single-Digit Modulo Counter
 * provides the count from 0 to N for the given N-count and base values
 * get count values and pass onto the ModuloNCounter object.
 */
class ModuloNDigit
{
	/**
	 * Initializes the new instances of the sensors.
	 */
	private:
		int sdc_currentCount;
		int m_base;
	public:
		/**
		 * Initializes the new instances of the counter.
		 */
		ModuloNDigit();
		/**
		 * Destructor to free up the memory allocated to constructors after program execution.
		 */
		~ModuloNDigit();
		/**
		 * Setter for the parameter base values.
		 */
		ModuloNDigit(int base);
		/**
		 * Setter for the parameters count and base values.
		 */
		void sdc_init(int count, int base);
		/**
		 * assignment operator overloading implementation to specify the compiler to point at copy constructor.
		 */
		void sdc_print();
		/**
		 * performs the count operation
		 * @return instance reference of a ModuloNDigit
		 */
		int sdc_count();

};

#endif /* ModuloNDigit_H_ */
