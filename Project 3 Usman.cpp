//Mohamed Usman Ali
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

const int SCRATCHEMUP_CAPACITY = 7;
const int BASHEMUP_CAPACITY = 7;
const int STREET_CAPACITY = 7;

// Queue initialization
std::queue<std::string> scratchemup_garage;
std::queue<std::string> bashemup_garage;
std::queue<std::string> street_queue;
std::unordered_map<std::string, int> positions;

int calculate_parking_fee(int position) {
    if (position == 0) return 15;
    if (position == 1) return 18;
    return 22;
}

void print_queue(std::queue<std::string> q) {
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    std::cout << std::endl;
}

void check_street_queue() {
    if (!street_queue.empty()) {
        std::string car_from_street = street_queue.front();
        street_queue.pop();
        if (scratchemup_garage.size() < SCRATCHEMUP_CAPACITY) {
            scratchemup_garage.push(car_from_street);
            std::cout << "Car " << car_from_street << " moved from the street to Scratchemup garage.\n";
        } else if (bashemup_garage.size() < BASHEMUP_CAPACITY) {
            bashemup_garage.push(car_from_street);
            std::cout << "Car " << car_from_street << " moved from the street to Bashemup garage.\n";
        }
    }
}

void handle_arrival(const std::string& license_plate) {
    if (scratchemup_garage.size() < SCRATCHEMUP_CAPACITY) {
        scratchemup_garage.push(license_plate);
        std::cout << "Car " << license_plate << " parked in Scratchemup garage.\n";
    } else if (bashemup_garage.size() < BASHEMUP_CAPACITY) {
        bashemup_garage.push(license_plate);
        std::cout << "Car " << license_plate << " parked in Bashemup garage.\n";
    } else if (street_queue.size() < STREET_CAPACITY) {
        street_queue.push(license_plate);
        std::cout << "Car " << license_plate << " is waiting on the street.\n";
    } else {
        std::cout << "Car " << license_plate << " is redirected to Boston.\n";
    }
}

void handle_departure(const std::string& license_plate) {
    bool found = false;
    int pos = 0;

    std::queue<std::string> temp;
    while (!scratchemup_garage.empty()) {
        std::string car = scratchemup_garage.front();
        scratchemup_garage.pop();
        if (car == license_plate) {
            std::cout << "Car " << car << " departed from Scratchemup garage. Parking fee: $" << calculate_parking_fee(pos) << "\n";
            found = true;
        } else {
            temp.push(car);
            pos++;
        }
    }
    scratchemup_garage = temp;

    if (!found) {
        pos = 0;
        while (!bashemup_garage.empty()) {
            std::string car = bashemup_garage.front();
            bashemup_garage.pop();
            if (car == license_plate) {
                std::cout << "Car " << car << " departed from Bashemup garage.\n";
                found = true;
            } else {
                temp.push(car);
                pos++;
            }
        }
        bashemup_garage = temp;
    }

    if (!found) {
        std::queue<std::string> street_temp;
        while (!street_queue.empty()) {
            std::string car = street_queue.front();
            street_queue.pop();
            if (car == license_plate) {
                std::cout << "Car " << car << " departed from the street.\n";
                found = true;
            } else {
                street_temp.push(car);
            }
        }
        street_queue = street_temp;
    }

    if (!found) {
        std::cout << "Car " << license_plate << " not found in any location.\n";
    }

    check_street_queue();
}

int main() {
    char action;
    std::string license_plate;

    while (true) {
        std::cout << "Enter action (a for arrival, d for departure, q to quit) and license plate: ";
        std::cin >> action;
        if (action == 'q') break;
        std::cin >> license_plate;

        if (action == 'a') {
            handle_arrival(license_plate);
        } else if (action == 'd') {
            handle_departure(license_plate);
        }
    }

    std::cout << "Exiting program...\n";
    std::cout << "Cars remaining in Scratchemup garage: " << scratchemup_garage.size() << "\n";
    std::cout << "Cars remaining in Bashemup garage: " << bashemup_garage.size() << "\n";
    std::cout << "Cars remaining on the street: " << street_queue.size() << "\n";

    return 0;
}
