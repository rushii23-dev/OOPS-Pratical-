/*
 * Experiment 4 : Single and Multilevel Inheritance
 *                University Management (Person -> Student -> GraduateStudent)
 *
 * Concepts used:
 *   - Defining a derived class
 *   - Single inheritance     : Person -> Student
 *   - Multilevel inheritance : Person -> Student -> GraduateStudent
 *   - protected members
 *   - Calling base class constructor from derived class
 *   - Order of constructor and destructor calls
 */

#include <iostream>
#include <string>
using namespace std;

// ---------- Base class ----------
class Person
{
protected:
    string name;
    int age;

public:
    Person(string n, int a)
    {
        name = n;
        age = a;
        cout << "Person constructor called" << endl;
    }

    ~Person()
    {
        cout << "Person destructor called" << endl;
    }

    void showPerson()
    {
        cout << "Name        : " << name << endl;
        cout << "Age         : " << age << endl;
    }
};

// ---------- Single inheritance : Student is a Person ----------
class Student : public Person
{
protected:
    int rollNo;
    string course;

public:
    Student(string n, int a, int r, string c) : Person(n, a)
    {
        rollNo = r;
        course = c;
        cout << "Student constructor called" << endl;
    }

    ~Student()
    {
        cout << "Student destructor called" << endl;
    }

    void showStudent()
    {
        showPerson();     // function of the base class
        cout << "Roll No     : " << rollNo << endl;
        cout << "Course      : " << course << endl;
    }
};

// ---------- Multilevel inheritance : GraduateStudent is a Student ----------
class GraduateStudent : public Student
{
private:
    string researchTopic;
    string guideName;

public:
    GraduateStudent(string n, int a, int r, string c, string topic, string guide)
        : Student(n, a, r, c)
    {
        researchTopic = topic;
        guideName = guide;
        cout << "GraduateStudent constructor called" << endl;
    }

    ~GraduateStudent()
    {
        cout << "GraduateStudent destructor called" << endl;
    }

    void showGraduateStudent()
    {
        showStudent();    // function of the parent class
        cout << "Research    : " << researchTopic << endl;
        cout << "Guide       : " << guideName << endl;
        // name is protected in Person, so it can be used here also
        cout << name << " is a graduate student." << endl;
    }
};

int main()
{
    cout << "===== Single Inheritance (Person -> Student) =====" << endl;
    {
        Student s("Vikas", 19, 101, "B.Tech CSE");
        cout << endl;
        s.showStudent();
        cout << endl;
    }   // s goes out of scope here, destructors run

    cout << "\n===== Multilevel Inheritance (Person -> Student -> GraduateStudent) =====" << endl;
    {
        GraduateStudent g("Neha", 24, 501, "M.Tech AI", "Machine Learning", "Dr. Sharma");
        cout << endl;
        g.showGraduateStudent();
        cout << endl;
    }   // g goes out of scope here, destructors run in reverse order

    return 0;
}
