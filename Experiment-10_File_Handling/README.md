# Experiment 10

## Aim

Implement a CSV file reader/writer using file I/O (fstream). Store and retrieve student records. Use file pointers (seekg, seekp, tellg, tellp).

## Concepts Used

- `ofstream`, `ifstream`, `fstream`
- File modes: `ios::in`, `ios::out`, `ios::app`, `ios::binary`
- File pointer functions: `seekg()`, `seekp()`, `tellg()`, `tellp()`
- Reading a CSV line and splitting it with `stringstream` and `getline`
- Storing, appending and searching student records

## How to Compile and Run

```bash
g++ -std=c++17 student_csv.cpp -o student_csv
./student_csv
```

## Output

The program creates a file named `students.csv` in the folder where it is run.

```
===== 1. Writing records =====
Put pointer after header : 25
Written : 101,Aarav,CSE,78   (tellp = 42)
Written : 102,Diya,IT,92   (tellp = 57)
Written : 103,Kabir,ENTC,66   (tellp = 75)

===== 2. Reading records =====
Roll	Name	Branch	Marks
101	Aarav	CSE	78
102	Diya	IT	92
103	Kabir	ENTC	66

===== 3. Appending a record =====
Appended : 104,Isha,CSE,88

===== 4. Reading after append =====
Roll	Name	Branch	Marks
101	Aarav	CSE	78
102	Diya	IT	92
103	Kabir	ENTC	66
104	Isha	CSE	88

===== 5. Searching records =====
Record found : 102	Diya	IT	92
Record with roll no 110 not found

===== 6. seekg() and tellg() =====
File size (tellg at end) : 91 bytes
tellg after seekg(0, ios::beg) : 0
First line   : RollNo,Name,Branch,Marks
tellg now    : 25
Next line    : 101,Aarav,CSE,78
After seekg back to 25 : 101,Aarav,CSE,78

===== 7. seekp() and tellp() =====
Put pointer at : 0
Put pointer after writing 1 char : 1
Header is now : rollNo,Name,Branch,Marks
```
