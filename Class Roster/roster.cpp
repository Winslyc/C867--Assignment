#include "roster.h"
#include<iostream>
#include<string>
#include<sstream>
#include "student.h"

//A. MODIFIED STUDENT DATA TABLE -
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Winsly,Cyrius,Cyriuswinsly0415@gmail.com,19,35,23,51,SOFTWARE"
	};
	Roster::Roster() {

	}
	//E2.A Parse through studentData one row at a time.
	void Roster::parse(string row) {
		size_t fUsed = row.find(",");
		string studentID = row.substr(0, fUsed);

		size_t lUsed = fUsed + 1;
		fUsed = row.find(",", lUsed);
		string firstName = row.substr(lUsed, fUsed - lUsed);

		lUsed = fUsed + 1;
		fUsed = row.find(",", lUsed);
		string lastName = row.substr(lUsed, fUsed - lUsed);

		lUsed = fUsed + 1;
		fUsed = row.find(",", lUsed);
		string emailAddress = row.substr(lUsed, fUsed - lUsed);
		
		lUsed = fUsed + 1;
		fUsed = row.find(",", lUsed);
		int age = stoi(row.substr(lUsed, fUsed - lUsed));

        lUsed = fUsed + 1;
        fUsed = row.find(",", lUsed);
        int daysInCourse1 = stoi(row.substr(lUsed, fUsed - lUsed));

        lUsed = fUsed + 1;
        fUsed = row.find(",", lUsed);
        int daysInCourse2 = stoi(row.substr(lUsed, fUsed - lUsed));

        lUsed= fUsed + 1;
        fUsed = row.find(",", lUsed);
        int daysInCourse3 = stoi(row.substr(lUsed, fUsed - lUsed));

        lUsed = fUsed + 1;
        fUsed = row.find(",", lUsed);
        string degreeprogram = row.substr(lUsed, fUsed - lUsed);

        DegreeProgram dp;
        if (degreeprogram == "SECURITY") {
            dp = DegreeProgram::SECURITY;
        }
        else if (degreeprogram == "NETWORK") {
            dp = DegreeProgram::NETWORK;
        }
        else {
            dp = DegreeProgram::SOFTWARE;
        }
		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, dp);
	
		return;
}

	void Roster::parseInitStudentData() {
		for (int i = 0; i < 5; i++) {
			parse(studentData[i]);
		}
	}

	// E3.A ADD FUNCTION
	void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
	// add students to classRosterArray
	lastIndex++;
	int arr[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[lastIndex] = new student(studentID, firstName, lastName, emailAddress, age, arr, degreeprogram);

	return;
}
	//E3.B REMOVE FUNCTION
	void Roster::remove(string studentID)
{
	//loop through array to find student ID if found then remove from array.
	bool find = false;
	int i = 0;
	while (find != true && i < numStudents) {


		if (classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			find = true;
			for (int j = i; j < numStudents - 1; j++) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			numStudents--;

		}
		else {
			i++;
		}
	} if (find != true) {
		cout << "A student with the id " << studentID << " was not found.";
	} 

	return;
}

	//E3.C PRINT ALL FUNCTION
	void Roster::printAll()
{ 
	for (int i = 0; i < numStudents; i++) {
		classRosterArray[i]->printData(student::STUDENTID);
		classRosterArray[i]->printData(student::FIRSTNAME);
		classRosterArray[i]->printData(student::LASTNAME);
		classRosterArray[i]->printData(student::AGE);
		classRosterArray[i]->printData(student::EMAILADDRESS);
		classRosterArray[i]->printData(student::NUMDAYS);
		classRosterArray[i]->printData(student::DEGREEPROGRAM);
	}
}
	//GET CLASSROSTER
	student* Roster::getClassRosterArray() {
	return *classRosterArray;
	}

	//E3.D PRINT AVERAGE DAYS IN COURSE FUNCTION.
	void Roster::printAverageDaysInCourse(string studentID)
{
	int total = 0;
	int avgCourse;
		for (int i = 0; i < numStudents; i++) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				total = classRosterArray[i]->getNumDaysToComplete()[0] + classRosterArray[i]->getNumDaysToComplete()[1] + classRosterArray[i]->getNumDaysToComplete()[2];
			}
		}

		avgCourse = total / 3;

		cout << "Student ID: " << studentID << ", average days in course is: ";
		cout << avgCourse << endl;

		return;
}

	//E3.E PRINT INVALID EMAILS FUNCTION
	void Roster::printInvalidEmails()
{
	string test;

	for (int i = 0; i < numStudents; i++) {
		test = classRosterArray[i]->getEmailAddress();
		if (test.find(' ') != string::npos) {
			cout << test << " - is invalid." << endl;
		}
		if (test.find('.') == string::npos) {
			cout << test << " - is invalid." << endl;
		}
		if (test.find('@') == string::npos) {
			cout << test << " - is invalid." << endl;
		}
	}

	return;
}
	
	//E3.F PRINT BY DEGREE PROGRAM 
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {

			classRosterArray[i]->printData(student::STUDENTID);
			classRosterArray[i]->printData(student::FIRSTNAME);
			classRosterArray[i]->printData(student::LASTNAME);
			classRosterArray[i]->printData(student::AGE);
			classRosterArray[i]->printData(student::EMAILADDRESS);
			classRosterArray[i]->printData(student::NUMDAYS); 
			classRosterArray[i]->printData(student::DEGREEPROGRAM);
		}
	
	}
	return;
}



Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
	}
	return;
}

