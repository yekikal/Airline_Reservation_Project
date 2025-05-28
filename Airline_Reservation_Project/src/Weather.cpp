#include "../include/Weather.h"
#include <fstream>
#include <iostream>

using namespace std;

string getWeather(const string& city, const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cout << "Unable to open " << filename << endl;
        return "";
    }
    string line;
    while (getline(inFile, line)) {
        if (line.find(city + ":") == 0) {
            inFile.close();
            return line;
        }
    }
    inFile.close();
    return "Weather data not found for " + city;
}
