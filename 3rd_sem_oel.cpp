#include <iostream>
#include <string>
using namespace std;

// Driver Node
class Driver {
public:
    int id;
    string name;
    int distance;      // distance from rider (km)
    bool available;
    Driver* next;

    Driver(int i, string n, int d) {
        id = i;
        name = n;
        distance = d;      // FIXED
        available = true;
        next = NULL;
    }
};

class RideSharingSystem {
private:
    Driver* head;

public:
    RideSharingSystem() {
        head = NULL;
    }

    void addDriver(int id, string name, int distance) {
        Driver* newDriver = new Driver(id, name, distance);

        if (head == NULL) {
            head = newDriver;
            return;
        }

        Driver* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newDriver;
    }

    // Display all drivers
    void displayDrivers() {
        Driver* temp = head;
        while (temp != NULL) {
            cout << "ID: " << temp->id
                 << " | Name: " << temp->name
                 << " | Distance: " << temp->distance << " km"
                 << " | Available: " << (temp->available ? "Yes" : "No")
                 << endl;
            temp = temp->next;
        }
    }

    void assignRide() {
        Driver* temp = head;
        Driver* nearest = NULL;
        int minDist = 9999;

        while (temp != NULL) {
            if (temp->available && temp->distance < minDist) {
                minDist = temp->distance;
                nearest = temp;
            }
            temp = temp->next;
        }

        if (nearest == NULL) {
            cout << "No driver available!" << endl;
        } else {
            cout << "Ride Assigned to: " << nearest->name << endl;
            nearest->available = false;
        }
    }
    void removeDriver(int id) {
        Driver* temp = head;
        Driver* prev = NULL;

        while (temp != NULL && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Driver not found" << endl;
            return;
        }

        if (prev == NULL) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }

        delete temp;
        cout << "Driver removed successfully" << endl;
    }
};

int main() {
    RideSharingSystem system;

    system.addDriver(1, "Ali", 5);
    system.addDriver(2, "Ahmed", 2);
    system.addDriver(3, "Usman", 7);

    cout << "\nAll Drivers:\n";
    system.displayDrivers();

    cout << "\nAssigning Ride...\n";
    system.assignRide();

    cout << "\nUpdated Drivers:\n";
    system.displayDrivers();

    return 0;
}
