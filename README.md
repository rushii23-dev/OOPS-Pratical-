# OOPS Practicals in C++

C++ programs for the Object Oriented Programming practicals, plus a mini project (Expense Tracker).
Each folder has the source code and a `README.md` with the aim, concepts used, how to run it, and the output.

## List of Experiments

| S.N. | Experiment | Folder |
|---|---|---|
| 1 | Data types, constants, variables, operators and I/O | [Experiment-01_Basics](Experiment-01_Basics) |
| 2 | Class hierarchy for BankAccount, access specifiers and member functions | [Experiment-02_Class_Hierarchy](Experiment-02_Class_Hierarchy) |
| 3 | All constructor types (Default, Parameterized, Copy, Move) and the Rule of 5 | [Experiment-03_Constructors_Rule_of_5](Experiment-03_Constructors_Rule_of_5) |
| 4 | Single and Multilevel Inheritance (Person -> Student -> GraduateStudent) | [Experiment-04_Inheritance](Experiment-04_Inheritance) |
| 5 | Runtime polymorphism with virtual functions and an abstract Shape class | [Experiment-05_Runtime_Polymorphism](Experiment-05_Runtime_Polymorphism) |
| 6 | Compile-time polymorphism: function and operator overloading (Complex Number) | [Experiment-06_Compile_Time_Polymorphism](Experiment-06_Compile_Time_Polymorphism) |
| 7 | Generic Stack using templates (int, float, string) | [Experiment-07_Templates](Experiment-07_Templates) |
| 8 | STL containers and algorithms on a student marks dataset | [Experiment-08_STL](Experiment-08_STL) |
| 9 | Custom exception hierarchy for banking transactions | [Experiment-09_Exception_Handling](Experiment-09_Exception_Handling) |
| 10 | CSV file reader/writer with fstream and file pointers | [Experiment-10_File_Handling](Experiment-10_File_Handling) |
| 11 | Mini Project: Expense Tracker | [Mini-Project_Expense_Tracker](Mini-Project_Expense_Tracker) |

## How to Compile and Run Any Program

You need a C++ compiler such as `g++`.

```bash
cd Experiment-01_Basics
g++ -std=c++17 basics.cpp -o basics
./basics
```

On Windows, run `basics.exe` instead of `./basics`.

## Syllabus Units Covered

1. **Introduction to OOP and Modern C++** : data types, operators, `::`, `new`/`delete`, `auto`, range-based for, `nullptr`, `constexpr` (Experiment 1)
2. **Classes, Objects and Memory Management** : access specifiers, constructors, destructors, Rule of 5, static members, friend functions (Experiments 2, 3)
3. **Inheritance and Polymorphism** : single and multilevel inheritance, virtual functions, abstract class, function and operator overloading (Experiments 4, 5, 6)
4. **Generic Programming and STL** : templates, `vector`, `map`, `unordered_map`, `sort`, `find_if`, `transform`, `accumulate`, lambdas (Experiments 7, 8)
5. **Exception Handling and File I/O** : `try`/`catch`/`throw`, custom exceptions, `noexcept`, `fstream`, file modes, `seekg`/`seekp`/`tellg`/`tellp` (Experiments 9, 10)
