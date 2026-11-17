# Experiment 8

## Aim

Use STL containers (vector, map, unordered_map) and algorithms (sort, find_if, transform) to process a student marks dataset.

## Concepts Used

- Containers: `vector`, `map`, `unordered_map`
- Iterators
- Algorithms: `sort`, `find_if`, `transform`, `accumulate`, `for_each`
- Lambda expressions as predicates

## How to Compile and Run

```bash
g++ -std=c++17 student_marks.cpp -o student_marks
./student_marks
```

## Output

```
===== All Students (using for_each) =====
Roll	Name	Marks
101	Aarav	78
102	Diya	92
103	Kabir	55
104	Isha	88
105	Rohan	35
106	Tanvi	67

===== Sorted by Marks (High to Low) =====
Roll	Name	Marks
102	Diya	92
104	Isha	88
101	Aarav	78
106	Tanvi	67
103	Kabir	55
105	Rohan	35

===== find_if =====
Student who failed : Rohan (35)
Isha found with marks 88

===== accumulate =====
Total marks   : 415
Average marks : 69.1667

===== transform (5 grace marks) =====
Diya : 92 -> 97
Isha : 88 -> 93
Aarav : 78 -> 83
Tanvi : 67 -> 72
Kabir : 55 -> 60
Rohan : 35 -> 40

===== map (Roll No -> Name, sorted by key) =====
101 -> Aarav
102 -> Diya
103 -> Kabir
104 -> Isha
105 -> Rohan
106 -> Tanvi
Name of roll no 103 : Kabir

===== unordered_map (Grade -> Count) =====
Grade A : 1 student(s)
Grade B : 2 student(s)
Grade C : 1 student(s)
Grade D : 1 student(s)
Grade F : 1 student(s)
```
