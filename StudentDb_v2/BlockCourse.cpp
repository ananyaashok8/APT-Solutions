/*
 * BlockCourse.cpp
 *
 *  Created on: 15-Jan-2022
 *      Author: Ananya Ashok
 */

#include "BlockCourse.h"
#include <iostream>

BlockCourse::~BlockCourse()
{

}


BlockCourse::BlockCourse(unsigned int courseKey, std::string major, std::string title,
		const float gradePoints,Poco::Data::Date startDate, Poco::Data::Date endDate,
		Poco::Data::Time startTime, Poco::Data::Time endTime)
:Course{courseKey, major,title,gradePoints},startDate(startDate),
 endDate(endDate),startTime(startTime),endTime(endTime){
}


const Poco::Data::Date& BlockCourse::getEndDate() const
{
	return endDate;
}


const Poco::Data::Time& BlockCourse::getEndTime() const
{
	return endTime;
}


const Poco::Data::Date& BlockCourse::getStartDate() const
{
	return startDate;
}


const Poco::Data::Time& BlockCourse::getStartTime() const
{
	return startTime;
}


/**
 * Block Course console print method.
 * Prints block course details in console for specified student matrikel number.
 */
void BlockCourse::printCourse() const
{
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	std::cout << "Course Type: Block Course "  << std::endl;
	std::cout << "Course start day: "
			<< startDate.day() << "."
			<< startDate.month() << "."
			<< startDate.year() <<  std::endl;
	std::cout <<"Course end day: "
			<< endDate.day() << "."
			<< endDate.month() << "."
			<< endDate.year() << std::endl;
	std::cout << "Course start time: "
			<< startTime.hour()   << "."
			<< startTime.minute() << "."
			<< startTime.second() << std::endl;
	std::cout << "Course end time: "
			<< endTime.hour() <<"."
			<< endTime.minute() << "."
			<< endTime.second() << std::endl;
}



/**
 * Block Course write into file method.
 * Writes course details into a file for specified student matrikel number.
 */
void BlockCourse::write(std::ostream &out) const
{
	out << "B;"<< Course::getCourseKey() << ";" << Course::getTitle() << ";"
			<< Course::getMajor() << ";"<< Course::getCreditPoints() << ";"
			<< startDate.day()   << ":"
			<< startDate.month() << ":"
			<< startDate.year() << ";"
			<< endDate.day() <<":"
			<< endDate.month() << ":"
			<< endDate.year() << ";"
			<< startTime.hour()   << ":"
			<< startTime.minute() << ":"
			<< startTime.second() << ";"
			<< endTime.hour() <<":"
			<< endTime.minute() << ":"
			<< endTime.second() << std::endl;
}
