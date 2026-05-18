/*
 * Enrollment.h
 *
 *  Created on: 11-Jan-2022
 *      Author: Ananya Ashok
 */

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

#include "Course.h"

/**
 * Represents the Courses enrolled by student.
 */
class Enrollment
{
private:
	std::string semester;
	const Course* course;
	float grade;


public:
	/**
	 * Parameterized constructor for Enrollment class.
	 * Initializes all the attributes of this class.
	 */
	Enrollment(std::string sem,const Course* course,float grade = 0.0);

	/**
	 * Getter method to retrieve Course class pointer.
	 * @pointer to Course class .
	 */
	const Course* getCourse() const;

	/**
	 * Getter method to retrieve garde.
	 * @float grade is returned.
	 */
	float getGrade() const;

	/**
	 * Setter method to set grade.
	 */
	void setGrade(float grade);
};

#endif /* ENROLLMENT_H_ */
