#pragma once
#include<string>
#include "degree.h"

using namespace std;
class student
{
//D.1 DECLARING PRIVATE VARIABLES FOR STUDENT CLASS
private:
	int  age;
	string studentID, firstName, lastName, emailAddress;
	int numDaysToComplete[3];
	DegreeProgram degree;
	
public:
	//D2.A DECLARING ACCESSOR METHODS
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getNumDaysToComplete();
	DegreeProgram getDegreeProgram();

	//D2.B DECLARING MUTATOR METHODS
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string email);
	void setAge(int age);
	void setNumDaysToComplete(int numdays[]);
	void setDegreeProgram(DegreeProgram program);

	//D2.D DECLARE CONSTRUCTORS FOR STUDENT CLASS
	student(string studentId, string firstName, string lastName, string emailAddress,int age, int numDaysToComplete[3], DegreeProgram degree);

	
	
	//D2.E print function for printing student data. Create enum to use int values to represent strings. for the switch.
	enum variables {
		STUDENTID = 0,
		FIRSTNAME = 1,
		LASTNAME = 2,
		EMAILADDRESS = 3,
		AGE = 4,
		NUMDAYS = 5,
		DEGREEPROGRAM = 6
	};
	//DECLARE VARIABLE CHOICES FOR PRINT DATA
	void printData(variables choice);

	
};
