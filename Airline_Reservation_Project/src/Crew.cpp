#include "../include/Crew.h"
#include <fstream>
#include <iostream>

using namespace std;

Crew::Crew(int id, const string& name) : id(id), name(name), assigned(false) {}

// Reads crew members from a file
vector<Crew> loadCrew(const string& filename) {
    vector<Crew> crewList;
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Unable to open " << filename << endl;
        return crewList;
    }
    int id;
    while (inFile >> id) {
        string name;
        getline(inFile, name);
        if (!name.empty() && name[0] == ' ') {
            name.erase(0, 1);
        }
        crewList.push_back(Crew(id, name));
    }
    inFile.close();
    return crewList;
}
