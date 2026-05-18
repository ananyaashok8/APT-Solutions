/*
 * Address.h
 *
 *  Created on: 11-Jan-2022
 *      Author: Ananya Ashok
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <string>

/**
 * Represents the student's Address.
 * Immutable class with only getter methods.
 */

class Address
{
private:
	/**
	 * Attributes of Class Address.
	 */
	std::string street;
	unsigned short postalCode;
	std::string cityName;
	std::string additionalInfo;

public:
	/**
	 * Parameterized Constructor to initialize all attributes of Address class.
	 */
	Address(std::string additionalInfo, std::string cityName, std::string street, unsigned short postalCode);

	/**
	 * Getter method to retrieve additionalInfo. 	 *
	 * @string additionalInfo is returned.
	 */
	const std::string getAdditionalInfo() const;

	/**
	 * Getter method to retrieve city Name. 	 *
	 * @string cityName is returned.
	 */
	const std::string& getCityName() const;

	/**
	 * Getter method to retrieve postalCode. 	 *
	 * @unsigned short postalCode is returned.
	 */
	unsigned short getPostalCode() const;

	/**
	 * Getter method to retrieve street. 	 *
	 * @string street is returned.
	 */
	const std::string& getStreet() const;
};

#endif /* ADDRESS_H_ */
