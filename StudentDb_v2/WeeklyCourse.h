/*
 * WeeklyCourse.h
 *
 *  Created on: 15-Jan-2022
 *      Author: Ananya Ashok
 */

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

#include "Course.h"
#include <POCO/Data/Time.h>
#include <POCO/DateTime.h>
#include <POCO/Data/Date.h>

/**
 * Represents the Weekly Courses registered by Student.
 * Derived class from Course Base class.
 */
class WeeklyCourse: public Course
{
private:
	Poco::DateTime::DaysOfWeek dayOfWeek;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
public:
	/**
	 * Virtual Destructor for the BlockCourse class.
	 */
	virtual ~WeeklyCourse();

	/**
	 * Initializes the Weekly Courses attributes.
	 * parameterized constructor for WeeklyCourse class.
	 */
	WeeklyCourse(unsigned int courseKey,std::string major,std::string title,const float gradePoints,
			Poco::DateTime::DaysOfWeek dayOfWeek,Poco::Data::Time startTime,
			Poco::Data::Time endTime);

	/**
	 * Weekly Course console print method.
	 * Prints Weekly course details in console for specified student matrikel number.
	 */
	void printCourse() const;


	/**
	 * Getter method to retrieve dayOfWeek.
	 * @Poco::Day dayOfweek is returned.
	 */
	Poco::DateTime::DaysOfWeek getDayOfWeek() const;

	/**
	 * Getter method to retrieve endTime.
	 * @Poco::Time endTime is returned.
	 */
	const Poco::Data::Time& getEndTime() const;

	/**
	 * Getter method to retrieve startTime.
	 * @Poco::Time startTime is returned.
	 */
	const Poco::Data::Time& getStartTime() const;

	/**
	 * Weekly Course write into file method.
	 * Writes course details into a file for specified student matrikel number.
	 */
	void write(std::ostream& out) const;
};

#endif /* WEEKLYCOURSE_H_ */
