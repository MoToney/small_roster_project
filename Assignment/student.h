#pragma once 

#include <string>
#include "degree.h"
using namespace std;

class Student {
    public:
        // overloaded constructor 
        Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,  int daysInCourse2,  int daysInCourse3, DegreeProgram degreeProgram);

        // destructor
        ~Student();
        
        //setters
        void setStudentID(string studentID);
        void setFirstName(string firstName);
        void setLastName(string lastName);
        void setEmailAddress(string emailAddress);
        void setAge(int age);
        void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
        void setDegreeProgram(DegreeProgram degreeProgram);
        
        
        //getters
        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAge();
        int* getDaysInCourse();
        DegreeProgram getDegreeProgram();
        
        //print
        void print();
        string printDegreeProgram();
        float avgDaysInCourse();
        string isEmailInvalid();

    private:
        string studentIdentification;
        string studentFirstName;
        string studentLastName;
        string studentEmailAddress;
        int studentAge;
        int daysArray[3];
        DegreeProgram studentDegreeProgram;
        const int MAX_COURSES = 3;

};
