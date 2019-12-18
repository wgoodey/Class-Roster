//
// Created by Whitney on 8/8/2019.
//

#ifndef CLASSROSTER_NETWORKSTUDENT_H
#define CLASSROSTER_NETWORKSTUDENT_H

#include "student.h"
#include "degree.h"


class networkStudent : public student {

public:
	//constructor
	networkStudent();
	networkStudent(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, degree::Degree degreeProgram);
	//destructor
	~networkStudent();

	void print() override;
	degree::Degree getDegreeProgram() override;
	void setDegreeProgram(degree::Degree degreeProgram);


private:
	degree::Degree degreeProgram;
};

#endif //CLASSROSTER_NETWORKSTUDENT_H
