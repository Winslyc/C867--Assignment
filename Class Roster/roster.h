#pragma once
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

class Roster
{
	//E.1 Create array of pointers students
private:
	int numStudents = 5;
	int lastIndex = -1;

public:
	Roster();
	//E1  CLASS ROSTER ARRAY.
	student* classRosterArray[5];

	//E.3.A add function
	void add(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);

	//E.3.B remove method
	 void remove(string studentID);
	 
	 //E.3.C print all method
	 void printAll();

	 student* getClassRosterArray();

	 //E.3.D print days in course
	 void printAverageDaysInCourse(string studentID);

	 //E.3.E  valid email checkers
	 void printInvalidEmails();

	 //E.3.F  prints out student information for degree program
	 void printByDegreeProgram(DegreeProgram degreeProgram);
	 //E2.A parse student data
	 void parseInitStudentData();
		 void parse(string row);

	 ~Roster();
};

