#include "../include/Aircraft.h"
#include <fstream>
#include <iostream>

using namespace std;

Aircraft::Aircraft(int id, const string& model) : id(id), model(model), assigned(false) {}

// Reads aircraft list from a file
vector<Aircraft> loadAircraft(const string& filename) {
    vector<Aircraft> aircrafts;
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Unable to open " << filename << endl;
        return aircrafts;
    }
    int id;
    while (inFile >> id) {
        string model;
        getline(inFile, model);
        if (!model.empty() && model[0] == ' ') {
            model.erase(0, 1);
        }
        aircrafts.push_back(Aircraft(id, model));
    }
    inFile.close();
    return aircrafts;
}
