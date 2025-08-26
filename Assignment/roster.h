#pragma once

#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class Roster {
    public:
        Roster();
        ~Roster();
        void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
        void remove(string studentID);
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
        void parseData(string studentData[]);
        DegreeProgram castDegreeProgram(string degree);
        Student** getClassRosterArray();
    

    private:
        const int MAX_STUDENTS = 5;
        Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
};

