/*
 * StudentDb.cpp
 *
 *  Created on: 11-Jan-2022
 *      Author: Ananya Ashok
 */

#include "StudentDb.h"
#include <iostream>
#include <algorithm>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <POCO/Data/Time.h>
#include <POCO/DateTime.h>
#include <POCO/Data/Date.h>

#include "Poco/JSON/Parser.h"
#include "Poco/JSON/Object.h"
#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/StreamCopier.h"



using std::ifstream; using std::ostringstream;
using std::istringstream;


void StudentDb::addNewCourse()
{
	try{
		std::string courseTitle;
		std::string major;
		float gradePoints;
		int courseKey;
		int courseType;
		std::string sem;
		int hour,minute,sec,month ,day,year;
		Poco::DateTime::DaysOfWeek dayOfWeek;
		Poco::Data::Time startTime;
		Poco::Data::Time endTime;
		Poco::Data::Date startDate;
		Poco::Data::Date endDate;
		Poco::Data::Time blockStartTime;
		Poco::Data::Time blockEndTime;
		std::cout << "                Add New Course             " << std::endl;
		std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;

		std::cout << "Enter New Course title to be added:" << std::endl;
		std::cin >> courseTitle;
		std::cout << "major:" << std::endl;
		std::cin >> major;
		std::cout << "gradePoints:" << std::endl;
		std::cin >> gradePoints;
		std::cout << "courseKey :" << std::endl;
		std::cin >> courseKey;

		std::cout << "semester :" << std::endl;
		std::cin >> sem;

		if (!((sem.find("WiSe") != std::string::npos) | (sem.find("SoSe") != std::string::npos))) {
			throw (1);
		}
		std::cout << "course Type : (Enter 1-> Weekly Course, 2-> Block Course) " << std::endl;
		std::cin >> courseType;


		if(courseType == 1)
		{
			std::cout << "Enter the day for the weekly Course  : (format : 0->Sunday, 1->Monday)" << std::endl;
			std::cin >> day;
			dayOfWeek = Poco::DateTime::DaysOfWeek(day);
			std::cout << "Enter the start time in the format (hour , minutes, seconds) " << std::endl;
			std::cin >> hour >> minute >> sec;
			startTime.assign(hour,minute,sec);
			std::cout << "Enter the end time in the format (hour , minutes, seconds) " << std::endl;
			std::cin >> hour >> minute >> sec;
			endTime.assign(hour,minute,sec);

			std::unique_ptr<const Course> newCourse = std::unique_ptr<const Course>(new WeeklyCourse(courseKey,major, courseTitle,gradePoints,sem,
					dayOfWeek,startTime,endTime));
			courses.insert(std::pair<int,std::unique_ptr<const Course>>(courseKey,std::move(newCourse)));

		}
		else if(courseType == 2)
		{
			std::cout << "Enter the start date for the block Course (format : (day,month,year))  :" << std::endl;
			std::cin >> day >> month >> year;
			startDate.assign(year,month,day);
			if((year > 2000) | (year < 1700))
				throw(90);
			else if((month > 12) | (month < 1))
				throw(91);
			else if((day > 31) | (day < 1))
				throw(92);
			std::cout << "Enter the end date for the block Course (format : (day,month,year))  :" << std::endl;
			std::cin >> day >> month >> year;
			endDate.assign(year,month,day);
			if((year > 2000) | (year < 1700))
				throw(90);
			else if((month > 12) | (month < 1))
				throw(91);
			else if((day > 31) | (day < 1))
				throw(92);
			std::cout << "Enter the start time in the format (hour , minutes, seconds) " << std::endl;
			std::cin >> hour >> minute >> sec;
			startTime.assign(hour,minute,sec);
			std::cout << "Enter the end time in the format (hour , minutes, seconds) " << std::endl;
			std::cin >> hour >> minute >> sec;
			startTime.assign(hour,minute,sec);

			std::unique_ptr<const Course> newCourse = std::unique_ptr<const Course>(new BlockCourse(courseKey, major,courseTitle,gradePoints,sem,
					startDate,endDate,startTime,endTime));
			courses.insert(std::pair<int,std::unique_ptr<const Course>>(courseKey,std::move(newCourse)));
		}
		else
			std::cout << "Oops!! Invalid course type entered." << std::endl;
	}
	catch(int errCode){
		std::cout << "Invalid date entered." << std::endl;
		if(errCode == 1)
			std::cout << "Invalid Semester Entered!" << '\n';
	}
	catch(std::invalid &e)
	{
		e.what();
	}
	catch(...){
		std::cout << "Oops! Student data incorrect." << std::endl;
	}
}

