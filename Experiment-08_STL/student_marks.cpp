#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

struct Student {
    string name;
    int marks;
};

int main() {
    vector<Student> s = {{"Aarav", 78}, {"Diya", 92}, {"Kabir", 55}, {"Isha", 88}, {"Rohan", 35}};

    sort(s.begin(), s.end(), [](Student a, Student b) { return a.marks > b.marks; });
    cout << "Sorted by marks:" << endl;
    for_each(s.begin(), s.end(), [](Student x) { cout << x.name << " - " << x.marks << endl; });

    auto it = find_if(s.begin(), s.end(), [](Student x) { return x.marks < 40; });
    if (it != s.end())
        cout << "\nFailed student: " << it->name << endl;

    int total = accumulate(s.begin(), s.end(), 0, [](int sum, Student x) { return sum + x.marks; });
    cout << "Average marks: " << total / s.size() << endl;

    vector<int> grace(s.size());
    transform(s.begin(), s.end(), grace.begin(), [](Student x) { return min(x.marks + 5, 100); });
    cout << "\nAfter 5 grace marks:" << endl;
    for (size_t i = 0; i < s.size(); i++)
        cout << s[i].name << " - " << grace[i] << endl;

    map<string, int> m;
    for (Student x : s)
        m[x.name] = x.marks;
    cout << "\nMap (sorted by name):" << endl;
    for (auto p : m)
        cout << p.first << " - " << p.second << endl;

    unordered_map<string, int> result;
    for (Student x : s) {
        if (x.marks >= 75)
            result["Distinction"]++;
        else if (x.marks >= 40)
            result["Pass"]++;
        else
            result["Fail"]++;
    }
    cout << "\nResult count:" << endl;
    for (auto p : result)
        cout << p.first << " - " << p.second << endl;
    return 0;
}
