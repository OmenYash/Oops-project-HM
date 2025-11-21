#include <iostream>
#include <string>
using namespace std;

class Room {
private:
    int roomNumber;
    string roomType;
    float price;
    bool isBooked;

public:
    // Default constructor
    Room() {
        roomNumber = 0;
        roomType = "None";
        price = 0;
        isBooked = false;
    }

    // Parameterized constructor
    Room(int rNo, string type, float pr) {
        roomNumber = rNo;
        roomType = type;
        price = pr;
        isBooked = false;
    }

    // Book the room
    void bookRoom() {
        if (isBooked)
            cout << "Room " << roomNumber << " is already booked!\n";
        else {
            isBooked = true;
            cout << "Room " << roomNumber << " booked successfully!\n";
        }
    }

    // Checkout
    void checkoutRoom() {
        if (!isBooked)
            cout << "Room " << roomNumber << " is already available!\n";
        else {
            isBooked = false;
            cout << "Room " << roomNumber << " is now available!\n";
        }
    }

    // Display room details
    void displayRoom() {
        cout << "Room Number: " << roomNumber
             << " | Type: " << roomType
             << " | Price: " << price
             << " | Status: " << (isBooked ? "Booked" : "Available") 
             << endl;
    }

    int getRoomNumber() {
        return roomNumber;
    }

    bool getIsBooked() {
        return isBooked;
    }
};

class Hotel {
private:
    Room rooms[5];     // 5-room hotel for project simplicity
    int totalRooms;

public:
    Hotel() {
        totalRooms = 5;
        rooms[0] = Room(101, "Single", 1500);
        rooms[1] = Room(102, "Double", 2500);
        rooms[2] = Room(201, "Deluxe", 3500);
        rooms[3] = Room(202, "Suite", 5000);
        rooms[4] = Room(301, "Luxury Suite", 8000);
    }

    void showAvailableRooms() {
        cout << "\n--- Available Rooms ---\n";
        for (int i = 0; i < totalRooms; i++) {
            rooms[i].displayRoom();
        }
        cout << endl;
    }

    void bookRoomByNumber(int rNo) {
        for (int i = 0; i < totalRooms; i++) {
            if (rooms[i].getRoomNumber() == rNo) {
                rooms[i].bookRoom();
                return;
            }
        }
        cout << "Invalid Room Number!\n";
    }

    void checkoutRoomByNumber(int rNo) {
        for (int i = 0; i < totalRooms; i++) {
            if (rooms[i].getRoomNumber() == rNo) {
                rooms[i].checkoutRoom();
                return;
            }
        }
        cout << "Invalid Room Number!\n";
    }
};

int main() {
    Hotel hotel;
    int choice, roomNo;

    do {
        cout << "\n===== HOTEL MANAGEMENT SYSTEM =====\n";
        cout << "1. Show All Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Checkout a Room\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hotel.showAvailableRooms();
            break;

        case 2:
            cout << "Enter room number to book: ";
            cin >> roomNo;
            hotel.bookRoomByNumber(roomNo);
            break;

        case 3:
            cout << "Enter room number to checkout: ";
            cin >> roomNo;
            hotel.checkoutRoomByNumber(roomNo);
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
