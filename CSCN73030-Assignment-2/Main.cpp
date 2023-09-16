#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

#define PRE_RELEASE

#ifdef PRE_RELEASE
#include "StudentDataEmails.h"
#else
#include "StudentData.h"
#endif

int main()
{
	std::vector<STUDENT_DATA> studentData;
	char* buffer = nullptr;
	std::string path;
	std::stringstream sstream;
	std::string firstName;
	std::string lastName;
	std::string email;
	std::streampos size = 0;
	std::ifstream ifStreamIn;

#ifdef PRE_RELEASE

	path = "./StudentData_Emails.txt";

#else
	path = "./StudentData.txt";
#endif

	ifStreamIn = std::ifstream(path, std::ios_base::in);

	if (ifStreamIn.is_open())
	{
		ifStreamIn.seekg(0, ifStreamIn.end);
		size = ifStreamIn.tellg();
		ifStreamIn.seekg(0, ifStreamIn.beg);

		buffer = new char[size];
		if (buffer)
		{
			memset(buffer, 0, size);
			ifStreamIn.read(buffer, size);
			sstream = std::stringstream(buffer);
		}
		else
			return 1;

	}

#ifdef PRE_RELEASE
	std::cout << "Running: pre-release" << std::endl;

	while (std::getline(sstream, lastName, ','))
	{
		STUDENT_DATA student;

		std::getline(sstream, firstName, ',');
		std::getline(sstream, email, '\n');

		student.firstName = firstName;
		student.lastName = lastName;
		student.email = email;
		studentData.push_back(student);

#ifdef _DEBUG
		std::cout << "Student: " << student.firstName << ", " << student.lastName << ", " << student.email << std::endl;
#endif
	}

#else
	std::cout << "Running: standard" << std::endl;

	while (std::getline(sstream, lastName, ','))
	{
		STUDENT_DATA student;

		std::getline(sstream, firstName, '\n');

		student.firstName = firstName;
		student.lastName = lastName;
		studentData.push_back(student);

#ifdef _DEBUG
		std::cout << "Student: " << student.firstName << ", " << student.lastName << std::endl;
#endif
	}
#endif
	delete buffer;
	return 0;
}