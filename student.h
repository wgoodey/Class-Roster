//
// Created by Whitney on 8/8/2019.
//

#ifndef CLASSROSTER_STUDENT_H
#define CLASSROSTER_STUDENT_H

#include "degree.h"
#include <string>

using namespace std;


class student {

public:
	//constructors
	student();
	student(string studentID, string firstName, string lastName, string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3);

	//destructor
	~student();

	virtual degree::Degree getDegreeProgram() = 0;
	virtual void print();


	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int getDaysInCourse(int courseNumber);


	//setters
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int courseNumber, int days);


protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
};

#endif //CLASSROSTER_STUDENT_H
