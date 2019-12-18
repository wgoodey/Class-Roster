//
// Created by Whitney on 8/8/2019.
//

#ifndef CLASSROSTER_SECURITYSTUDENT_H
#define CLASSROSTER_SECURITYSTUDENT_H

#include "student.h"
#include "degree.h"


class securityStudent : public student {

public:
	//constructor
	securityStudent();
	securityStudent(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, degree::Degree degreeProgram);
	//destructor
	~securityStudent();

	void print() override;
	degree::Degree getDegreeProgram() override;
	void setDegreeProgram(degree::Degree degreeProgram);


private:
	degree::Degree degreeProgram;
};

#endif //CLASSROSTER_SECURITYSTUDENT_H
