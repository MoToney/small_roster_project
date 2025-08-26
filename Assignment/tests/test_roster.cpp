#include <iostream>
#include "roster.h"
#include "roster.cpp"
#include "student.h"
#include "student.cpp"


using namespace std;

void runTests() {
    // Create a Roster instance
    Roster classRoster;

    // Add students to the roster
    cout << "\n*** Adding Students ***" << endl;
    classRoster.add("A1", "John", "Doe", "john.doe@email.com", 20, 30, 35, 40, SOFTWARE);
    classRoster.add("A2", "Jane", "Smith", "jane.smith@email.com", 22, 25, 30, 35, SECURITY);
    classRoster.add("A3", "Emily", "Davis", "emily.davis@email.com", 19, 50, 40, 30, NETWORK);

    // Print all students
    cout << "\n*** Printing All Students ***" << endl;
    classRoster.printAll();

    // Print average days in course for a specific student
    cout << "\n*** Printing Average Days in Course for Student A1 ***" << endl;
    classRoster.printAverageDaysInCourse("A1");

    // Remove a student
    cout << "\n*** Removing Student A2 ***" << endl;
    classRoster.remove("A2");

    // Try removing the same student again (should show error)
    cout << "\n*** Attempting to Remove Non-Existent Student A2 ***" << endl;
    classRoster.remove("A2");

    // Print all students again to verify removal
    cout << "\n*** Printing All Students After Removal ***" << endl;
    classRoster.printAll();
}

int main() {
    runTests();
    return 0;
}