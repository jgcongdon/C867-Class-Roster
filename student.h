#pragma once
#include <string>
#include "degree.h"
using std::string;

using namespace std;

class Student {

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	Degree degree;

public:
	Student();
	Student(string ID, string firstName, string lastName, string emailAddress, int age, int* daysCourse, Degree degree);

	string getID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysCourse();
	virtual Degree getDegree();

	void setID(string ID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysCourse(int, int, int);

	virtual void print();

	~Student();

};