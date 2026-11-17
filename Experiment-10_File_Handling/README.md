# Experiment 10

## Aim

Implement a CSV file reader/writer using file I/O (fstream). Store and retrieve student records. Use file pointers (seekg, seekp, tellg, tellp).

## Concepts Used

- `ofstream`, `ifstream`, `fstream`
- File modes: `ios::in`, `ios::out`, `ios::app`, `ios::binary`
- File pointers: `seekg()`, `seekp()`, `tellg()`, `tellp()`
- Splitting a CSV line using `stringstream` and `getline`

## How to Run

```bash
g++ -std=c++17 student_csv.cpp -o student_csv
./student_csv
```

## Output

The program creates a file named `students.csv`.

```
tellp after writing: 38

Roll	Name	Marks
101	Aarav	78
102	Diya	92
103	Kabir	66
104	Isha	88

File size: 50 bytes
First line: 101,Aarav,78
tellg now: 13

seekp moved to: 10
First line after update: 101,Aarav,80
```
