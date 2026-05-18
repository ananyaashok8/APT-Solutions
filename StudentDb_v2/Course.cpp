/*
 * Course.cpp
 *
 *  Created on: 11-Jan-2022
 *      Author: Ananya Ashok
 */

#include "Course.h"


/**
 * container map to store major by ID for memory management.
 */
std::map<unsigned char,std::string> Course::majorById ={
		{'E', "Embedded"},{'A',"Automation"},{'C',"Communication"},{'P',"Power"} };


Course::~Course()
{
}

const float Course::getCreditPoints() const
{
	return creditPoints;
}

std::string Course::getMajor() const
{
	std::string tempMajor;

	auto it = majorById.find(major);
	if(it!= majorById.end())
	{
		tempMajor = it->second;
	}
	return tempMajor;
}

Course::Course(unsigned int courseKey,std::string majorType, std::string title, float creditPoints) :courseKey(courseKey), title(title), creditPoints(creditPoints)
{
	this->major = majorType.front();
}

unsigned int Course::getCourseKey() const
{
	return courseKey;
}

std::string Course::getTitle() const
{
	return title;
}

void Course::printCourse() const
{
	//do nothing.
	//will invoke print methods of derived class.
}

void Course::write(std::ostream &out) const
{
	out << "                 Courses  List                  " << std::endl;
	out << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<std::endl;
}
