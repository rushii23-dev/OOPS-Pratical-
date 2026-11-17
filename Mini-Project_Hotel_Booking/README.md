# Mini Project : Hotel Room Booking System

A simple menu-driven Hotel Room Booking System in C++. You can see all rooms, see free rooms, book a room, check out and search for a guest. All bookings are saved in `rooms.csv`, so they are still there when you run the program again.

## Features

1. Show all rooms with their status
2. Show only available rooms
3. Book a room (room number, guest name, number of days) and show the bill
4. Check out a guest and free the room
5. Search which room a guest is in

## Rooms

| Room | Type | Price per day |
|---|---|---|
| 101, 102 | Single | 1000 |
| 201, 202 | Double | 1800 |
| 301 | Deluxe | 3000 |

## Concepts Used

| Concept | Where |
|---|---|
| Class and object | `Room`, `Hotel` |
| Constructor | `Room(int, string, double)`, `Hotel()` loads saved data |
| Access specifiers | `rooms` and `findRoom()` are private in `Hotel` |
| Member functions | `bookRoom()`, `checkOut()`, `searchGuest()` |
| Custom exception | `BookingException` (child of `exception`) |
| try / catch / throw | Wrong room, room already booked, wrong days |
| noexcept | `what()` |
| vector | Stores all rooms |
| Range-based for loop | Showing and searching rooms |
| File handling | `ofstream` to save, `ifstream` to load |
| stringstream | Splitting a CSV line |

## How to Run

```bash
g++ -std=c++17 hotel_booking.cpp -o hotel_booking
./hotel_booking
```

## Sample Output

```
----- Hotel Room Booking -----
1. Show All Rooms
2. Show Available Rooms
3. Book Room
4. Check Out
5. Search Guest
0. Exit
Enter choice: 1
Room	Type	Price	Status
101	Single	1000	Available
102	Single	1000	Available
201	Double	1800	Available
202	Double	1800	Available
301	Deluxe	3000	Available

Enter choice: 3
Room number: 101
Guest name: Rahul Sharma
Number of days: 3
Room 101 booked for Rahul Sharma
Total bill: 3000

Enter choice: 3
Room number: 101
Guest name: Amit
Number of days: 2
Error: Room is already booked

Enter choice: 3
Room number: 999
Guest name: X
Number of days: 1
Error: Room not found

Enter choice: 2
Room	Type	Price	Status
102	Single	1000	Available
201	Double	1800	Available
202	Double	1800	Available
301	Deluxe	3000	Available

Enter choice: 5
Guest name: Rahul Sharma
Rahul Sharma is in room 101

Enter choice: 4
Room number: 101
Rahul Sharma checked out. Bill paid: 3000

Enter choice: 0
Thank you
```
