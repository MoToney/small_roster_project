#include <iostream>
#include <cassert>  // For assertions
#include "student.h"
#include "student.cpp"

using namespace std;

void testStudentClass() {
    // Create a test student
    Student testStudent("S123", "John", "Doe", "john.doe@example.com", 21, 10, 15, 20, DegreeProgram::SOFTWARE);

    // Test Constructor & Getters
    assert(testStudent.getStudentID() == "S123");
    assert(testStudent.getFirstName() == "John");
    assert(testStudent.getLastName() == "Doe");
    assert(testStudent.getEmailAddress() == "john.doe@example.com");
    assert(testStudent.getAge() == 21);

    // Test daysInCourse array retrieval
    int* days = testStudent.getDaysInCourse();
    assert(days[0] == 10);
    assert(days[1] == 15);
    assert(days[2] == 20);

    // Test Degree Program
    assert(testStudent.getDegreeProgram() == DegreeProgram::SOFTWARE);

    // Test Setters
    testStudent.setStudentID("S456");
    assert(testStudent.getStudentID() == "S456");

    testStudent.setFirstName("Alice");
    assert(testStudent.getFirstName() == "Alice");

    testStudent.setLastName("Smith");
    assert(testStudent.getLastName() == "Smith");

    testStudent.setEmailAddress("alice.smith@example.com");
    assert(testStudent.getEmailAddress() == "alice.smith@example.com");

    testStudent.setAge(25);
    assert(testStudent.getAge() == 25);

    testStudent.setDaysInCourse(30, 40, 50);
    days = testStudent.getDaysInCourse();
    assert(days[0] == 30);
    assert(days[1] == 40);
    assert(days[2] == 50);

    testStudent.setDegreeProgram(DegreeProgram::SECURITY);
    assert(testStudent.getDegreeProgram() == DegreeProgram::SECURITY);

    // If all assertions pass, print success message
    cout << "All tests passed successfully!" << endl;
}

int main() {
    testStudentClass();
    return 0;
}