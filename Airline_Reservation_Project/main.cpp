#include <iostream>
#include "./include/booking_management.h" 
#include "./include/crew_management.h"
#include "./include/flight_management.h"
#include "./include/passenger_management.h"
#include "./include/reporting.h"
#include "./include/system_administration.h"

using namespace std;

int main() {
    int choice;
    do {
        cout << "\n====== Airline Reservation System ======\n";
        cout << "1. Aircraft Assignment (Flight Management)\n";
        cout << "2. List All Passengers (Passenger Management)\n";
        cout << "3. Refund Booking (Booking Management)\n";
        cout << "4. Assign Crew to Flight (Crew Management)\n";
        cout << "5. Dashboard (Reporting)\n";
        cout << "6. API Integration (System Administration)\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
        case 1: cout<< "aircraftAssignment()"; break;
        case 2: cout << "listPassengers()"; break;
        case 3: cout << "refundBooking()"; break;
        case 4: cout << "assignCrew()"; break;
        case 5: cout << "showDashboard()"; break;
        case 6: cout << "apiIntegration()"; break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid option.\n";
        }

    } while (choice != 0);

    return 0;
}
