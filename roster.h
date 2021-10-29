#pragma once
#include <string>
#include <iostream>
#include "student.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "networkStudent.h"

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Jackson,Congdon,jcongd3@wgu.edu,30,45,53,39,SOFTWARE"
};

static const unsigned int DATA_COLUMNS = 9;
const int numStudents = 5;

class Roster {
private:
    int index = 0;


public:
    Roster();
    Roster(int capacity);

    Student* classRosterArray[5];

    int lastIndex;
    int capacity;
    Student** students;

    Student* getStudentAt(int index);

    void add(string studentId, string firstName, string lastName, string email, int age, int daysCourse1, int daysCourse2, int daysCourse3, Degree degree);
    void printAll();
    void remove(string studentID);
    void printDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(int degreeProgram);

    ~Roster();
};