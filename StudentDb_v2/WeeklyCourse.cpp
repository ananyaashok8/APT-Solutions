/*
 * WeeklyCourse.cpp
 *
 *  Created on: 15-Jan-2022
 *      Author: Ananya Ashok
 */

#include "WeeklyCourse.h"
#include <iostream>


WeeklyCourse::WeeklyCourse(unsigned int courseKey, std::string major,
		std::string title,const float gradePoints, Poco::DateTime::DaysOfWeek dayOfWeek,
		Poco::Data::Time startTime, Poco::Data::Time endTime)
:Course{courseKey, major,title,gradePoints},dayOfWeek(dayOfWeek),
 startTime(startTime),endTime(endTime){

}


WeeklyCourse::~WeeklyCourse()
{
}

Poco::DateTime::DaysOfWeek WeeklyCourse::getDayOfWeek() const
{
	return dayOfWeek;
}

const Poco::Data::Time& WeeklyCourse::getEndTime() const
{
	return endTime;
}


/**
 * Weekly Course console print method.
 * Prints weekly course details in console for specified student matrikel number.
 */
void WeeklyCourse::printCourse() const
{
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	std::cout << " Course Type: Weekly Course "  << std::endl;
	std::cout << " Course Day :"     << dayOfWeek << std::endl;
	std::cout << " Course start time: "
			<< startTime.hour()   << "."
			<< startTime.minute() << "."
			<< startTime.second() << std::endl;
	std::cout << " Course end time: "   << endTime.hour() <<"."
			<< endTime.minute() << "."
			<< endTime.second() << std::endl;
}

const Poco::Data::Time& WeeklyCourse::getStartTime() const
{
	return startTime;
}


/**
 * weekly Course write into file method.
 * Writes weekly details into a file for specified student matrikel number.
 */
void WeeklyCourse::write(std::ostream &out) const
{
	out << "W;"<< Course::getCourseKey() << ";" << Course::getTitle() << ";"
			<< Course::getMajor() << ";"<< Course::getCreditPoints() << ";"
			<< dayOfWeek << ";"
			<< startTime.hour()   << ":"
			<< startTime.minute() << ":"
			<< startTime.second() << ";"
			<< endTime.hour() <<":"
			<< endTime.minute() << ":"
			<< endTime.second() <<std::endl;
}
