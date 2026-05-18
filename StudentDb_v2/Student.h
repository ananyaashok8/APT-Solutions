/*
 * Student.h
 *
 *  Created on: 11-Jan-2022
 *      Author: Ananya Ashok
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <vector>
#include <map>
#include <fstream>
#include <POCO/DateTime.h>
#include <POCO/Data/Date.h>

#include "Address.h"
#include "Enrollment.h"


/**
 * Represents the Student details class.
 * contains vector of enrollments, student address.
 */
class Student
{
private:

	static int nextFreeMatrikelNumber;
	unsigned int matrikelNumber;
	std::string firstName;
	std::string lastName;
	Poco::Data::Date dateOfBirth;
	std::vector<Enrollment> enrollments;
	Address *address;
public:

	/**
	 * Initializes the Student attributes.
	 * parameterized constructor for Student class.
	 */
	Student(std::string firstname, std::string lastName, Poco::Data::Date dateOfBirth,std::string additionalInfo,std::string street,std::string cityName,unsigned short postalCode);

	/**
	 * destructor for Student class.
	 */
	virtual ~Student();

	/**
	 * Method to retrieve Address data from Address Class.
	 * returns Address attributes.
	 */
	Address* getAddress();

	/**
	 * Getter method to retrieve Enrollments.
	 * @vector of Enrollments is returned.
	 */
	const std::vector<Enrollment>& getEnrollments() const;

	/**
	 * Getter method to retrieve firstName.
	 * @string firstName is returned.
	 */
	const std::string& getFirstName() const;

	/**
	 * Getter method to retrieve lastName.
	 * @string lastName is returned.
	 */
	const std::string& getLastName() const;

	/**
	 * Getter method to retrieve MatrikelNumber.
	 * @unsigned int matrikelNumber is returned.
	 */
	unsigned int getMatrikelNumber() const;

	/**
	 * Getter method to retrieve nextFreeMatrikelNumber.
	 * @int nextFreeMatrikelNumber is returned.
	 */
	int getNextFreeMatrikelNumber() const;

	/**
	 * Getter method to retrieve dateOfBirth.
	 * @Date Poco dateOfBirth is returned.
	 */
	Poco::Data::Date getDateOfBirth() const;

	/**
	 * Setter method to assign dateOfBirth.
	 *  Poco::Date dateOfBirth is set.
	 */
	void setDateOfBirth(const Poco::Data::Date &dateOfBirth);

	/**
	 * Setter method to assign enrollment.
	 *  vector enrollments is set.
	 */
	void setEnrollments(unsigned int courseKey, std::string sem,
			const Course *course);

	/**
	 * Setter method to assign firstName.
	 *  firstName is set.
	 */
	void setFirstName(const std::string &firstName);

	/**
	 * Setter method to assign lastName.
	 * lastName is set.
	 */
	void setLastName(const std::string &lastName);

	/**
	 * Setter method to assign Address.
	 * address fields are set.
	 */
	void setAddress( std::string street,std::string cityName,
			unsigned short postalCode, std::string additionalInfo);

	/**
	 * Virtual method to write student data into a file.
	 */
	virtual void write(std::ostream& out) const;

	/**
	 * Method to update enrollment data.
	 */
	void updateEnrollments(unsigned int courseKey, float gradePoints);

	/**
	 * Method to remove enrollment data.
	 */
	void removeEnrollments(unsigned int courseKey);

	/**
	 * Method to print enrollment data.
	 */
	void printEnrollments();

	/**
	 * Setter method to assign nextfreeMatrikelNumber.
	 * nextfreeMatrikelNumber is set.
	 */
	void setNextFreeMatrikelNumber(int nextFreeMatrikelNumber);
};

#endif /* STUDENT_H_ */
