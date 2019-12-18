//
// Created by Whitney on 8/8/2019.
//

#include "student.h"
#include <string>
#include <iostream>

using namespace std;


//constructors

//default
student::student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysInCourse[0] = 0;
    this->daysInCourse[1] = 0;
    this->daysInCourse[2] = 0;
}

student::student(string studentID, string firstName, string lastName, string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
}
//destructor
student::~student() {
    //nothing was dynamically allocated, so nothing to do here
}

//print student data
void student::print() {
    std::cout << getStudentID() << "\tFirst Name: " << getFirstName() << "\tLast Name: " << getLastName()
              << "\tAge: " << getAge() << "\tdaysInCourse: {" << getDaysInCourse(1) << ", "
              << getDaysInCourse(2) << ", " << getDaysInCourse(3) << "}";
}

//getters
string student::getStudentID() {
    return this->studentID;
}
string student::getFirstName() {
    return this->firstName;
}
string student::getLastName() {
    return this->lastName;
}
string student::getEmailAddress() {
    return this->emailAddress;
}
int student::getAge() {
    return this->age;
}
int student::getDaysInCourse(int courseNumber) {
    return this->daysInCourse[courseNumber - 1];
}


//setters
void student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void student::setLastName(string lastName) {
    this->lastName = lastName;
}
void student::setEmailAddress(string emailAddress) {
    this->emailAddress;
}
void student::setAge(int age) {
    this->age = age;
}
void student::setDaysInCourse(int courseNumber, int days) {
    this->daysInCourse[courseNumber - 1] = days;
}