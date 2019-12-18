//
// Created by Whitney on 8/8/2019.
//

#include "securityStudent.h"
#include <iostream>


//constructor
securityStudent::securityStudent() : student(){
    this->degreeProgram = degree::SECURITY;
}
securityStudent::securityStudent(string studentID, string firstName, string lastName, string emailAddress, int age,
                                 int daysInCourse1, int daysInCourse2, int daysInCourse3, degree::Degree degreeProgram)
        : student(studentID, firstName, lastName, emailAddress, age,
                  daysInCourse1, daysInCourse2, daysInCourse3) {

    this->degreeProgram = degree::SECURITY;
}

//destructor
securityStudent::~securityStudent() {
    //only call super destructor, since nothing was dynamically allocated.
    this->student::~student();
}

void securityStudent::print() {
    student::print();
    std::cout << " Degree Program: Security" << endl;
}

degree::Degree securityStudent::getDegreeProgram() {
    return degree::SECURITY;
}

void securityStudent::setDegreeProgram(degree::Degree degreeProgram) {
    this->degreeProgram = degreeProgram;
}