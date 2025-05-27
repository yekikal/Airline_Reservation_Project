#ifndef BOOKING_H
#define BOOKING_H

#include <vector>
#include <string>

class Passenger;
class Flight;

class Booking {
public:
    int id;
    Passenger* passenger;
    Flight* flight;
    bool refundable;
    Booking(int id, Passenger* p, Flight* f, bool ref);
};

// Loads bookings from a file, linking to the passengers and flights vectors
std::vector<Booking> loadBookings(const std::string& filename,
    std::vector<Passenger>& passengers,
    std::vector<Flight>& flights);

#endif
