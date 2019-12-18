//
// Created by Whitney on 8/8/2019.
//

#include "softwareStudent.h"
#include <iostream>


//constructor
softwareStudent::softwareStudent() : student(){
    this->degreeProgram = degree::SOFTWARE;
}
softwareStudent::softwareStudent(string studentID, string firstName, string lastName, string emailAddress, int age,
                                 int daysInCourse1, int daysInCourse2, int daysInCourse3, degree::Degree degreeProgram)
                                 : student(studentID, firstName, lastName, emailAddress, age,
                                           daysInCourse1, daysInCourse2, daysInCourse3) {

    this->degreeProgram = degree::SOFTWARE;
}

//destructor
softwareStudent::~softwareStudent() {
    //only call super destructor, since nothing was dynamically allocated.
    this->student::~student();
}

void softwareStudent::print() {
    student::print();
    std::cout << " Degree Program: Software" << endl;
}

degree::Degree softwareStudent::getDegreeProgram() {
    return degree::SOFTWARE;
}

void softwareStudent::setDegreeProgram(degree::Degree degreeProgram) {
    this->degreeProgram = degreeProgram;
}