#include "../include/Booking.h"
#include "../include/Passenger.h"
#include "../include/Flight.h"
#include <fstream>
#include <iostream>

using namespace std;

Booking::Booking(int id, Passenger* p, Flight* f, bool ref)
    : id(id), passenger(p), flight(f), refundable(ref) {
}

// Reads bookings from file and links to passengers and flights
vector<Booking> loadBookings(const string& filename,
    vector<Passenger>& passengers,
    vector<Flight>& flights) {
    vector<Booking> bookings;
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Unable to open " << filename << endl;
        return bookings;
    }
    int id, pid, fid;
    bool ref;
    while (inFile >> id >> pid >> fid >> ref) {
        Passenger* pPtr = nullptr;
        for (auto& p : passengers) {
            if (p.id == pid) {
                pPtr = &p;
                break;
            }
        }
        Flight* fPtr = nullptr;
        for (auto& f : flights) {
            if (f.id == fid) {
                fPtr = &f;
                break;
            }
        }
        if (pPtr && fPtr) {
            bookings.push_back(Booking(id, pPtr, fPtr, ref));
        }
    }
    inFile.close();
    return bookings;
}
