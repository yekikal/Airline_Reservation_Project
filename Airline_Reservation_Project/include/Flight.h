#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include <vector>

class Aircraft; // forward declaration
class Crew;

class Flight {
public:
    int id;
    std::string origin;
    std::string destination;
    Aircraft* assignedAircraft;
    std::vector<Crew*> crewAssigned;
    Flight(int id = 0, const std::string& origin = "", const std::string& destination = "");
    void assignAircraft(Aircraft* ac);   // assign an aircraft
    void assignCrew(Crew* crewMember);   // assign a crew member
};

// Loads flights from a file; each line has: ID Origin Destination
std::vector<Flight> loadFlights(const std::string& filename);

#endif
