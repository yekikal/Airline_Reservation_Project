#ifndef WEATHER_H
#define WEATHER_H

#include <string>

// Returns the weather info for a given city by reading a mock file
std::string getWeather(const std::string& city, const std::string& filename);

#endif
