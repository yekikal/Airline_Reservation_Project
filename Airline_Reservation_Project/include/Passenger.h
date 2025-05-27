#pragma once
#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <vector>

class Passenger {
public:
    int id;
    std::string name;
    Passenger(int id = 0, const std::string& name = "");
};

// Loads passengers from a given text file. Each line should contain an ID and a name.
std::vector<Passenger> loadPassengers(const std::string& filename);

#endif
