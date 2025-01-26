#ifndef FLIGHT_COMPANY_H
#define FLIGHT_COMPANY_H

#include <vector>
#include <string>
#include "Airplane.h"
#include "Flight.h"
using namespace std;
class FlightCompany {
private:
    vector<Airplane> airplanes;
    vector<Flight> flights;

public:
    void addAirplane(const Airplane& airplane);
    void addFlight(const Flight& flight);
    void searchAirplanesByDestination(const string& destination);
    void menu();
};

#endif 
