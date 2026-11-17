/*
 * Experiment 10 : CSV File Reader / Writer using File I/O (fstream)
 *                 Store and Retrieve Student Records
 *
 * Concepts used:
 *   - ofstream (write), ifstream (read), fstream (read + write)
 *   - File modes : ios::out, ios::in, ios::app, ios::binary
 *     (ios::binary is used so that every line ends with only '\n'.
 *      On Windows, text mode writes "\r\n", which can make the
 *      positions given by tellg() / seekg() wrong.)
 *   - File pointer functions :
 *        tellp() -> current position of the PUT (write) pointer
 *        seekp() -> move the PUT (write) pointer
 *        tellg() -> current position of the GET (read) pointer
 *        seekg() -> move the GET (read) pointer
 *   - Reading a CSV line and splitting it using stringstream
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

const string FILE_NAME = "students.csv";

class Student
{
public:
    int rollNo;
    string name;
    string branch;
    int marks;

    // Convert a student to one CSV line : 101,Aarav,CSE,78
    string toCSV()
    {
        return to_string(rollNo) + "," + name + "," + branch + "," + to_string(marks);
    }

    // Read a student from one CSV line
    void fromCSV(string line)
    {
        stringstream ss(line);
        string field;

        getline(ss, field, ',');
        rollNo = stoi(field);
        getline(ss, name, ',');
        getline(ss, branch, ',');
        getline(ss, field, ',');
        marks = stoi(field);
    }

    void display()
    {
        cout << rollNo << "\t" << name << "\t" << branch << "\t" << marks << endl;
    }
};

// 1. Write records to the file (ios::out creates a new file)
void writeRecords()
{
    ofstream fout(FILE_NAME, ios::out | ios::binary);
    if (!fout)
    {
        cout << "Error opening file for writing!" << endl;
        return;
    }

    Student list[3] = {
        {101, "Aarav", "CSE", 78},
        {102, "Diya", "IT", 92},
        {103, "Kabir", "ENTC", 66}
    };

    fout << "RollNo,Name,Branch,Marks" << endl;   // header line
    cout << "Put pointer after header : " << fout.tellp() << endl;

    for (int i = 0; i < 3; i++)
    {
        fout << list[i].toCSV() << endl;
        cout << "Written : " << list[i].toCSV()
             << "   (tellp = " << fout.tellp() << ")" << endl;
    }
    fout.close();
}

// 2. Add a record at the end (ios::app)
void appendRecord(Student s)
{
    ofstream fout(FILE_NAME, ios::app | ios::binary);
    fout << s.toCSV() << endl;
    fout.close();
    cout << "Appended : " << s.toCSV() << endl;
}

// 3. Read all records
void readRecords()
{
    ifstream fin(FILE_NAME, ios::in);
    if (!fin)
    {
        cout << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    getline(fin, line);      // skip the header line

    cout << "Roll\tName\tBranch\tMarks" << endl;
    while (getline(fin, line))
    {
        if (line == "")
            continue;
        Student s;
        s.fromCSV(line);
        s.display();
    }
    fin.close();
}

// 4. Search a record by roll number
void searchRecord(int roll)
{
    ifstream fin(FILE_NAME);
    string line;
    getline(fin, line);      // skip header

    while (getline(fin, line))
    {
        Student s;
        s.fromCSV(line);
        if (s.rollNo == roll)
        {
            cout << "Record found : ";
            s.display();
            return;
        }
    }
    cout << "Record with roll no " << roll << " not found" << endl;
}

// 5. Demonstrate seekg() and tellg()
void filePointerDemo()
{
    ifstream fin(FILE_NAME, ios::in | ios::binary);

    // Move get pointer to the end to know the file size
    fin.seekg(0, ios::end);
    cout << "File size (tellg at end) : " << fin.tellg() << " bytes" << endl;

    // Move get pointer back to the beginning
    fin.seekg(0, ios::beg);
    cout << "tellg after seekg(0, ios::beg) : " << fin.tellg() << endl;

    string header;
    getline(fin, header);
    cout << "First line   : " << header << endl;
    cout << "tellg now    : " << fin.tellg() << endl;

    // Remember where the first record starts
    streampos firstRecord = fin.tellg();

    string line;
    getline(fin, line);
    cout << "Next line    : " << line << endl;

    // Jump back to the first record and read it again
    fin.seekg(firstRecord);
    getline(fin, line);
    cout << "After seekg back to " << firstRecord << " : " << line << endl;

    fin.close();
}

// 6. Demonstrate seekp() : change the first letter of the header
void seekpDemo()
{
    fstream file(FILE_NAME, ios::in | ios::out | ios::binary);
    file.seekp(0, ios::beg);           // go to the start of the file
    cout << "Put pointer at : " << file.tellp() << endl;
    file << "r";                       // overwrite 'R' with 'r'
    cout << "Put pointer after writing 1 char : " << file.tellp() << endl;
    file.close();

    ifstream fin(FILE_NAME);
    string header;
    getline(fin, header);
    cout << "Header is now : " << header << endl;
    fin.close();
}

int main()
{
    cout << "===== 1. Writing records =====" << endl;
    writeRecords();

    cout << "\n===== 2. Reading records =====" << endl;
    readRecords();

    cout << "\n===== 3. Appending a record =====" << endl;
    Student s4 = {104, "Isha", "CSE", 88};
    appendRecord(s4);

    cout << "\n===== 4. Reading after append =====" << endl;
    readRecords();

    cout << "\n===== 5. Searching records =====" << endl;
    searchRecord(102);
    searchRecord(110);

    cout << "\n===== 6. seekg() and tellg() =====" << endl;
    filePointerDemo();

    cout << "\n===== 7. seekp() and tellp() =====" << endl;
    seekpDemo();

    return 0;
}
