#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include "StudentData.h"

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

	path = "./StudentData.txt";

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

	delete buffer;
	return 0;
}