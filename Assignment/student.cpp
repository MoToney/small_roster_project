#include <iostream>
#include <string>
using namespace std;
#include "degree.h"
#include "student.h"

// overloaded constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,  int daysInCourse2,  int daysInCourse3, DegreeProgram degreeProgram){
    studentIdentification = studentID;
    studentFirstName = firstName;
    studentLastName = lastName;
    studentEmailAddress = emailAddress;
    studentAge = age;
    daysArray[0] = daysInCourse1;
    daysArray[1] = daysInCourse2;
    daysArray[2] = daysInCourse3;
    studentDegreeProgram = degreeProgram; 
};

Student::~Student() {
    
}

// setter methods
void Student::setStudentID(string studentID) {
    studentIdentification = studentID;
}
void Student::setFirstName(string firstName) {
    studentFirstName = firstName;
}
void Student::setLastName(string lastName) {
    studentLastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
    studentEmailAddress = emailAddress;
}
void Student::setAge(int age) {
    studentAge = age;
}
void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    daysArray[0] = daysInCourse1;
    daysArray[1] = daysInCourse2;
    daysArray[2] = daysInCourse3;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    studentDegreeProgram = degreeProgram;
}

// getter methods 
string Student::getStudentID() {
    return studentIdentification;
}
string Student::getFirstName() {
    return studentFirstName;
}
string Student::getLastName() {
    return studentLastName;
}
string Student::getEmailAddress() {
    return studentEmailAddress;
}
int Student::getAge() {
    return studentAge;
}
int* Student::getDaysInCourse() {
    return daysArray;
}
DegreeProgram Student::getDegreeProgram() {
    return studentDegreeProgram;
}

// print method
string Student::printDegreeProgram() {
    switch (studentDegreeProgram) {
        case SECURITY: return "Security";
        case NETWORK: return "Network";
        case SOFTWARE: return "Software";
        default: return "Unknown";
    }
}

void Student::print() {
    cout << "Student ID: " << studentIdentification << "\t" <<
    "First name: " << studentFirstName << "\t" <<
    "Last name: " << studentLastName << "\t" <<
    "Email address: " << studentEmailAddress << "\t" <<
    "Age (years): " << studentAge << "\t" <<
    "Days in Course: {" << daysArray[0] << ", " << daysArray[1] << ", " << daysArray[2] << "}" << "\t" <<
    "Degree Program: " << printDegreeProgram() << endl;
}

float Student::avgDaysInCourse() {
    int total = 0;
    for (int i = 0; i < MAX_COURSES; i++) {
        total = total + daysArray[i];
    }
    return static_cast<float>(total) / MAX_COURSES;
}

string Student::isEmailInvalid() {
    if (studentEmailAddress.find(" ") != string::npos || studentEmailAddress.find("@") == string::npos) {
        return studentEmailAddress; 
    }

    size_t index = studentEmailAddress.find("@");

    if (studentEmailAddress.find(".", index + 1) == string::npos) {
        return studentEmailAddress; 
        }
    
    return "";
    }