void StudentDb::addNewStudentData()
{
	std::cout << "            Add New Student Info           " << std::endl;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	std::string firstName,lastName,street,additionalInfo,cityName;
	int day,month,year;
	Poco::Data::Date dateOfBirth;
	unsigned short postalCode;
	std::cout << "Please enter student Data" << std::endl;
	std::cout << "First name:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, firstName);
	std::cout << "Last name:" << std::endl;
	std::cin.ignore(0);
	std::getline(std::cin, lastName);
	std::cout << "DOB: (format:YYYY MM DD)" << std::endl;
	std::cin >> year >> month >> day;
	dateOfBirth.assign(year, month, day);
	std::cout << "Please enter student address details :" << std::endl;

	std::cout << "streetName:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, street);

	std::cout << "cityName:" << std::endl;
	std::cin.ignore(0);
	std::getline(std::cin, cityName);

	std::cout << "postalCode:" << std::endl;
	std::cin >> postalCode;

	std::cout << "additionalInfo:" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, additionalInfo);


	Student newStudent(firstName,lastName,dateOfBirth,additionalInfo,street,cityName,postalCode);
	int matrklNr = newStudent.getNextFreeMatrikelNumber();
	students.insert (std::pair<int,Student>(matrklNr,{newStudent.getFirstName(),
			newStudent.getLastName(),newStudent.getDateOfBirth(),
			newStudent.getAddress()->getAdditionalInfo(),
			newStudent.getAddress()->getStreet(),
			newStudent.getAddress()->getCityName(),
			newStudent.getAddress()->getPostalCode()}));

	/*if(students.find(matrklNr) != students.end())
		students[matrklNr] = newStudent;
	else
	{
		students = matrklNr;
		students.push_back(newStudent);
	}*/
}

void StudentDb::addNewEnrollment()
{
	std::cout << "            Add New Enrollment             " << std::endl;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	unsigned int matrikelNumber,courseKey;
	std::string sem;
	std::cout << "Adding new enrollment" << std::endl;
	std::cout << "Enter the matrikel number for student enrollment:" << std::endl;
	std::cin >> matrikelNumber;
	std::map<int,Student>::iterator it;
	for(it = students.begin();it!= students.end(); it++)
	{
		if(it == students.find(matrikelNumber))
		{
			std::cout << "Enter the course key of the course you want to enroll to :" << std::endl;
			std::cin >> courseKey;
			std::cout << "Enter the semester you want to enroll for:" << std::endl;
			std::cin >> sem;
			std::map<int,std::unique_ptr<const Course>>::const_iterator courseIter;
			courseIter = courses.find(courseKey);
			if(courseIter != courses.end())
			{
				it->second.setEnrollments(courseKey, sem, courseIter->second.get());
			}
			else
				std::cout << "No course found for the given Course Key." << std::endl;
		}
	}

}

