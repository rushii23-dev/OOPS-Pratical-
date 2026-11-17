# Experiment 3

## Aim

Implement a class demonstrating all constructor types (Default, Parameterized, Copy, Move). Apply the Rule of 5. Verify with Valgrind for memory leaks.

## Concepts Used

- Default constructor
- Parameterized constructor
- Copy constructor (deep copy)
- Move constructor and `move()`
- Copy assignment and move assignment operators
- Destructor
- Rule of 5: a class that uses `new` and `delete` should have all five special functions

## How to Run

```bash
g++ -std=c++17 constructors.cpp -o constructors
./constructors
```

## Checking Memory Leaks (Linux / WSL)

```bash
g++ -std=c++17 -g constructors.cpp -o constructors
valgrind --leak-check=full ./constructors
```

Valgrind should show: `All heap blocks were freed -- no leaks are possible`

## Output

```
Default constructor
Marks: 0
Parameterized constructor
Marks: 85
Copy constructor
Marks: 85
Move constructor
Marks: 85
Marks: empty
Default constructor
Copy assignment
Marks: 85
Default constructor
Move assignment
Marks: 85
Marks: empty
End of main
Destructor
Destructor
Destructor
Destructor
Destructor
Destructor
```
