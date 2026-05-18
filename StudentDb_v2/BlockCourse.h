/*
 * BlockCourse.h
 *
 *  Created on: 15-Jan-2022
 *      Author: Ananya Ashok
 */

#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

#include "Course.h"
#include <POCO/Data/Time.h>
#include <POCO/DateTime.h>
#include <POCO/Data/Date.h>

/**
 * Represents the Block Courses registered by Student.
 * Derived class from Course Base class.
 */
class BlockCourse : public Course
{
private:
	// attributes declaration
	Poco::Data::Date startDate;
	Poco::Data::Date endDate;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;

public:
	/**
	 * Virtual Destructor for the BlockCourse class.
	 */
	virtual ~BlockCourse();

	/**
	 * Initializes the Block Courses attributes.
	 * parameterized constructor for BlockCourse class.
	 */
	BlockCourse(unsigned int courseKey, std::string major,
			std::string title,const float gradePoints,
			Poco::Data::Date startDate,
			Poco::Data::Date endDate,
			Poco::Data::Time startTime,
			Poco::Data::Time endTime);

	/**
	 * Getter method to retrieve endDate.
	 * @Poco::Date endDate is returned.
	 */
	const Poco::Data::Date& getEndDate() const;

	/**
	 * Getter method to retrieve endTime.
	 * @Poco::Time endTime is returned.
	 */
	const Poco::Data::Time& getEndTime() const;

	/**
	 * Getter method to retrieve startDate.
	 * @Poco::Date startDate is returned.
	 */
	const Poco::Data::Date& getStartDate() const;

	/**
	 * Getter method to retrieve startTime.
	 * @Poco::Time startTime is returned.
	 */
	const Poco::Data::Time& getStartTime() const;


	/**
	 * Block Course console print method.
	 * Prints block course details in console for specified student matrikel number.
	 */
	void printCourse() const;

	/**
	 * Block Course write into file method.
	 * Writes course details into a file for specified student matrikel number.
	 */
	void write(std::ostream& out) const;
};

#endif /* BLOCKCOURSE_H_ */