void StudentDb::printStudent()
{
	int matrikelNumber;
	std::cout << "             print Student data            " << std::endl;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	std::cout << "   " << std::endl;
	std::cout << "Enter the matrikel number of the student to search for:" << std::endl;
	std::cin >> matrikelNumber;
	std::map<int,Student>::iterator it;
	bool matrikelNumberFound = false;

	for(it = students.begin();it!= students.end(); it++)
	{
		if(it == students.find(matrikelNumber))
		{
			std::cout << ">>> Student Personal Details-->" << std::endl;
			std::cout << std::endl;
			std::cout <<"Matrikel Number: " << it->first << std::endl;
			std::cout << "First name: " << it->second.getFirstName() << std::endl
					<< "Second name: " << it->second.getLastName()<< std::endl
					<< "DOB: " << it->second.getDateOfBirth().day() << "-"
					<< it->second.getDateOfBirth().month() << "-"
					<< it->second.getDateOfBirth().year() <<std::endl
					<< "Student Address :" << std::endl
					<< "City Name: "<< it->second.getAddress()->getCityName() << std::endl
					<< "Street: "<< it->second.getAddress()->getStreet()  << std::endl
					<< "Postal Code: "<< it->second.getAddress()->getPostalCode() << std::endl
					<< "Additional Info: "<< it->second.getAddress()->getAdditionalInfo() << std::endl;

			std::cout << std::endl;
			std::cout << ">>> Student Course Enrollments-->" << std::endl;
			std::cout << std::endl;
			it->second.printEnrollments();

			matrikelNumberFound = true;
		}
	}
	if(!matrikelNumberFound)
		std::cout << "Matrikel Number not found in Database." << std::endl;


}

void StudentDb::printCourses()
{
	std::cout << "                 Courses  List                  " << std::endl;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" <<std::endl;

	std::map<int,std::unique_ptr<const Course>>::const_iterator it;
	for(it = courses.begin();it != courses.end(); it++)
	{
		std::cout << "Course Name :" << it->second.get()->getTitle() << std::endl;
		std::cout << "Course Key :" << it->second.get()->getCourseKey() << std::endl;
		std::cout << "Major :" << it->second.get()->getMajor() << std::endl;
		std::cout << "Credit Points :" << it->second.get()->getCreditPoints() << std::endl;
		it->second.get()->printCourse();
	}

}


void StudentDb::searchStudent()
{
	std::cout << "            Search student Info            " << std::endl;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	std::string searchString = "unknown";
	std::cout << "Enter the student name to be searched:" << std::endl;
	std::cin >> searchString;
	std::size_t tempFirst,tempLast;



	for(std::map<int,Student>::iterator it = students.begin();it!= students.end(); it++)
	{
		tempFirst = it->second.getFirstName().find(searchString);
		tempLast = it->second.getLastName().find(searchString);
		if(tempFirst != std::string::npos)
		{
			std::cout <<"Matrikel Number: " << it->first << std::endl
					<< "First name: " << it->second.getFirstName() << std::endl
					<< "Second name: " << it->second.getLastName()<< std::endl;
		}
		else if(tempLast != std::string::npos)
		{
			std::cout <<"Matrikel Number: " << it->first << std::endl
					<< "First name: " << it->second.getFirstName() << std::endl
					<< "Second name: " << it->second.getLastName()<< std::endl;

		}
		else
			std::cout << "Oops!! Student Data not found for the given input string" << std::endl;
	}

}

