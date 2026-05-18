/*
 * Student.cpp
 *
 *  Created on: 11-Jan-2022
 *      Author: Ananya Ashok
 */

#include "Student.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int Student::nextFreeMatrikelNumber = 100000;

Student::Student(std::string firstname, std::string lastName,Poco::Data::Date dateOfBirth,std::string additionalInfo,std::string street,std::string cityName,unsigned short postalCode): firstName(firstname), lastName(lastName),dateOfBirth(dateOfBirth)
{
	matrikelNumber = nextFreeMatrikelNumber;
	address = new Address(additionalInfo, cityName, street, postalCode);
}


Address* Student::getAddress()
{
	return address;
}


const std::vector<Enrollment>& Student::getEnrollments() const
{
	return enrollments;
}

const std::string& Student::getFirstName() const
{
	return firstName;
}

const std::string& Student::getLastName() const
{
	return lastName;
}

unsigned int Student::getMatrikelNumber() const
{
	return matrikelNumber;
}


void Student::setDateOfBirth(const Poco::Data::Date &dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}


void Student::setFirstName(const std::string &firstName)
{
	this->firstName = firstName;
}


void Student::setLastName(const std::string &lastName)
{
	this->lastName = lastName;
}

int Student::getNextFreeMatrikelNumber() const
{
	return nextFreeMatrikelNumber++;
}

Poco::Data::Date Student::getDateOfBirth() const
{
	return this->dateOfBirth;
}


/**
 * method to create a new instance of Address Class everytime
 * this method is called.
 */
void Student::setAddress(std::string street,
		std::string cityName, unsigned short postalCode, std::string additionalInfo)
{
	address = new Address(additionalInfo,cityName,street,postalCode);
}

/**
 * method to add new enrollment to the  Enrollment vector.
 */
void Student::setEnrollments(unsigned int courseKey, std::string sem,
		const Course *course)
{
	std::vector<Enrollment>::iterator enrolIter;
	for(enrolIter = enrollments.begin();enrolIter != enrollments.end();enrolIter++ )
	{
		if(enrolIter->getCourse()->getCourseKey() == courseKey)
		{
			//warning message to avoid multiple enrollment for same course
			std::cout << "Enrollment already exists" << std::endl;
		}
		else {
			//passing 0.0 to grade as its a new enrollment
			//grade can be updated later
			Enrollment newEnrollment(sem,course, 0.0);
			enrollments.push_back(newEnrollment);
		}
	}

}

Student::~Student()
{
}


void Student::write(std::ostream &out) const
{
	out << matrikelNumber-1<< ";"
			<< firstName << ";" << lastName<< ";"
			<< dateOfBirth.day() << "."
			<< dateOfBirth.month() << "."
			<< dateOfBirth.year() << ";" << address->getStreet() << ";"
			<< address->getCityName() << ";" << address->getPostalCode() << ";";
	out << address->getAdditionalInfo();
	out << std::endl;
	out << enrollments.size();
	out << std::endl;
	for(auto & val: enrollments)
	{
		out<<matrikelNumber-1<< ";"<<val.getCourse()->getCourseKey() << ";"
				<< val.getCourse()->getTitle() << ";"
				<< val.getCourse()->getCreditPoints() << ";"
				<<  val.getGrade() << ";" ;
	}
	out << std::endl;

}


/**
 * method to update enrollment to the Enrollment vector.
 */
void Student::updateEnrollments(unsigned int courseKey, float gradePoints)
{
	std::vector<Enrollment>::iterator enrolIter;
	for(enrolIter = enrollments.begin();enrolIter != enrollments.end();enrolIter++ )
	{
		//iterate through Enrollments Vector and update grade for specified
		//courseKey for that specific student
		if(enrolIter->getCourse()->getCourseKey() == courseKey)
		{
			enrolIter->setGrade(gradePoints);
		}
	}
	std::cout << "Enrollment updated" << std::endl;

}

/**
 * method to remove enrollment to the  Enrollment vector.
 */
void Student::removeEnrollments(unsigned int courseKey)
{
	std::vector<Enrollment>::iterator enrolIter;
	for(enrolIter = enrollments.begin();enrolIter != enrollments.end();enrolIter++ )
	{
		//iterate through Enrollments Vector and update grade for specified
		//courseKey for that specific student
		if(enrolIter->getCourse()->getCourseKey() == courseKey)
		{
			enrollments.erase(enrolIter);
		}
		break;
	}
	std::cout << "Enrollment removed." << std::endl;
}

void Student::setNextFreeMatrikelNumber(int nextFreeMatrikelNumber)
{
	this->nextFreeMatrikelNumber = nextFreeMatrikelNumber;
}

void Student::printEnrollments()
{
	for ( auto & val: enrollments)
	{
		std::cout  << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
		std::cout  << "CourseKey: " <<val.getCourse()->getCourseKey() << "\n";
		std::cout  << "Title: " << val.getCourse()->getTitle() << "\n";
		std::cout  << "CreditPoints: " << val.getCourse()->getCreditPoints() << "\n";
		std::cout  << "Major: " << val.getCourse()->getMajor() << "\n";
		val.getCourse()->printCourse();
		std::cout  << "Grade: " << val.getGrade() << "\n" ;

	}
}
/*
parseLine(std::string line, char delimiter,
        std::vector<std::string> &myVec)
{

    size_t start = 0;
    size_t end   = 0;

    end = line.find(delimiter, start);
    while( end != string ::npos)
    {
        myVec.push_back(line.substr(start, (end-start)));
        start = start+delimiter;
        end = line.find(delimiter,start);
    }
    myVec.push_back(line.substr(start));

}*/