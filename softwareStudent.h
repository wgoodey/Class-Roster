//
// Created by Whitney on 8/8/2019.
//

#ifndef CLASSROSTER_SOFTWARESTUDENT_H
#define CLASSROSTER_SOFTWARESTUDENT_H

#include "student.h"
#include "degree.h"


class softwareStudent : public student {

	//FIX ME: add copy constructor (for degree change)
	//FIX ME: add function to copy object with a degree change and then delete old object

public:
	//constructor
	softwareStudent();
	softwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, degree::Degree degreeProgram);
	//destructor
	~softwareStudent();

	void print() override;
	degree::Degree getDegreeProgram() override;
	void setDegreeProgram(degree::Degree degreeProgram);


private:
	degree::Degree degreeProgram;
};

#endif //CLASSROSTER_SOFTWARESTUDENT_H
