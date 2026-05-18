/*
 * Enrollment.cpp
 *
 *  Created on: 11-Jan-2022
 *      Author: Ananya Ashok
 */

#include "Enrollment.h"


float Enrollment::getGrade() const
{
	return grade;
}


const Course* Enrollment::getCourse() const
{
	return course;
}

Enrollment::Enrollment(std::string semester, const Course *course,
		float grade):semester(semester),course(course), grade(grade)
{

}

void Enrollment::setGrade(float grade)
{
	this->grade = grade;
}

