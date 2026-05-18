/*
 * StudentDb.h
 *
 *  Created on: 11-Jan-2022
 *      Author: Ananya Ashok
 */

#ifndef STUDENTDB_H_
#define STUDENTDB_H_

#include <map>
#include <string>
#include <POCO/DateTime.h>
#include <POCO/Data/Date.h>

#include "Student.h"
#include "Course.h"
#include "WeeklyCourse.h"
#include "BlockCourse.h"
#include "Enrollment.h"


/**
 * Represents the Student Database.
 * contains a map to store students and courses.
 * provides user to perform add new course, student and enrollments.
 * lets user to search, update the student data.
 * provides functionality to read student data from file.
 * provides functionality to write student data into a file.
 */
class StudentDb
{
private:
	//containers to store student and course data.
	std::map<int,Student> students;
	std::map<int,std::unique_ptr<const Course>> courses;

public:

	/**
	 * Method to add new student data to the Student Database.
	 * provides user to perform add new course.
	 */
	void addNewCourse();

	/**
	 * Method to add new course to the Student Database.
	 * provides user to perform add new student.
	 */
	void addNewStudentData();

	/**
	 * Method to add new enrollment data to the Student Database.
	 * provides user to perform add new enrollment.
	 */
	void addNewEnrollment();

	/**
	 * Method to print student data in the Student Database.
	 * prints all data about the student.
	 */
	void printStudent();

	/**
	 * Method to print courses data in the Student Database.
	 * prints all the courses offered.
	 */
	void printCourses();

	/**
	 * Method to search for a specific student in the Student Database.
	 * provides user to perform search operation on database.
	 */
	void searchStudent();

	/**
	 * Method to update for a specific student in the Student Database.
	 * provides user to perform update operation on database.
	 */
	void updatestudent();

	/**
	 * Method to read student data from a file into student database.
	 */
	void read(std::istream& in);

	/**
	 * Method to write student data to a file from student database.
	 */
	void write(std::ostream& out);

	/**
	 * Method to retrieve student data from server and store it in the Student Database.
	 */
	void serverConnect();

};

#endif /* STUDENTDB_H_ */
