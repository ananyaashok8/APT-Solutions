/*
 * SimpleUI.cpp
 *
 *  Created on: 15-Jan-2022
 *      Author: Ananya Ashok
 */

#include "SimpleUI.h"
#include "StudentDb.h"
#include <iostream>


SimpleUI::SimpleUI(StudentDb &db)
{
	dbPtr = &db;
}

void SimpleUI::run()
{

	int command ;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << "Please choose the action to perform:" << std::endl;
	std::cout << " 1.Add new Course." << std::endl;
	std::cout << " 2.List courses." << std::endl;
	std::cout << " 3.Add new student." << std::endl;
	std::cout << " 4.Add enrollment." << std::endl;
	std::cout << " 5.Print student." << std::endl;
	std::cout << " 6.Search student." << std::endl;
	std::cout << " 7.Update student." << std::endl;
	std::cout << " 8.Write student data using a file." << std::endl;
	std::cout << " 9.Read student data using a file." << std::endl;
	std::cout << "10.Establish a connection and get data from host server."
			  << std::endl;

	std::cin >> command;

	if((command > 0) && (command <= 10))
	{
		switch(command)
		{
		case 1:{
			dbPtr->addNewCourse();
			break;
		}
		case 2:{
			dbPtr ->printCourses();
			break;
		}
		case 3:{
			dbPtr ->addNewStudentData();
			break;
		}
		case 4:{
			dbPtr ->addNewEnrollment();
			break;
		}
		case 5:{
			dbPtr ->printStudent();
			break;
		}
		case 6:{
			dbPtr ->searchStudent();
			break;
		}
		case 7:{
			dbPtr ->updatestudent();
			break;
		}
		case 8:{
			std::cout << "Enter the file name to write into:" << std::endl;
			std::string fileName;
			std::cin >> fileName;

			std::ofstream fileOpen;
			fileOpen.open(fileName);

			dbPtr ->write(fileOpen);
			fileOpen.close();
			break;
		}
		case 9:{
			std::cout << "Enter the file name to read from:" << std::endl;
						std::string fileName;
						std::cin >> fileName;

						std::ifstream fileOpen;
						fileOpen.open(fileName);

						dbPtr ->read(fileOpen);
						fileOpen.close();
			break;
		}
		case 10:{
			dbPtr->serverConnect();
		}
		}
	}
	else
		std::cout << "Please choose a command between 1-9" << std::endl;

}
