
#include <iostream>
#include <vector>
#include <algorithm>
#include "Student.h"


using namespace std;

vector<Student> students;

// Validation 
bool isIdExists(int id) {
    for (auto& s : students) {
        if (s.getId() == id) return true;
    }
    return false;
}

// Functions 
void addStudent() {
    int id;
    string name;
    double gpa;

    cout << "Enter ID: ";
    cin >> id;

    if (isIdExists(id)) {
        cout << "ID already exists!\n";
        return;
    }

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter GPA: ";
    cin >> gpa;

    if (gpa < 0 || gpa > 4) {
        cout << "Invalid GPA!\n";
        return;
    }

    students.push_back(Student(id, name, gpa));
    cout << "Added successfully!\n";
}

Student* findStudent(int id) {
    for (auto& s : students) {
        if (s.getId() == id) return &s;
    }
    return nullptr;
}

void removeStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students.erase(students.begin() + i);
            cout << "Removed!\n";
            return;
        }
    }

    cout << "Not found!\n";
}

void displayStudents() {
    for (auto& s : students) {
        s.display();
    }
}

void enrollCourse() {
    int id;
    string course;

    cout << "Enter ID: ";
    cin >> id;

    Student* s = findStudent(id);

    if (!s) {
        cout << "Not found!\n";
        return;
    }

    cout << "Enter course: ";
    cin >> course;

    s->addCourse(course);
}

void showCourses() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    Student* s = findStudent(id);

    if (!s) {
        cout << "Not found!\n";
        return;
    }

    for (auto& c : s->getCourses()) {
        cout << c << endl;
    }
}



//main

int main() {
    int choice;

    while (true) {
        cout << "\n1.Add\n2.Remove\n3.Search\n4.Display\n5.Enroll\n6.Show Courses\n7.Sort\n8.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: addStudent(); break;
        case 2: removeStudent(); break;
        case 3: {
            int id;
            cin >> id;
            Student* s = findStudent(id);
            if (s) s->display();
            else cout << "Not found\n";
            break;
        }
        case 4: displayStudents(); break;
        case 5: enrollCourse(); break;
        case 6: showCourses(); break;
        case 7:
            sort(students.begin(), students.end(), [](Student a, Student b) {
                return a.getGpa() > b.getGpa();
                });
            cout << "Sorted!\n";
            break;
        case 8: return 0;
        }
    }
}




