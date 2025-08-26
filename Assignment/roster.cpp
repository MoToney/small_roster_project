#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

Roster::Roster() {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        classRosterArray[i] = nullptr;
    }
}

Roster::~Roster() {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr; 
    }
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (classRosterArray[i] == nullptr) {
			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1,  daysInCourse2,  daysInCourse3, degreeProgram);

			return;
		}
	}
    cout << "Error: Roster full" << endl;
}    

void Roster::remove(string studentID){
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            return;
        }
    }
    cout << "Error: Student not found. " << endl;
}

Student** Roster::getClassRosterArray() {
    return classRosterArray;
}


void Roster::printAll(){
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID){
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            cout << "Average Days in Course: " << classRosterArray[i]->avgDaysInCourse() << endl; 
            return;
        }
    }
}



void Roster::printInvalidEmails(){
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (classRosterArray[i] != nullptr) {
            string invalidEmail = classRosterArray[i]->isEmailInvalid();
            if (invalidEmail != "") {
                cout << "Invalid email: " << invalidEmail << endl;
            }
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    for (int i = 0; i < MAX_STUDENTS; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

DegreeProgram Roster::castDegreeProgram(string degree) {
    if (degree == "SECURITY") {
        return SECURITY;
    } else if (degree == "NETWORK") {
        return NETWORK;
    } else if (degree == "SOFTWARE") {
        return SOFTWARE;
    }
    else {
        return ERROR;
    }
}

void Roster::parseData(string studentData[]) {
    for (int i = 0; i < MAX_STUDENTS; i++) {
        istringstream inSS(studentData[i]);
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        string degree;
        int age;
        int daysInCourse1;
        int daysInCourse2;
        int daysInCourse3;
        DegreeProgram degreeProgram;

        getline(inSS, studentID, ',');
        getline(inSS, firstName, ',');    
        getline(inSS, lastName, ',');        
        getline(inSS, emailAddress, ',');        
        inSS >> age; inSS.ignore();        
        inSS >> daysInCourse1; inSS.ignore();        
        inSS >> daysInCourse2; inSS.ignore();        
        inSS >> daysInCourse3; inSS.ignore();        
        getline(inSS, degree);    

        // Cast degree string to DegreeProgram enum
        degreeProgram = castDegreeProgram(degree);

        
         // Add the student to the roster using the add() function
        add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);


    }}
