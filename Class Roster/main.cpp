#include "degree.h"
#include "student.h"
#include "roster.h"
#include <string>

using namespace std;
int main() {
	//F1
	const string intro = "C867 final Task \nLanguage: C++ \nWGU ID: 010520431   WINSLY CYRIUS ";

	cout << intro << endl;

	//F2
	Roster *roster = new Roster();

	// Adds all student data to classRoster
	roster->parseInitStudentData();
	//F4 TESTING FUNCTIONS 
	roster->printAll();
	cout << endl;
	roster->printInvalidEmails();
	cout << endl;
	roster->printByDegreeProgram(DegreeProgram::SOFTWARE);
	cout << endl;
	//loop through classRosterArray and for each element:
	for(int i = 0; i<5; i++){
		roster->printAverageDaysInCourse(roster->classRosterArray[i]->getStudentID());
	}
	roster->remove("A3");
	cout << endl;
	roster->printAll();
	cout << endl;
	roster->remove("A3");
	cout << endl;
	cout << "DONE";
}	