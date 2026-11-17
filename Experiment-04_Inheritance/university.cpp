#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void showPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : public Person {
protected:
    int roll;
    string course;
public:
    Student(string n, int a, int r, string c) : Person(n, a) {
        roll = r;
        course = c;
    }

    void showStudent() {
        showPerson();
        cout << "Roll No: " << roll << endl;
        cout << "Course: " << course << endl;
    }
};

class GraduateStudent : public Student {
private:
    string topic;
public:
    GraduateStudent(string n, int a, int r, string c, string t) : Student(n, a, r, c) {
        topic = t;
    }

    void showGraduate() {
        showStudent();
        cout << "Research Topic: " << topic << endl;
    }
};

int main() {
    cout << "Single Inheritance (Person -> Student)" << endl;
    Student s("Vikas", 19, 101, "B.Tech CSE");
    s.showStudent();

    cout << "\nMultilevel Inheritance (Person -> Student -> GraduateStudent)" << endl;
    GraduateStudent g("Neha", 24, 501, "M.Tech AI", "Machine Learning");
    g.showGraduate();
    return 0;
}
