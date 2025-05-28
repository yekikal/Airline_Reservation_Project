
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "./include/Passenger.h"
#include "./include/Flight.h"
#include "./include/Crew.h"
#include "./include/Aircraft.h"
#include "./include/Booking.h"
#include "./include/Weather.h"

using namespace std;

int main() {
    // Load sample data from text files
    vector<Passenger> passengers = loadPassengers("passengers.txt");
    vector<Flight> flights = loadFlights("flights.txt");
    vector<Crew> crewList = loadCrew("crew.txt");
    vector<Aircraft> aircrafts = loadAircraft("aircraft.txt");
    vector<Booking> bookings = loadBookings("bookings.txt", passengers, flights);

    int choice;
    bool running = true;
    while (running) {
        // Display menu
        cout << "\n*** Airline Reservation System ***\n";
        cout << "1. Aircraft Assignment\n";
        cout << "2. List All Passengers\n";
        cout << "3. Refund Management\n";
        cout << "4. Assign Crew to Flight\n";
        cout << "5. Dashboard\n";
        cout << "6. API Integration - Weather Info\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Aircraft Assignment
            cout << "\n-- Aircraft Assignment --\n";
            // List flights
            cout << "Flights:\n";
            for (auto& f : flights) {
                cout << "ID: " << f.id << " (" << f.origin << " -> " << f.destination << ")";
                if (f.assignedAircraft) {
                    cout << " [Aircraft ID: " << f.assignedAircraft->id << "]";
                }
                cout << "\n";
            }
            // List aircraft
            cout << "Aircraft available:\n";
            for (auto& ac : aircrafts) {
                cout << "ID: " << ac.id << " (" << ac.model << ")";
                if (ac.assigned) cout << " [assigned]";
                cout << "\n";
            }
            // Prompt for assignment
            cout << "Enter Flight ID and Aircraft ID to assign: ";
            int fid, aid;
            cin >> fid >> aid;
            // Find the flight and aircraft by ID
            Flight* flightPtr = nullptr;
            Aircraft* aircraftPtr = nullptr;
            for (auto& f : flights) {
                if (f.id == fid) {
                    flightPtr = &f;
                    break;
                }
            }
            for (auto& ac : aircrafts) {
                if (ac.id == aid) {
                    aircraftPtr = &ac;
                    break;
                }
            }
            // Perform checks and assign if valid
            if (!flightPtr) {
                cout << "Flight ID not found!\n";
            }
            else if (!aircraftPtr) {
                cout << "Aircraft ID not found!\n";
            }
            else if (flightPtr->assignedAircraft != nullptr) {
                cout << "This flight already has an aircraft assigned!\n";
            }
            else if (aircraftPtr->assigned) {
                cout << "This aircraft is already assigned to a flight!\n";
            }
            else {
                flightPtr->assignAircraft(aircraftPtr);
                cout << "Aircraft ID " << aid << " assigned to Flight ID " << fid << ".\n";
            }
            break;
        }
        case 2: {
            // List All Passengers
            cout << "\n-- List of All Passengers --\n";
            for (auto& p : passengers) {
                cout << "ID: " << p.id << ", Name: " << p.name << "\n";
            }
            break;
        }
        case 3: {
            // Refund Management (Cancel Booking)
            cout << "\n-- Refund Management (Cancel Booking) --\n";
            cout << "Bookings:\n";
            for (auto& b : bookings) {
                cout << "Booking ID: " << b.id
                    << ", Passenger: " << b.passenger->name
                    << ", Flight ID: " << b.flight->id
                    << ", Refundable: " << (b.refundable ? "Yes" : "No") << "\n";
            }
            cout << "Enter Booking ID to cancel: ";
            int bid;
            cin >> bid;
            bool found = false;
            // Find booking by ID
            for (auto it = bookings.begin(); it != bookings.end(); ++it) {
                if (it->id == bid) {
                    found = true;
                    if (it->refundable) {
                        cout << "Booking " << bid << " is refundable. Processing refund...\n";
                        bookings.erase(it); // remove booking
                        cout << "Booking cancelled and refund processed.\n";
                    }
                    else {
                        cout << "Booking " << bid << " is not refundable. No refund.\n";
                    }
                    break;
                }
            }
            if (!found) {
                cout << "Booking ID not found.\n";
            }
            break;
        }
        case 4: {
            // Assign Crew to Flight
            cout << "\n-- Assign Crew to Flight --\n";
            // List flights
            cout << "Flights:\n";
            for (auto& f : flights) {
                cout << "ID: " << f.id << " (" << f.origin << " -> " << f.destination << ")\n";
            }
            // List crew members
            cout << "Crew members available:\n";
            for (auto& c : crewList) {
                cout << "ID: " << c.id << ", Name: " << c.name;
                if (c.assigned) cout << " [assigned]";
                cout << "\n";
            }
            // Prompt for assignment
            cout << "Enter Flight ID and Crew ID to assign: ";
            int fid2, cid;
            cin >> fid2 >> cid;
            Flight* flightPtr2 = nullptr;
            Crew* crewPtr = nullptr;
            for (auto& f : flights) {
                if (f.id == fid2) {
                    flightPtr2 = &f;
                    break;
                }
            }
            for (auto& c : crewList) {
                if (c.id == cid) {
                    crewPtr = &c;
                    break;
                }
            }
            // Perform checks and assign
            if (!flightPtr2) {
                cout << "Flight ID not found!\n";
            }
            else if (!crewPtr) {
                cout << "Crew ID not found!\n";
            }
            else if (crewPtr->assigned) {
                cout << "Crew member is already assigned to a flight!\n";
            }
            else {
                flightPtr2->assignCrew(crewPtr);
                cout << "Crew ID " << cid << " assigned to Flight ID " << fid2 << ".\n";
            }
            break;
        }
        case 5: {
            // Dashboard
            cout << "\n-- Dashboard --\n";
            cout << "Total Flights: " << flights.size() << "\n";
            cout << "Total Passengers: " << passengers.size() << "\n";
            cout << "Total Crew Members: " << crewList.size() << "\n";
            cout << "Flight assignments:\n";
            for (auto& f : flights) {
                cout << "Flight ID " << f.id << ": ";
                if (f.assignedAircraft) {
                    cout << "Aircraft ID " << f.assignedAircraft->id;
                }
                else {
                    cout << "No aircraft assigned";
                }
                cout << "; Crew assigned: " << f.crewAssigned.size() << "\n";
            }
            break;
        }
        case 6: {
            // API Integration (Weather Info)
            cout << "\n-- API Integration: Weather Info --\n";
            cout << "Enter city (e.g., NewYork, Paris): ";
            string city;
            cin >> city;
            string result = getWeather(city, "weather.txt");
            cout << "Weather data: " << result << "\n";
            break;
        }
        case 0: {
            running = false;
            cout << "Exiting the system. Goodbye!\n";
            break;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    }

    return 0;
}

