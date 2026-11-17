# Experiment 4

## Aim

Implement Single and Multilevel Inheritance for a university management scenario (Person -> Student -> GraduateStudent).

## Concepts Used

- Defining a derived class
- Single inheritance: `Person` -> `Student`
- Multilevel inheritance: `Person` -> `Student` -> `GraduateStudent`
- `protected` members used in child classes
- Calling the base class constructor from the derived class
- Order of constructor and destructor calls

## How to Compile and Run

```bash
g++ -std=c++17 university.cpp -o university
./university
```

## Output

```
===== Single Inheritance (Person -> Student) =====
Person constructor called
Student constructor called

Name        : Vikas
Age         : 19
Roll No     : 101
Course      : B.Tech CSE

Student destructor called
Person destructor called

===== Multilevel Inheritance (Person -> Student -> GraduateStudent) =====
Person constructor called
Student constructor called
GraduateStudent constructor called

Name        : Neha
Age         : 24
Roll No     : 501
Course      : M.Tech AI
Research    : Machine Learning
Guide       : Dr. Sharma
Neha is a graduate student.

GraduateStudent destructor called
Student destructor called
Person destructor called
```