void StudentDb::updatestudent()
{
	int matrikelNumber,updateCode;

	std::cout << "            Update student Info            " << std::endl;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	std::cout << "   " << std::endl;
	std::cout << "Enter the matrikel number of the student to search for:" << std::endl;
	std::cin >> matrikelNumber;
	std::map<int,Student>::iterator it;
	for(it = students.begin();it!= students.end(); it++)
	{
		if(it == students.find(matrikelNumber))
		{
			std::cout << "Enter the data field to be updated:" << std::endl;
			std::cout << "0 : terminate" << std::endl;
			std::cout << "1 : first name" << std::endl;
			std::cout << "2 : last name" << std::endl;
			std::cout << "3 : Address " << std::endl;
			std::cout << "4 : DOB " << std::endl;
			std::cout << "5 : Update Enrollments " << std::endl;
			std::cin >> updateCode;

			switch(updateCode)
			{
			case 0:{
				break;
			}
			case 1:{
				std::string firstName;
				std::cout << "Enter new value for FirstName : " << std::endl;
				std::cin >> firstName;
				it->second.setFirstName(firstName) ;
				break;
			}
			case 2:{
				std::string lastName;
				std::cout << "Enter new value for LastName : " << std::endl;
				std::cin >> lastName;
				it->second.setLastName(lastName) ;
				break;
			}
			case 3:{
				std::string street,cityName,additionalInfo;
				unsigned short postalCode;
				std::cout << "Enter new Address : " << std::endl;
				std::cout << "streetName:" << std::endl;
				std::cin.ignore();
				std::getline(std::cin, street);
				std::cout << "cityName:" << std::endl;
				std::cin.ignore(0);
				std::getline(std::cin, cityName);
				std::cout << "postalCode:" << std::endl;
				std::cin >> postalCode;
				std::cout << "additionalInfo:" << std::endl;
				std::cin.ignore();
				it->second.setAddress(street, cityName, postalCode, additionalInfo);
				break;
			}
			case 4:{
				int day,month,year;
				Poco::Data::Date dateOfBirth;
				std::cout << "Enter DOB to be updated : (format: YYYY MM DD) " << std::endl;
				std::cin >> year >> month >> day;
				dateOfBirth.assign(year, month, day);
				it->second.setDateOfBirth(dateOfBirth);
				break;
			}
			case 5:{
				float gradePoints;
				unsigned int courseKey;
				int updateCommand;
				std::cout << "Enter 1 for Remove and 2 for update Enrollment :" << std::endl;
				std::cin >> updateCommand;

				if(updateCommand == 1)
				{
					std::cout << "Enter courseKey to enrollment : " << std::endl;
					std::cin >> courseKey;
					it->second.removeEnrollments(courseKey);
				}
				else if(updateCommand == 2)
				{
					std::cout << "Enter courseKey to enrollment : " << std::endl;
					std::cin >> courseKey;
					std::cout << "Enter gradePoints to be updated : " << std::endl;
					std::cin >> gradePoints;
					it->second.updateEnrollments(courseKey, gradePoints);
				}
				else
					std::cout << "Wrong command entered." << std::endl;

				break;
			}
			}
		}
	}
}



