/*
 * Address.cpp
 *
 *  Created on: 11-Jan-2022
 *      Author: Ananya Ashok
 */

#include "Address.h"
#include <iostream>

const std::string Address::getAdditionalInfo() const
{
	return additionalInfo;
}

const std::string& Address::getCityName() const
{
	return cityName;
}

unsigned short Address::getPostalCode() const
{
	return postalCode;
}

Address::Address(std::string additionalInfo, std::string cityName,
		std::string street, unsigned short postalCode)
{
	this-> additionalInfo = additionalInfo;
	this-> cityName = cityName;
	this-> street = street;
	this-> postalCode = postalCode;
}

const std::string& Address::getStreet() const
{
	return street;
}

