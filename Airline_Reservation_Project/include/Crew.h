#ifndef CREW_H
#define CREW_H

#include <string>
#include <vector>

class Crew {
public:
    int id;
    std::string name;
    bool assigned;
    Crew(int id = 0, const std::string& name = "");
};

// Loads crew members from a file; each line has: ID Name
std::vector<Crew> loadCrew(const std::string& filename);

#endif
