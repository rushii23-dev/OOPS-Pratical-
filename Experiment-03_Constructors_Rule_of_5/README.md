# Experiment 3

## Aim

Implement a class demonstrating all constructor types (Default, Parameterized, Copy, Move). Apply the Rule of 5. Verify with Valgrind for memory leaks.

## Concepts Used

- Default constructor (with constructor delegation)
- Parameterized constructor (with initializer list)
- Copy constructor (deep copy)
- Move constructor (C++11) and `std::move`
- Copy assignment and move assignment operators
- Destructor
- Rule of 5: a class that uses `new`/`delete` should define all five special functions

## How to Compile and Run

```bash
g++ -std=c++17 constructors.cpp -o constructors
./constructors
```

## Checking Memory Leaks with Valgrind (Linux / WSL)

```bash
g++ -std=c++17 -g constructors.cpp -o constructors
valgrind --leak-check=full ./constructors
```

Expected result at the end of the Valgrind report:

```
All heap blocks were freed -- no leaks are possible
```

Every `new[]` has a matching `delete[]` in the destructor or the assignment operators, so there is no memory leak.

## Output

```
----- Default Constructor -----
Parameterized constructor called for Unknown
Default constructor called
Unknown -> Marks : (empty)

----- Parameterized Constructor -----
Parameterized constructor called for Anjali
Anjali -> Marks : 85 90 78 

----- Copy Constructor -----
Copy constructor called for Anjali
Original : Anjali -> Marks : 85 90 78 
Copy     : Anjali-Copy -> Marks : 100 90 78 

----- Move Constructor -----
Move constructor called for Anjali-Copy
New object : Anjali-Copy -> Marks : 100 90 78 
Old object : Anjali-Copy -> Marks : (empty)

----- Copy Assignment -----
Parameterized constructor called for Rohan
Before : Rohan -> Marks : 50 60 
Copy assignment operator called
After  : Anjali -> Marks : 85 90 78 

----- Move Assignment -----
Parameterized constructor called for Meera
Move assignment operator called
New object : Anjali-Copy -> Marks : 100 90 78 
Old object : Anjali-Copy -> Marks : (empty)

----- End of main, destructors will run now -----
Destructor called for Anjali-Copy
Destructor called for Anjali
Destructor called for Anjali-Copy
Destructor called for Anjali-Copy
Destructor called for Anjali
Destructor called for Unknown
```
