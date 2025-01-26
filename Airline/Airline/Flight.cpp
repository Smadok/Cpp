#include "Flight.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Flight::Flight(const string& origin, const string& destination, Airplane* airplane, double distance)
    : origin(origin), destination(destination), airplane(airplane), distance(distance) {}

string Flight::getOrigin() const { return origin; }
string Flight::getDestination() const { return destination; }
Airplane* Flight::getAirplane() const { return airplane; }
double Flight::getDistance() const { return distance; }

double Flight::calculateFlightDuration() const {
    if (airplane == nullptr) {
        throw std::runtime_error("Airplane is not assigned.");
    }
    if (airplane->getAverageSpeed() <= 0) {
        throw std::invalid_argument("Airplane speed must be positive.");
    }
    return distance / airplane->getAverageSpeed();
}

