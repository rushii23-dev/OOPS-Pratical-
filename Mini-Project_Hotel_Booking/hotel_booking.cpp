#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class BookingException : public exception {
    string msg;
public:
    BookingException(string m) {
        msg = m;
    }
    const char *what() const noexcept override {
        return msg.c_str();
    }
};

class Room {
public:
    int roomNo;
    string type;
    double price;
    bool booked;
    int days;
    string guest;

    Room(int n, string t, double p) {
        roomNo = n;
        type = t;
        price = p;
        booked = false;
        days = 0;
        guest = "-";
    }

    void display() {
        cout << roomNo << "\t" << type << "\t" << price << "\t";
        if (booked)
            cout << "Booked by " << guest << " for " << days << " days" << endl;
        else
            cout << "Available" << endl;
    }
};

class Hotel {
private:
    vector<Room> rooms;

    int findRoom(int no) {
        for (int i = 0; i < (int)rooms.size(); i++) {
            if (rooms[i].roomNo == no)
                return i;
        }
        throw BookingException("Room not found");
    }

public:
    Hotel() {
        load();
        if (rooms.empty()) {
            rooms.push_back(Room(101, "Single", 1000));
            rooms.push_back(Room(102, "Single", 1000));
            rooms.push_back(Room(201, "Double", 1800));
            rooms.push_back(Room(202, "Double", 1800));
            rooms.push_back(Room(301, "Deluxe", 3000));
            save();
        }
    }

    void showAll() {
        cout << "Room\tType\tPrice\tStatus" << endl;
        for (Room r : rooms)
            r.display();
    }

    void showAvailable() {
        cout << "Room\tType\tPrice\tStatus" << endl;
        for (Room r : rooms) {
            if (!r.booked)
                r.display();
        }
    }

    void bookRoom(int no, string name, int days) {
        int i = findRoom(no);
        if (rooms[i].booked)
            throw BookingException("Room is already booked");
        if (days <= 0)
            throw BookingException("Days must be more than 0");
        rooms[i].booked = true;
        rooms[i].days = days;
        rooms[i].guest = name;
        save();
        cout << "Room " << no << " booked for " << name << endl;
        cout << "Total bill: " << rooms[i].price * days << endl;
    }

    void checkOut(int no) {
        int i = findRoom(no);
        if (!rooms[i].booked)
            throw BookingException("Room is not booked");
        cout << rooms[i].guest << " checked out. Bill paid: " << rooms[i].price * rooms[i].days << endl;
        rooms[i].booked = false;
        rooms[i].days = 0;
        rooms[i].guest = "-";
        save();
    }

    void searchGuest(string name) {
        for (Room r : rooms) {
            if (r.booked && r.guest == name) {
                cout << name << " is in room " << r.roomNo << endl;
                return;
            }
        }
        cout << "No booking found for " << name << endl;
    }

    void save() {
        ofstream fout("rooms.csv");
        for (Room r : rooms)
            fout << r.roomNo << "," << r.type << "," << r.price << "," << r.booked << "," << r.days << "," << r.guest << endl;
        fout.close();
    }

    void load() {
        ifstream fin("rooms.csv");
        string line;
        while (getline(fin, line)) {
            if (line == "")
                continue;
            stringstream ss(line);
            string no, type, price, booked, days, guest;
            getline(ss, no, ',');
            getline(ss, type, ',');
            getline(ss, price, ',');
            getline(ss, booked, ',');
            getline(ss, days, ',');
            getline(ss, guest);
            Room r(stoi(no), type, stod(price));
            r.booked = (booked == "1");
            r.days = stoi(days);
            r.guest = guest;
            rooms.push_back(r);
        }
        fin.close();
    }
};

int main() {
    Hotel h;
    int choice;

    do {
        cout << "\n----- Hotel Room Booking -----" << endl;
        cout << "1. Show All Rooms" << endl;
        cout << "2. Show Available Rooms" << endl;
        cout << "3. Book Room" << endl;
        cout << "4. Check Out" << endl;
        cout << "5. Search Guest" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        if (!cin)
            break;

        try {
            if (choice == 1)
                h.showAll();
            else if (choice == 2)
                h.showAvailable();
            else if (choice == 3) {
                int no = 0, days = 0;
                string name;
                cout << "Room number: ";
                cin >> no;
                cout << "Guest name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Number of days: ";
                cin >> days;
                h.bookRoom(no, name, days);
            }
            else if (choice == 4) {
                int no = 0;
                cout << "Room number: ";
                cin >> no;
                h.checkOut(no);
            }
            else if (choice == 5) {
                string name;
                cout << "Guest name: ";
                cin.ignore();
                getline(cin, name);
                h.searchGuest(name);
            }
            else if (choice != 0)
                cout << "Invalid choice" << endl;
        }
        catch (BookingException &e) {
            cout << "Error: " << e.what() << endl;
        }
    } while (choice != 0);

    cout << "Thank you" << endl;
    return 0;
}
