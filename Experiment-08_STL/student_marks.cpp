/*
 * Experiment 8 : STL Containers and Algorithms
 *                Processing a Student Marks Dataset
 *
 * Concepts used:
 *   - Containers : vector, map, unordered_map
 *   - Iterators
 *   - Algorithms : sort, find_if, transform, accumulate, for_each
 *   - Lambda expressions as predicates
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>   // sort, find_if, transform, for_each
#include <numeric>     // accumulate
using namespace std;

struct Student
{
    int rollNo;
    string name;
    int marks;
};

// Returns grade based on marks
char getGrade(int marks)
{
    if (marks >= 90) return 'A';
    if (marks >= 75) return 'B';
    if (marks >= 60) return 'C';
    if (marks >= 40) return 'D';
    return 'F';
}

void printStudent(const Student &s)
{
    cout << s.rollNo << "\t" << s.name << "\t" << s.marks << endl;
}

int main()
{
    // ---------- vector : stores the dataset ----------
    vector<Student> students = {
        {101, "Aarav", 78},
        {102, "Diya", 92},
        {103, "Kabir", 55},
        {104, "Isha", 88},
        {105, "Rohan", 35},
        {106, "Tanvi", 67}
    };

    cout << "===== All Students (using for_each) =====" << endl;
    cout << "Roll\tName\tMarks" << endl;
    for_each(students.begin(), students.end(), printStudent);

    // ---------- sort : highest marks first (lambda as comparator) ----------
    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.marks > b.marks;
    });

    cout << "\n===== Sorted by Marks (High to Low) =====" << endl;
    cout << "Roll\tName\tMarks" << endl;
    // using an iterator to go through the vector
    for (vector<Student>::iterator it = students.begin(); it != students.end(); it++)
    {
        printStudent(*it);
    }

    // ---------- find_if : find first student who failed ----------
    cout << "\n===== find_if =====" << endl;
    auto failed = find_if(students.begin(), students.end(), [](const Student &s) {
        return s.marks < 40;
    });
    if (failed != students.end())
        cout << "Student who failed : " << failed->name << " (" << failed->marks << ")" << endl;
    else
        cout << "No student failed" << endl;

    // find_if : search by name
    string searchName = "Isha";
    auto found = find_if(students.begin(), students.end(), [searchName](const Student &s) {
        return s.name == searchName;
    });
    if (found != students.end())
        cout << searchName << " found with marks " << found->marks << endl;
    else
        cout << searchName << " not found" << endl;

    // ---------- accumulate : total and average ----------
    cout << "\n===== accumulate =====" << endl;
    int total = accumulate(students.begin(), students.end(), 0, [](int sum, const Student &s) {
        return sum + s.marks;
    });
    double average = (double)total / students.size();
    cout << "Total marks   : " << total << endl;
    cout << "Average marks : " << average << endl;

    // ---------- transform : add 5 grace marks (max 100) ----------
    cout << "\n===== transform (5 grace marks) =====" << endl;
    vector<int> newMarks(students.size());
    transform(students.begin(), students.end(), newMarks.begin(), [](const Student &s) {
        int m = s.marks + 5;
        if (m > 100) m = 100;
        return m;
    });
    for (int i = 0; i < (int)students.size(); i++)
    {
        cout << students[i].name << " : " << students[i].marks << " -> " << newMarks[i] << endl;
    }

    // ---------- map : roll number -> name (keeps keys sorted) ----------
    cout << "\n===== map (Roll No -> Name, sorted by key) =====" << endl;
    map<int, string> rollMap;
    for (const Student &s : students)
    {
        rollMap[s.rollNo] = s.name;
    }
    for (auto it = rollMap.begin(); it != rollMap.end(); it++)
    {
        cout << it->first << " -> " << it->second << endl;
    }
    cout << "Name of roll no 103 : " << rollMap[103] << endl;

    // ---------- unordered_map : count of students in each grade ----------
    cout << "\n===== unordered_map (Grade -> Count) =====" << endl;
    unordered_map<char, int> gradeCount;
    for (const Student &s : students)
    {
        gradeCount[getGrade(s.marks)]++;
    }
    string grades = "ABCDF";
    for (char g : grades)
    {
        cout << "Grade " << g << " : " << gradeCount[g] << " student(s)" << endl;
    }

    return 0;
}
