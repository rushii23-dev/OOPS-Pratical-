#include <iostream>
#include <utility>
using namespace std;

class Marks {
private:
    int *m;
public:
    Marks() {
        m = new int(0);
        cout << "Default constructor" << endl;
    }

    Marks(int x) {
        m = new int(x);
        cout << "Parameterized constructor" << endl;
    }

    Marks(const Marks &obj) {
        m = new int(*obj.m);
        cout << "Copy constructor" << endl;
    }

    Marks(Marks &&obj) noexcept {
        m = obj.m;
        obj.m = nullptr;
        cout << "Move constructor" << endl;
    }

    Marks &operator=(const Marks &obj) {
        if (this != &obj) {
            delete m;
            m = new int(*obj.m);
        }
        cout << "Copy assignment" << endl;
        return *this;
    }

    Marks &operator=(Marks &&obj) noexcept {
        if (this != &obj) {
            delete m;
            m = obj.m;
            obj.m = nullptr;
        }
        cout << "Move assignment" << endl;
        return *this;
    }

    ~Marks() {
        delete m;
        cout << "Destructor" << endl;
    }

    void show() {
        if (m != nullptr)
            cout << "Marks: " << *m << endl;
        else
            cout << "Marks: empty" << endl;
    }
};

int main() {
    Marks a;
    a.show();

    Marks b(85);
    b.show();

    Marks c = b;
    c.show();

    Marks d = move(c);
    d.show();
    c.show();

    Marks e;
    e = b;
    e.show();

    Marks f;
    f = move(d);
    f.show();
    d.show();

    cout << "End of main" << endl;
    return 0;
}
