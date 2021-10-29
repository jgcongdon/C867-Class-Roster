#include<iostream>
#include<iomanip>
#include "student.h"
#include <string>
#include "degree.h"
using namespace std;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysInCourse[0] = 0;
	this->daysInCourse[1] = 0;
	this->daysInCourse[2] = 0;
}

Student::Student(string id, string firstname, string lastname, string emailaddress, int age, int* daysincourse, Degree degree)
{
	this->studentID = id;
	this->firstName = firstname;
	this->lastName = lastname;
	this->emailAddress = emailaddress;
	this->age = age;
	this->daysInCourse[0] = daysincourse[0];
	this->daysInCourse[1] = daysincourse[1];
	this->daysInCourse[2] = daysincourse[2];
}

string Student::getID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getDaysCourse()
{
	return daysInCourse;
}


void Student::setID(string ID)
{
	this->studentID = ID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
	this->age = age;
}

void Student::setDaysCourse(int d1, int d2, int d3)
{
	this->daysInCourse[0] = d1;
	this->daysInCourse[1] = d2;
	this->daysInCourse[2] = d3;
}

void Student::print()
{
	cout << getID();
	cout << "\t First name: " << getFirstName();
	cout << "\t Last name: " << getLastName();
	cout << "\t Age: " << getAge();

	int* days = getDaysCourse();
	cout << "\t  Days in course: " << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2];

	string degreeString = "";
	switch (getDegree()) {
	case NETWORK:
		degreeString = "NETWORK";
		break;
	case SECURITY:
		degreeString = "SECURITY";
		break;
	case SOFTWARE:
		degreeString = "SOFTWARE";
		break;
	}
	cout << "\tDegree: " << degreeString << endl;
}

Degree Student::getDegree() {
	return NETWORK;
}

Student::~Student()
{

}