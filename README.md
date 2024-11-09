
# Garage Parking System

## Project Overview
This Garage Parking System is designed to manage a car parking facility with two garages and a street queue. It uses a queue-based system to handle car arrivals and departures, ensuring efficient management of parking spaces.

## Features
- **Single Lane Garage Management**: Handles up to 7 cars in the Scratchemup garage and 7 cars in the Bashemup garage.
- **Street Queue**: Manages a queue of up to 7 cars waiting on the street when both garages are full.
- **Dynamic Car Handling**: Cars are dynamically added to and removed from the garages and street queue based on arrival and departure requests.
- **Parking Fee Calculation**: Calculates parking fees based on car position and duration.
- **Overflow Management**: Redirects cars to an alternative location when both garages and the street queue are full.

## System Requirements
- C++ Compiler (e.g., GCC, Clang, MSVC)
- Basic knowledge of C++ and command line operations

## Installation
1. Clone the repository or download the source code:
   ```bash
   git clone https://your-repository-url.com
   ```
2. Navigate to the project directory:
   ```bash
   cd garage-parking-system
   ```

## Usage
1. Compile the project using a C++ compiler:
   ```bash
   g++ -o garage_parking_system main.cpp
   ```
2. Run the compiled executable:
   ```bash
   ./garage_parking_system
   ```

## Inputs and Outputs
- **Input**: The program expects inputs in the format `[action] [license_plate]`, where `action` can be 'a' (arrival) or 'd' (departure).
- **Output**: Displays messages about parking status, fees, and redirections as cars arrive and depart.

## Example
```plaintext
Enter action (a for arrival, d for departure, q to quit) and license plate:
a ABC123
Car ABC123 parked in Scratchemup garage.
d ABC123
Car ABC123 departed from Scratchemup garage. Parking fee: $15
q
Exiting program...
Cars remaining in Scratchemup garage: 0
Cars remaining in Bashemup garage: 0
Cars remaining on the street: 0
```

## Contributing
Contributions to this project are welcome. Please fork the repository and submit pull requests with any new features or fixes.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
