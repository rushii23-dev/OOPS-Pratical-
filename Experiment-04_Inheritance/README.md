# Experiment 4

## Aim

Implement Single and Multilevel Inheritance for a university management scenario (Person -> Student -> GraduateStudent).

## Concepts Used

- Single inheritance: `Person` -> `Student`
- Multilevel inheritance: `Person` -> `Student` -> `GraduateStudent`
- `protected` members
- Calling the base class constructor from the derived class

## How to Run

```bash
g++ -std=c++17 university.cpp -o university
./university
```

## Output

```
Single Inheritance (Person -> Student)
Name: Vikas
Age: 19
Roll No: 101
Course: B.Tech CSE

Multilevel Inheritance (Person -> Student -> GraduateStudent)
Name: Neha
Age: 24
Roll No: 501
Course: M.Tech AI
Research Topic: Machine Learning
```
