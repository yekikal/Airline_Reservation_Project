#include "../include/Passenger.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

// Constructor
Passenger::Passenger(int id, const string& name) : id(id), name(name) {}

// Reads passengers from a file and returns them in a vector
vector<Passenger> loadPassengers(const string& filename) {
    vector<Passenger> passengers;
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Unable to open " << filename << endl;
        return passengers;
    }
    int id;
    while (inFile >> id) {
        string name;
        getline(inFile, name);
        if (!name.empty() && name[0] == ' ') {
            name.erase(0, 1); // remove leading space
        }
        passengers.push_back(Passenger(id, name));
    }
    inFile.close();
    return passengers;
}
