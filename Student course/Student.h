#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n);
};

class Student : public Person {
private:
    int id;
    double gpa;
    vector<string> courses;

public:
    Student(int i, string n, double g);

    int getId();
    double getGpa();
    string getName();

    vector<string>& getCourses();

    void addCourse(string course);
    void display();
};

#endif
