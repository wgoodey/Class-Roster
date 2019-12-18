#include <iostream>
#include "roster.h"
#include "student.h"
#include "softwareStudent.h"

using namespace std;


//[studentID],[firstName],[lastName],[emailAddress],[age],[numberOfDaysToComplete3Courses],[degree]
const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY,",
                              "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK,",
                              "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE,",
                              "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY,",
                              "A5,Whitney,Goodey,wgoodey@wgu.edu,34,5,30,40,SOFTWARE"};

//constructor
roster::roster() {
    this->studentCount = -1;
    this->rosterSize = 0;
    this->classRosterArray = nullptr;
}

roster::roster(int arraySize) {
    this->studentCount = -1;
    this->rosterSize = arraySize;
    this->classRosterArray = new student*[rosterSize];
}

//destructor
roster::~roster() {
    for (int i = 0; i <= studentCount; i++) {
        delete this->classRosterArray[i];
        this->classRosterArray[i] = nullptr;
    }
    delete this->classRosterArray;
}

void roster::parse(const string newStudentData[]) {
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse1;
    int daysInCourse2;
    int daysInCourse3;
    degree::Degree degreeProgram;
    string data = "";

    for (int i = 0; i < rosterSize; i++) {
        int end = 0;
        //copy one line of data at a time
        data = studentData[i];
        if (data[data.length() - 1] == ',') {
        data = data.substr(0, data.length() - 1);
        }

        //studentID
        end = data.find(',');
        studentID = data.substr(0, end);
        data = data.substr(end + 1, data.length() - end);

        //firstName
        end = data.find(',');
        firstName = data.substr(0, end);
        data = data.substr(end + 1, data.length() - end);

        //lastName
        end = data.find(',');
        lastName = data.substr(0, end);
        data = data.substr(end + 1, data.length() - end);

        //emailAddress
        end = data.find(',');
        emailAddress = data.substr(0, end);
        data = data.substr(end + 1, data.length() - end);

        //age
        end = data.find(',');
        age = stoi(data.substr(0, end));
        data = data.substr(end + 1, data.length() - end);

        //daysInCourse1
        end = data.find(',');
        daysInCourse1 = stoi(data.substr(0, end));
        data = data.substr(end + 1, data.length() - end);

        //daysInCourse2
        end = data.find(',');
        daysInCourse2 = stoi(data.substr(0, end));
        data = data.substr(end + 1, data.length() - end);

        //daysInCourse3
        end = data.find(',');
        daysInCourse3 = stoi(data.substr(0, end));
        data = data.substr(end + 1, data.length() - end);

        //degreeProgram
        if (data == "NETWORK"){
            degreeProgram = degree::NETWORK;
        }
        if (data == "SECURITY"){
            degreeProgram = degree::SECURITY;
        }
        if (data == "SOFTWARE"){
            degreeProgram = degree::SOFTWARE;
        }

        //call the add function to create the new student object
        roster::add(studentID, firstName, lastName, emailAddress, age,
                    daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
    }
}


void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
         int daysInCourse1, int daysInCourse2, int daysInCourse3, degree::Degree degreeProgram) {

    degree::Degree program = degreeProgram;

    //check to make sure array isn't full
    if (this->studentCount < rosterSize) {
        //if there is room in the array, create new student object and increase studentCount
        studentCount++;
        switch (program) {
            case 0:
                this->classRosterArray[studentCount] = new networkStudent(studentID, firstName, lastName, emailAddress, age,
                                                                    daysInCourse1, daysInCourse2, daysInCourse3,
                                                                    degreeProgram);
                break;
            case 1:
                this->classRosterArray[studentCount] = new securityStudent(studentID, firstName, lastName, emailAddress, age,
                                                                     daysInCourse1, daysInCourse2, daysInCourse3,
                                                                     degreeProgram);
                break;
            case 2:
                this->classRosterArray[studentCount] = new softwareStudent(studentID, firstName, lastName, emailAddress, age,
                                                                     daysInCourse1, daysInCourse2, daysInCourse3,
                                                                     degreeProgram);
                break;
            default:
                std::cout << "Failed to add student - confirm degree program.";

        }
            } else {
        std::cout << "Course roster is full. Unable to add student.";
    }
}


