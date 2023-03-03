#include "student.h"
#include <iostream>
using namespace std;


// D2.D CONSTRUCTOR INITIALIZATION
student::student(string studentId, string firstName, string lastName, string emailAddress, int age, int numDaysToComplete[3], DegreeProgram degree)
{
	this->studentID = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	setNumDaysToComplete(numDaysToComplete);
	this->degree = degree;
}

//D2.A GETTER METHODS
string student::getStudentID()
{
	return studentID;
}

int student::getAge()
{
	return age;
}

string student::getFirstName()
{
	return firstName;
}

string student::getLastName()
{
	return lastName;
}

string student::getEmailAddress()
{
	return emailAddress;
}

int* student::getNumDaysToComplete()
{

	return numDaysToComplete;
}

DegreeProgram student::getDegreeProgram()
{
	return degree;
}

//D2.B SETTER METHODS 
void student::setStudentID(string ID) 
{
	this->studentID = ID;
}

void student::setAge(int age)
{
	this->age = age;
}

void student::setNumDaysToComplete(int numdays[])
{
	for (int i = 0; i < 3; i++) {
		numDaysToComplete[i] = numdays[i];
	}
}

void student::setDegreeProgram(DegreeProgram program)
{
	this->degree = program;
}

void student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void student::setEmailAddress(string email)
{
	this->emailAddress = email;
}

//D2.E PRINT FUNCTION 
void student::printData(variables CHOICE)
{
	switch (CHOICE) {
	case 0:
		cout << "The Student ID is " << this->getStudentID() << ". ";
		break;
	case 1:
		cout << "First Name: " << this->getFirstName();
		break;
	case 2:
		cout << " Last Name: " << this->getLastName();
		break;
	case 3:
		cout << " Email Address: " << this->getEmailAddress() << " ";
		break;
	case 4:
		cout << " Age: " << this->getAge();
		break;
	case 5:
		cout << " {"<< this->getNumDaysToComplete()[0] << ", " << this->getNumDaysToComplete()[1
	] << ", " << this->getNumDaysToComplete()[2] <<"} ";
		break;
	case 6:
		DegreeProgram dp = this->getDegreeProgram();
		string ret;
		if (dp == DegreeProgram::SECURITY) {
			ret = "Security";
		}
		else if (dp == DegreeProgram::NETWORK) {
			ret = "Network";
		}
		else {
			ret = "Software";
		}
		cout << "Degree Program: " << ret << endl;
		break;

	}
}
