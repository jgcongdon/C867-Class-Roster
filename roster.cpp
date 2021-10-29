#include "roster.h"
#include "student.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
using std::cout;
using std::cerr;
using namespace std;

Roster::Roster()
{
    this->capacity = 0;
    this->lastIndex = -1;
    this->students = nullptr;
}

Roster::Roster(int capacity)
{
    this->capacity = capacity;
    this->lastIndex = -1;
    this->students = new Student * [capacity];
}

void Roster::add(string ID, string firstName, string lastName, string email, int age, int daysCourse1, int daysCourse2, int daysCourse3, Degree degree) {
    int daysCourse[3] = { daysCourse1, daysCourse2, daysCourse3 };
    switch (degree) {
    case NETWORK:
        classRosterArray[index] = new networkStudent(ID, firstName, lastName, email, age, daysCourse, degree);
        break;
    case SECURITY:
        classRosterArray[index] = new securityStudent(ID, firstName, lastName, email, age, daysCourse, degree);
        break;
    case SOFTWARE:
        classRosterArray[index] = new softwareStudent(ID, firstName, lastName, email, age, daysCourse, degree);
        break;
    }
    index++;
}

void Roster::remove(string studentID) {
    cout << "Removing Student ID: " << studentID << endl;
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] == nullptr) {
            cout << "Error: matching Student ID was not found." << endl;
        }
        else if (studentID == classRosterArray[i]->getID()) {
            classRosterArray[i] = nullptr;
            cout << "Student ID successfully removed." << endl;
        }
    }
};

void Roster::printInvalidEmails() {
    for (int i = 0; i < numStudents; i++) {
        string emailAddress = classRosterArray[i]->getEmailAddress();
        if ((emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos)) {
            cout << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << ": " << classRosterArray[i]->getEmailAddress() << endl;
        }
    }
}

void Roster::printDaysInCourse(string studentID) {
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] != nullptr) {
            if (classRosterArray[i]->getID() == studentID) {
                const int* classes = classRosterArray[i]->getDaysCourse();
                int average = (classes[0] + classes[1] + classes[2]) / 3;
                cout << studentID << " average: " << average << "\t" << endl;
            }
        }
    }
};

void Roster::printByDegreeProgram(int dType) {
    cout << "Printing by Degree program:" << endl;
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray != nullptr) {
            if (classRosterArray[i]->getDegree() == dType) {
                classRosterArray[i]->print();
            }
        }
    }
}

void Roster::printAll() {
    for (int i = 0; i < 5; i++) {
        (*classRosterArray[i]).print();
    }
    cout << '\n';
}

Roster::~Roster() {
};

int main() {
    cout << "Scripting and Programming Applications C867" << endl;
    cout << "C++" << endl;
    cout << "001010008" << endl;
    cout << "Jackson Congdon" << endl << endl;

    Roster classRoster;
    Degree degree;

    string output, col[DATA_COLUMNS];

    for (int i = 0; i < numStudents; i++) {
        std::istringstream input(studentData[i]);
        for (int j = 0; j < DATA_COLUMNS; ++j) {
            std::getline(input, output, ',');
            col[j] = output;
        }

        switch (col[8][2]) {
        case 'T':
            degree = NETWORK;
            break;
        case 'C':
            degree = SECURITY;
            break;
        case 'F':
            degree = SOFTWARE;
            break;
        }

        classRoster.add(col[0], col[1], col[2], col[3], std::stoi(col[4]), std::stoi(col[5]), std::stoi(col[6]), std::stoi(col[7]), degree);
    }

    cout << "Roster: " << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Invalid Emails: " << endl;
    classRoster.printInvalidEmails();
    cout << endl << endl;

    cout << "Average number of days in three courses for each student: " << endl;
    for (int i = 0; i < numStudents; i++) {
        classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getID());
    }
    cout << endl;

    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    classRoster.remove("A3");
    cout << endl;
    classRoster.remove("A3");
    cout << endl;

    classRoster.~Roster();
}