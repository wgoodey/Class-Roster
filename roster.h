////
//// Created by Whitney on 8/9/2019.
////

#ifndef CLASSROSTER_ROSTER_H
#define CLASSROSTER_ROSTER_H

#include <array>
#include "degree.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"


class roster {

public:
    roster();
    roster(int arraySize);
    ~roster();

    void parse(const string newStudentData[]);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age,
             int daysInCourse1, int daysInCourse2, int daysInCourse3, degree::Degree degreeProgram);
    void remove(string studentID);
    void printAll();
    void printDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(int degreeProgram);
    //copy student object to temp, delete student, create object of new degree type from temp

    int getStudentCount();
    student* getIndex(int index);

private:
    int studentCount;
    int rosterSize;
    student** classRosterArray;
};

#endif //CLASSROSTER_ROSTER_H