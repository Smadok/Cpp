#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include "Airplane.h"
using namespace std;

class Flight {
private:
    string origin;
    string destination;
    Airplane* airplane;
    double distance;

public:
    Flight(const string& origin, const string& destination, Airplane* airplane, double distance);
    string getOrigin() const;
    string getDestination() const;
    Airplane* getAirplane() const;

    double getDistance() const;
    double calculateFlightDuration() const;
};

#endif 
