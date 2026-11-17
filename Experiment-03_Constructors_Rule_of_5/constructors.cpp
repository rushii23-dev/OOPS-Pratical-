/*
 * Experiment 3 : All Constructor Types and the Rule of 5
 *
 * Concepts used:
 *   - Default constructor
 *   - Parameterized constructor
 *   - Copy constructor
 *   - Move constructor (C++11)
 *   - Copy assignment operator and Move assignment operator
 *   - Destructor
 *   - Rule of 5 : if a class manages memory (new / delete), write all 5:
 *         1. Destructor
 *         2. Copy constructor
 *         3. Copy assignment operator
 *         4. Move constructor
 *         5. Move assignment operator
 *   - Initializer list, constructor delegation
 *
 * Check for memory leaks (on Linux / WSL):
 *   g++ -std=c++17 -g constructors.cpp -o constructors
 *   valgrind --leak-check=full ./constructors
 */

#include <iostream>
#include <string>
#include <utility>   // for std::move
using namespace std;

class MarksList
{
private:
    string studentName;
    int size;
    int *marks;      // dynamic array -> this is why we need the Rule of 5

public:
    // 1. Default constructor (uses constructor delegation)
    MarksList() : MarksList("Unknown", 0)
    {
        cout << "Default constructor called" << endl;
    }

    // 2. Parameterized constructor (uses initializer list)
    MarksList(string name, int n) : studentName(name), size(n), marks(nullptr)
    {
        if (size > 0)
        {
            marks = new int[size];
            for (int i = 0; i < size; i++)
            {
                marks[i] = 0;
            }
        }
        cout << "Parameterized constructor called for " << studentName << endl;
    }

    // 3. Copy constructor : makes a NEW copy of the memory (deep copy)
    MarksList(const MarksList &other)
    {
        studentName = other.studentName;
        size = other.size;
        marks = nullptr;
        if (size > 0)
        {
            marks = new int[size];
            for (int i = 0; i < size; i++)
            {
                marks[i] = other.marks[i];
            }
        }
        cout << "Copy constructor called for " << studentName << endl;
    }

    // 4. Move constructor : takes the memory from the other object
    MarksList(MarksList &&other) noexcept
    {
        studentName = other.studentName;
        size = other.size;
        marks = other.marks;      // steal the pointer

        other.size = 0;           // leave the other object empty
        other.marks = nullptr;
        cout << "Move constructor called for " << studentName << endl;
    }

    // 5. Copy assignment operator
    MarksList &operator=(const MarksList &other)
    {
        cout << "Copy assignment operator called" << endl;
        if (this != &other)            // avoid self-assignment
        {
            delete[] marks;            // free old memory

            studentName = other.studentName;
            size = other.size;
            marks = nullptr;
            if (size > 0)
            {
                marks = new int[size];
                for (int i = 0; i < size; i++)
                {
                    marks[i] = other.marks[i];
                }
            }
        }
        return *this;
    }

    // 6. Move assignment operator
    MarksList &operator=(MarksList &&other) noexcept
    {
        cout << "Move assignment operator called" << endl;
        if (this != &other)
        {
            delete[] marks;            // free old memory

            studentName = other.studentName;
            size = other.size;
            marks = other.marks;       // steal the pointer

            other.size = 0;
            other.marks = nullptr;
        }
        return *this;
    }

    // 7. Destructor : frees the memory
    ~MarksList()
    {
        cout << "Destructor called for " << studentName << endl;
        delete[] marks;
    }

    void setName(string name)
    {
        studentName = name;
    }

    void setMark(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            marks[index] = value;
        }
    }

    void display()
    {
        cout << studentName << " -> Marks : ";
        if (size == 0)
        {
            cout << "(empty)";
        }
        for (int i = 0; i < size; i++)
        {
            cout << marks[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "----- Default Constructor -----" << endl;
    MarksList m1;
    m1.display();

    cout << "\n----- Parameterized Constructor -----" << endl;
    MarksList m2("Anjali", 3);
    m2.setMark(0, 85);
    m2.setMark(1, 90);
    m2.setMark(2, 78);
    m2.display();

    cout << "\n----- Copy Constructor -----" << endl;
    MarksList m3 = m2;          // copy constructor
    m3.setName("Anjali-Copy");  // change only the copy
    m3.setMark(0, 100);
    cout << "Original : ";
    m2.display();
    cout << "Copy     : ";
    m3.display();

    cout << "\n----- Move Constructor -----" << endl;
    MarksList m4 = std::move(m3);   // move constructor
    cout << "New object : ";
    m4.display();
    cout << "Old object : ";
    m3.display();

    cout << "\n----- Copy Assignment -----" << endl;
    MarksList m5("Rohan", 2);
    m5.setMark(0, 50);
    m5.setMark(1, 60);
    cout << "Before : ";
    m5.display();
    m5 = m2;                    // copy assignment (Rohan gets Anjali's data)
    cout << "After  : ";
    m5.display();

    cout << "\n----- Move Assignment -----" << endl;
    MarksList m6("Meera", 2);
    m6 = std::move(m4);         // move assignment (takes Anjali-Copy's data)
    cout << "New object : ";
    m6.display();
    cout << "Old object : ";
    m4.display();

    cout << "\n----- End of main, destructors will run now -----" << endl;
    return 0;
}
