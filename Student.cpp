

#include "Student.h"

// Person
Person::Person(string n) {
    name = n;
}

// Student
Student::Student(int i, string n, double g) : Person(n) {
    id = i;
    gpa = g;
}

int Student::getId() {
    return id;
}

double Student::getGpa() {
    return gpa;
}

string Student::getName() {
    return name;
}

vector<string>& Student::getCourses() {
    return courses;
}

void Student::addCourse(string course) {
    for (auto& c : courses) {
        if (c == course) {
            cout << "Course already exists!\n";
            return;
        }
    }
    courses.push_back(course);
}

void Student::display() {
    cout << "ID: " << id << " Name: " << name << " GPA: " << gpa << endl;
}