/*
 * ModuloNCounter.h
 *
 *  Created on: 10-Nov-2021
 *      Author: 91819
 */
#include <iostream>
#include <stdlib.h>

#include "ModuloNDigit.h"


#ifndef ModuloNCounter_H_
#define ModuloNCounter_H_
class ModuloNDigit;

/**
 * @brief Class creation for implementation of Multi-Digit Modulo Counter.
 * provides the count from 0 to N for the given digits and base values.
 * get count values from ModuloNDigit and pass onto the ModuloNCounter object.
 * provides pre-increment and post-increment operator overloading implementation.
 */
class ModuloNCounter
{
	/**
	 * Initializes the new instances of the sensors.
	 */
	private:
		int mdc_digits;
		int m_base;
		ModuloNDigit *pSDC;
	public:
		/**
		 * Initializes the new instances of the counter.
		 */
		ModuloNCounter();
		/**
		 * Setter for the parameters digits and base values.
		 */
		ModuloNCounter(int digits, int base);
		/**
		 * Copy constructor to store the value of the count during pre-increment implementation.
		 */
		ModuloNCounter(const ModuloNCounter& obj);
		/**
		 * Destructor to free up the memory allocated to constructors after program execution.
		 */
		~ModuloNCounter();
		/**
		 * Setter for the ModuloNCounter values
		 * @return instance reference of a ModuloNCounter
		 */
		ModuloNCounter& operator++();
		/**
		 * pre-increment operator overloading implementation for the ModuloNCounter.
		 */
		ModuloNCounter operator++(int);
		/**
		 * post-increment operator overloading implementation for the ModuloNCounter.
		 */
		ModuloNCounter& operator=(const ModuloNCounter& obj);
		/**
		 * assignment operator overloading implementation to specify the compiler to point at copy constructor.
		 */
		void mdc_print();
		/**
		 * performs the count operation
		 * @return instance reference of a ModuloNCounter
		 */
		int mdc_count();

};

#endif /* ModuloNCounter_H_ */
