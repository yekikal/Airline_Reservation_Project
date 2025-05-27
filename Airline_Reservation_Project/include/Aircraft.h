#pragma once
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <string>
#include <vector>

class Aircraft {
public:
    int id;
    std::string model;
    bool assigned;
    Aircraft(int id = 0, const std::string& model = "");
};

// Loads aircraft from a file; each line has: ID Model
std::vector<Aircraft> loadAircraft(const std::string& filename);

#endif