void StudentDb::read(std::istream &in)
{
	courses.clear();
	students.clear();

	std::cout << "        Read student Info from file        " << std::endl;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;

	Poco::DateTime::DaysOfWeek dayOfWeek;
	Poco::Data::Date dateOfBirth;
	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
	Poco::Data::Date startDate;
	Poco::Data::Date endDate;

	int day,month,year,hour,min,sec;
	unsigned short postalCode;
	unsigned int courseKey;
	std::string fName,lName,street,cityName,additionalInfo;
	std::string major,title,sem;
	char courseType;
	int creditPoints;
	std::vector<std::string>   result;


	std::string line = "",currentStream,delimiter =";";
	std::getline(in,line,'\n');
	currentStream = line;
	int lineLength = line.length();
	if(lineLength <= 2)
	{
		int courseCount = stoi(currentStream);
		for(int index =0; index < courseCount; index++)
		{
			std::getline(in,currentStream,'\n');

			size_t pos = 0;
			std::string token;
			int switchCount = -1;
			courseType = currentStream[0];
			if(courseType == 'W')
			{
				for(int courseIndex =0; courseIndex < 8; courseIndex++)
				{
					//read the value until the delimiter is found and store
					//the value in token
					while ((pos = currentStream.find(delimiter)) != std::string::npos) {
						token = currentStream.substr(0, pos);
						currentStream.erase(0, pos + delimiter.length());
						switchCount++;
						switch(switchCount)
						{
						case 1: {
							courseKey = stoi(token);							break;
						}
						case 2: {
							title = token;
							break;
						}
						case 3: {
							major = token;
							break;
						}
						case 4: {
							creditPoints = stoi(token);
							break;
						}
						case 5: {
							int tempDay = stoi(token);
							dayOfWeek = Poco::DateTime::DaysOfWeek(tempDay);
							break;
						}
						case 6: {
							std::stringstream tempData(token);
							std::string line;
							std::getline(tempData,line,'.');
							hour = atoi(line.c_str());
							std::getline(tempData,line,'.');
							min = atoi(line.c_str());
							std::getline(tempData,line,' ');
							sec = atoi(line.c_str());
							startTime.assign(hour,min,sec);
							break;
						}
						case 7: {
							std::stringstream tempData(token);
							std::string line;
							std::getline(tempData,line,'.');
							hour = atoi(line.c_str());
							std::getline(tempData,line,'.');
							min = atoi(line.c_str());
							std::getline(tempData,line,' ');
							sec = atoi(line.c_str());
							endTime.assign(hour,min,sec);
							break;
						}
						}


					}
				}
				//update the course data into the Course map
				std::unique_ptr<const Course> newCourse = std::unique_ptr<const Course>(new WeeklyCourse(courseKey,major, title,creditPoints,
						dayOfWeek,startTime,endTime));
				courses.insert(std::pair<int,std::unique_ptr<const Course>>(courseKey,std::move(newCourse)));
			}
			else
				if(courseType == 'B')
				{
					for(int courseIndex =0; courseIndex < 9; courseIndex++)
					{
						while ((pos = currentStream.find(delimiter)) != std::string::npos) {
							token = currentStream.substr(0, pos);
							currentStream.erase(0, pos + delimiter.length());
							switchCount++;
							switch(switchCount)
							{
							case 1: {
								courseKey = stoi(token);							break;
							}
							case 2: {
								title = token;
								break;
							}
							case 3: {
								major = token;
								break;
							}
							case 4: {
								creditPoints = stoi(token);
								break;
							}
							case 5: {
								std::stringstream tempData(token);
								std::string line;
								std::getline(tempData,line,'.');
								day = atoi(line.c_str());
								std::getline(tempData,line,'.');
								month = atoi(line.c_str());
								std::getline(tempData,line,' ');
								year = atoi(line.c_str());
								startDate.assign(year,month,day);
								break;
							}
							case 6: {
								std::stringstream tempData(token);
								std::string line;
								std::getline(tempData,line,'.');
								day = atoi(line.c_str());
								std::getline(tempData,line,'.');
								month = atoi(line.c_str());
								std::getline(tempData,line,' ');
								year = atoi(line.c_str());
								endDate.assign(year,month,day);
								break;
							}
							case 7: {
								std::stringstream tempData(token);
								std::string line;
								std::getline(tempData,line,'.');
								hour = atoi(line.c_str());
								std::getline(tempData,line,'.');
								min = atoi(line.c_str());
								std::getline(tempData,line,' ');
								sec = atoi(line.c_str());
								startTime.assign(hour,min,sec);
								break;
							}
							case 8: {
								std::stringstream tempData(token);
								std::string line;
								std::getline(tempData,line,'.');
								hour = atoi(line.c_str());
								std::getline(tempData,line,'.');
								min = atoi(line.c_str());
								std::getline(tempData,line,' ');
								sec = atoi(line.c_str());
								endTime.assign(hour,min,sec);
								break;
							}
							}


						}
					}
					//update course data into Course map
					std::unique_ptr<const Course> newCourse = std::unique_ptr<const Course>(new BlockCourse(courseKey, major,title,creditPoints,
							startDate,endDate,startTime,endTime));
					courses.insert(std::pair<int,std::unique_ptr<const Course>>(courseKey,std::move(newCourse)));
				}
		}
	}

	// student data read from the file
	//Read each line and segregate the fields based on delimiter
	std::getline(in,line,'\n');
	currentStream = line;
	lineLength = line.length();
	if(lineLength <= 2)
	{
		int studentCount = stoi(currentStream);
		for(int index =0; index < studentCount; index++)
		{
			std::getline(in,currentStream,'\n');
			size_t pos = 0;

			std::string token;
			int switchCount = 0;
			courseType = currentStream[0];

			for(int courseIndex =0; courseIndex < 7; courseIndex++)
			{
				while ((pos = currentStream.find(delimiter)) != std::string::npos) {
					token = currentStream.substr(0, pos);
					currentStream.erase(0, pos + delimiter.length());
					switchCount++;
					switch(switchCount)
					{

					case 2: {
						fName = token;
						break;
					}
					case 3: {
						lName = token;
						break;
					}
					case 4: {
						std::stringstream tempData(token);
						std::string line;
						std::getline(tempData,line,'.');
						day = atoi(line.c_str());
						std::getline(tempData,line,'.');
						month = atoi(line.c_str());
						std::getline(tempData,line,' ');
						year = atoi(line.c_str());
						dateOfBirth.assign(year,month,day);

						break;
					}
					case 5: {
						street = token.find(' ');
						cityName = token;
						break;
					}
					case 6: {
						postalCode = stoi(token);
						break;
					}
					case 7: {
						additionalInfo = token;
						break;
					}
					}
				}
			}

			Student newStudent(fName,lName,dateOfBirth,additionalInfo,street,cityName,postalCode);
			int matrklNr = newStudent.getNextFreeMatrikelNumber();
			students.insert (std::pair<int,Student>(matrklNr,{newStudent.getFirstName(),
					newStudent.getLastName(),newStudent.getDateOfBirth(),
					newStudent.getAddress()->getAdditionalInfo(),
					newStudent.getAddress()->getStreet(),
					newStudent.getAddress()->getCityName(),
					newStudent.getAddress()->getPostalCode()}));
		}
	}

	//enrollment data read from the file.

	std::getline(in,line,'\n');
	currentStream = line;

	lineLength = line.length();
	if(lineLength <= 2)
	{
		//count no. of enrollments to read
		int enrollmentCount = stoi(currentStream);
		for(int index =0; index < enrollmentCount; index++)
		{
			std::getline(in,currentStream,'\n');
			size_t pos = 0;

			std::string token;

			int switchCount = 0;
			courseType = currentStream[0];

			for(int courseIndex =0; courseIndex < 4; courseIndex++)
			{
				while ((pos = currentStream.find(delimiter)) != std::string::npos) {
					token = currentStream.substr(0, pos);
					currentStream.erase(0, pos + delimiter.length());
					switchCount++;
					switch(switchCount)
					{
					case 2: {
						courseKey = stoi(token);
						break;
					}
					case 3: {
						sem = token;
						break;
					}
					}


				}
			}
			//find the courseKey in Course map
			std::map<int,std::unique_ptr<const Course>>::const_iterator courseIter;
			courseIter = courses.find(courseKey);
			if(courseIter != courses.end())
			{
				//update enrollment data for specified courseKey
				std::map<int,Student>::iterator it;
				for(it = students.begin();it!= students.end(); it++)
					it->second.setEnrollments(courseKey, sem, courseIter->second.get());
			}

		}

	}
	std::cout << "Data successfully read from the file. " << std:: endl;
}

