#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ofstream fout("students.csv", ios::out | ios::binary);
    fout << "101,Aarav,78\n";
    fout << "102,Diya,92\n";
    fout << "103,Kabir,66\n";
    cout << "tellp after writing: " << fout.tellp() << endl;
    fout.close();

    fout.open("students.csv", ios::app | ios::binary);
    fout << "104,Isha,88\n";
    fout.close();

    ifstream fin("students.csv", ios::in | ios::binary);
    string line, roll, name, marks;
    cout << "\nRoll\tName\tMarks" << endl;
    while (getline(fin, line)) {
        stringstream ss(line);
        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, marks, ',');
        cout << roll << "\t" << name << "\t" << marks << endl;
    }

    fin.clear();
    fin.seekg(0, ios::end);
    cout << "\nFile size: " << fin.tellg() << " bytes" << endl;

    fin.seekg(0, ios::beg);
    getline(fin, line);
    cout << "First line: " << line << endl;
    cout << "tellg now: " << fin.tellg() << endl;
    fin.close();

    fstream file("students.csv", ios::in | ios::out | ios::binary);
    file.seekp(10);
    cout << "\nseekp moved to: " << file.tellp() << endl;
    file << "80";
    file.close();

    fin.open("students.csv", ios::in | ios::binary);
    getline(fin, line);
    cout << "First line after update: " << line << endl;
    fin.close();
    return 0;
}
