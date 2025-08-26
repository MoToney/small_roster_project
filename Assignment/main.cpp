
#include <iostream>
#include "roster.h"
#include "roster.cpp"
#include "student.h"
#include "student.cpp"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

main() {
    // 1.  Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    cout << "Course: Scripting and Programming - Applications C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Name: Mo" << endl << endl;

    const string studentData[] = 
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
    "A5,Maurice,Toney,mtoney12@wgu.edu,24,8,15,28,SOFTWARE"};

    const int SIZE = 5; 

    // 2.  Create an instance of the Roster class called classRoster.
    Roster classRoster;

    // 3.  Add each student to classRoster.
    classRoster.parseData(const_cast<string*>(studentData));

    classRoster.printAll();
    classRoster.printInvalidEmails();

    Student** classRosterArray = classRoster.getClassRosterArray(); // Now it's a pointer

    for (int i = 0; i < SIZE; i++) {
        if (classRosterArray[i] != nullptr) { // Ensure valid student object
            string studentID = classRosterArray[i]->getStudentID();
            classRoster.printAverageDaysInCourse(studentID);
        }
    }

    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}
