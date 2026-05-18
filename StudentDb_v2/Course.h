/*
 * Course.h
 *
 *  Created on: 11-Jan-2022
 *      Author: Ananya Ashok
 */

#ifndef COURSE_H_
#define COURSE_H_


#include <string>
#include <map>
#include <fstream>
#include <iostream>


/**
 * Represents the Courses offered.
 * Course- Base class for WeeklyCourse and BlockCourse derived classes.
 */
class Course
{
private:
	//private attributes declaration
	unsigned int courseKey;
	unsigned char major;
	const std::string title;
	const float creditPoints;
	static std::map<unsigned char,std::string> majorById;

public:

	/**
	 * Initializes the Courses attributes.
	 * parameterized constructor for Course class.
	 */
	Course(unsigned int courseKey,std::string majorType,std::string title, float creditPoints = -1);

	/**
	 * Pure virtual Destructor for the Course class.
	 */
	virtual ~Course() = 0;

	/**
	 * Getter method to retrieve creditPoints.
	 * @string creditPoints is returned.
	 */
	const float getCreditPoints() const;


	/**
	 * Getter method to retrieve major.
	 * @string major is returned.
	 */
	std::string getMajor() const;


	/**
	 * Getter method to retrieve title.
	 * @string title is returned.
	 */
	std::string getTitle() const;


	/**
	 * Getter method to retrieve courseKey.
	 * @unsigned int courseKey is returned.
	 */
	unsigned int getCourseKey() const;


	/**
	 * virtual method to print course details.
	 */
	virtual void printCourse() const;


	/**
	 * virtual method to write course details into specified file.
	 */
	virtual void write(std::ostream& out) const;

};

#endif /* COURSE_H_ */
