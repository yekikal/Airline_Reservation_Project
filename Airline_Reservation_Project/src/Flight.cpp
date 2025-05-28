#include "../include/Flight.h"
#include "../include/Aircraft.h"
#include "../include/Crew.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

Flight::Flight(int id, const string& origin, const string& destination)
    : id(id), origin(origin), destination(destination), assignedAircraft(nullptr) {
}

// Assign an aircraft to this flight and mark the aircraft as assigned
void Flight::assignAircraft(Aircraft* ac) {
    assignedAircraft = ac;
    ac->assigned = true;
}

// Assign a crew member to this flight and mark the crew member as assigned
void Flight::assignCrew(Crew* crewMember) {
    crewAssigned.push_back(crewMember);
    crewMember->assigned = true;
}

// Reads flights from a file; each line: ID Origin Destination
vector<Flight> loadFlights(const string& filename) {
    vector<Flight> flights;
    ifstream inFile(filename);

    if (!inFile) {
        cout << "Unable to open " << filename << endl;
        return flights;
    }
    int id;
    string origin, dest;
    while (inFile >> id >> origin >> dest) {
        flights.push_back(Flight(id, origin, dest));
    }
    
    if (flights.empty()) {
        cout << "No flights found in " << filename << endl;
    } else {
        cout << flights.size() << " flights loaded from " << filename << endl;
	}
    cout << "Loaded flight ID: " << id << " from " << origin << " to " << dest << endl;
    inFile.close();
    return flights;
}