void StudentDb::write(std::ostream& out)
{
	std::cout << "        Write student Info into file        " << std::endl;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	int studentsCount,coursesCount;
	coursesCount = courses.size();

	//print the number of course data
	out << coursesCount << std::endl;
	std::map<int,std::unique_ptr<const Course>>::const_iterator courseIter;
	for(courseIter = courses.begin();courseIter != courses.end(); courseIter++)
	{
		//iterate through each course and print all data
		courseIter->second.get()->write(out);
	}

	studentsCount = students.size();
	//print the number of students data
	out << studentsCount << std::endl;

	std::map<int,Student>::iterator studentIter;
	for(studentIter = students.begin();studentIter!= students.end(); studentIter++)
	{
		//iterate through each student and print all data
		studentIter->second.write(out) ;
	}

	std::cout << "Student data successfully written into file." << std::endl;
}

void StudentDb::serverConnect()
{
	std::cout << "        Fetch student data from server      " << std::endl;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	std::cout << std::endl;
	int studentCount;
	std::cout << "Please enter the number of student data to be fetched:" << std::endl;
	std::cin >> studentCount;

	for(int studentIndex =0;studentIndex < studentCount; studentIndex++ )
	{

		//provide host and port address to establish server connection
		Poco::Net::SocketAddress sa("www.mnl.de", 4242);
		Poco::Net::StreamSocket socket(sa);
		Poco::Net::SocketStream str(socket);

		//send generate command to fetch data
		str << "generate" << "\n";
		str.flush();
		socket.shutdownSend();

		std::string line1,line2,line3;

		//store 100 generating and ignore
		std::getline(str,line1);

		//store the student details for further processing
		std::getline(str,line2);

		//store 200 generated and ignore
		std::getline(str,line3);
		std::cout << "Connected to server. " << std::endl;

		//sutdown the socket once data receive is done.
		socket.shutdownReceive();

		//parse through json data received from server and assign
		//data to respective variables

		try{
			std::string json = line2;
			Poco::JSON::Parser jsonParser;
			Poco::Dynamic::Var serverData = jsonParser.parse(json);
			Poco::JSON::Object::Ptr jsonObject = serverData.extract<Poco::JSON::Object::Ptr>();
			Poco::DynamicStruct ds = *jsonObject;

			std::string dateOfBirthDate = ds["dateOfBirth"]["date"];
			std::string dateOfBirthMonth = ds["dateOfBirth"]["month"];
			std::string dateOfBirthYear = ds["dateOfBirth"]["year"];
			std::string cityName = ds["location"]["city"];
			std::string street = ds["location"]["street"];
			std::string additionalInfo = ds["location"]["state"];
			std::string postalcode = ds["location"]["postCode"];
			std::string firstName = ds["name"]["firstName"];
			std::string lastName = ds["name"]["lastName"];
			Poco::Data::Date dateOfBirth;
			int dobDate, dobMonth, dobYear;

			dobDate = atoi(dateOfBirthDate.c_str());
			dobMonth = atoi(dateOfBirthMonth.c_str());
			dobYear = atoi(dateOfBirthYear.c_str());

			dateOfBirth.assign(dobYear,dobMonth,dobDate);
			unsigned short postalCode = atoi(postalcode.c_str());


			if((0 == dobDate) || (0 == dobYear) || (0 == dobMonth) || (0 == postalCode))
				throw 99;

			//push all the data from the server into the student database
			Student newStudent(firstName,lastName,dateOfBirth,additionalInfo,street,cityName,postalCode);
			int matrklNr = newStudent.getNextFreeMatrikelNumber();
			students.insert (std::pair<int,Student>(matrklNr,{newStudent.getFirstName(),
					newStudent.getLastName(),newStudent.getDateOfBirth(),
					newStudent.getAddress()->getAdditionalInfo(),
					newStudent.getAddress()->getStreet(),
					newStudent.getAddress()->getCityName(),
					newStudent.getAddress()->getPostalCode()}));
		}
		catch(int errCode){
			std::cout << "Invalid data received from the server" << std::endl;
		}
		catch(...) {
			std::cout << "Parsing of data was unsuccessful. Please recheck." << std::endl;
		}

		std::cout << "data fetched from the server and updated to database." << std::endl;

		//terminate server connection.
		str << "quit" << "\n";
		str.flush();
		socket.close();
	}
}
