# Experiment 8

## Aim

Use STL containers (vector, map, unordered_map) and algorithms (sort, find_if, transform) to process a student marks dataset.

## Concepts Used

- Containers: `vector`, `map`, `unordered_map`
- Algorithms: `sort`, `find_if`, `transform`, `accumulate`, `for_each`
- Lambda expressions

## How to Run

```bash
g++ -std=c++17 student_marks.cpp -o student_marks
./student_marks
```

## Output

```
Sorted by marks:
Diya - 92
Isha - 88
Aarav - 78
Kabir - 55
Rohan - 35

Failed student: Rohan
Average marks: 69

After 5 grace marks:
Diya - 97
Isha - 93
Aarav - 83
Kabir - 60
Rohan - 40

Map (sorted by name):
Aarav - 78
Diya - 92
Isha - 88
Kabir - 55
Rohan - 35

Result count:
Pass - 1
Fail - 1
Distinction - 3
```
