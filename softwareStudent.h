#pragma once
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class softwareStudent : public Student
{
private:
	Degree degree = SOFTWARE;

public:
	using Student::Student;
	Degree getDegree() override;
};