void roster::remove(string studentID) {
    bool found = false;
    int location = -1;

    cout << "Removing student " << studentID << "....";
    //search roster array for matching ID
    for (int i = 0; i <= this->studentCount; i++) {
        //find matching ID
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            location = i;
        }
    }

    if (found) {
        //delete the object then null the element
        delete this->classRosterArray[location];
        this->classRosterArray[location] = nullptr;
        cout << "done." << endl;

        //shift entries down
        for (int j = location; j <= this->studentCount; j++) {
            //if last element
            if (j == this->studentCount) {
                break;
            } else {
                this->classRosterArray[j] = this->classRosterArray[j + 1];
            }
        }
        //decrease student count and return
        studentCount--;
    } else {
        cout << "Student ID not found." << endl;
    }
}


void roster::printAll() {
    for (int i = 0; i <= this->studentCount; i++) {
        this->classRosterArray[i]->print();
    }
}


void roster::printDaysInCourse(string studentID) {
    //search roster array for matching ID
    for (int i = 0; i <= this->studentCount; i++) {
        if (this->classRosterArray[i]->getStudentID() == studentID) {
            int avgDays = (this->classRosterArray[i]->getDaysInCourse(1) + this->classRosterArray[i]->getDaysInCourse(2)
                         + this->classRosterArray[i]->getDaysInCourse(3)) / 3;
            cout << avgDays;
            break;
        }
    }
}


void roster::printInvalidEmails() {
    string email = "";
    bool error = false;
    int atSymbol = -1;

    std::cout << "The following emails are invalid:" << endl;
    for (int i = 0; i <= this->studentCount; i++) {
        error = false;

        email = this->classRosterArray[i]->getEmailAddress();
        atSymbol = email.find('@');

        //check for spaces
        if ((email.find(' ') != string::npos) || (atSymbol == string::npos) || (email.find('.', atSymbol) == string::npos)) {
            error = true;
        }
        //print email address if error is true
        if (error) {
            cout << email << endl;
        }
    }
}

void roster::printByDegreeProgram(int degreeProgram) {
    //loop and print if degreeProgram matches
    for (int i = 0; i <= this->studentCount; i++) {
        if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            this->classRosterArray[i]->print();
        }
    }
}


int roster::getStudentCount () {
    return this->studentCount + 1;
}

student* roster::getIndex(int index) {
    return this->classRosterArray[index];
}




//main function for testing
int main() {
    int numStudents = 5;

//[studentID],[firstName],[lastName],[emailAddress],[age],[numberOfDaysToComplete3Courses],[degree]
    const string studentData[5] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY,",
                                   "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK,",
                                   "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE,",
                                   "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY,",
                                   "A5,Whitney,Goodey,wgoodey@wgu.edu,34,5,30,40,SOFTWARE"};


    
    cout << endl << endl << "C867 Scripting & Programming: Applications, C++" << endl;
    cout << "Student ID: #000688891 \tWhitney Goodey" << endl << endl;

	roster* classRoster = new roster(numStudents);
    classRoster->parse(&studentData[numStudents]);
    classRoster->printAll();
    classRoster->printInvalidEmails();
    //loop through classRosterArray and for each element print average number of days:
    for (int i = 0; i < numStudents; i++) {
        cout << "Average number of days for student " << classRoster->getIndex(i)->getStudentID() << ": ";
        classRoster->printDaysInCourse(classRoster->getIndex(i)->getStudentID());
        cout << endl;
    }
    classRoster->printByDegreeProgram(degree::SOFTWARE);
    classRoster->remove("A3");
    classRoster->remove("A3");
	delete classRoster;

    return 0;
}