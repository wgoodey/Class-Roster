//
// Created by Whitney on 8/8/2019.
//

#include "networkStudent.h"
#include <iostream>


//constructor
networkStudent::networkStudent() : student(){
    this->degreeProgram = degree::NETWORK;
}
networkStudent::networkStudent(string studentID, string firstName, string lastName, string emailAddress, int age,
                                 int daysInCourse1, int daysInCourse2, int daysInCourse3, degree::Degree degreeProgram)
        : student(studentID, firstName, lastName, emailAddress, age,
                  daysInCourse1, daysInCourse2, daysInCourse3) {

    this->degreeProgram = degree::NETWORK;
}

//destructor
networkStudent::~networkStudent() {
    //only call super destructor, since nothing was dynamically allocated.
    this->student::~student();
}

void networkStudent::print() {
    student::print();
    std::cout << " Degree Program: Network" << endl;
}

degree::Degree networkStudent::getDegreeProgram() {
    return degree::NETWORK;
}

void networkStudent::setDegreeProgram(degree::Degree degreeProgram) {
    this->degreeProgram = degreeProgram;
}