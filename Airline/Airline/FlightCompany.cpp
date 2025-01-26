#include "FlightCompany.h"
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

    static void saveAirplanesToFile(const vector<Airplane>& airplanes, const string& filename) {
        ofstream file(filename);
        if (!file) {
            cerr << "Error: Could not open file for writing: " << filename << endl;
            return;
        }
        for (const auto& airplane : airplanes) {
            file << airplane.getId() << "," << airplane.getManufacturer() << "," << airplane.getModel() << ","
                << airplane.getSeats() << "," << airplane.getMinRunwayLength() << "," << airplane.getFuelConsumptionPerKm()
                << "," << airplane.getFuelCapacity() << "," << airplane.getAverageSpeed() << "," << airplane.getStaffCosts() << endl;
        }
    }

    static vector<Airplane> loadAirplanesFromFile(const string& filename) {
        vector<Airplane> airplanes;
        ifstream file(filename);
        if (!file) {
            cerr << "Error: Could not open file for reading: " << filename << endl;
            return airplanes;
        }
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string id, manufacturer, model;
            int seats;
            double minRunwayLength, fuelConsumptionPerKm, fuelCapacity, averageSpeed, staffCost;

            getline(ss, id, ',');
            getline(ss, manufacturer, ',');
            getline(ss, model, ',');
            ss >> seats; ss.ignore();
            ss >> minRunwayLength; ss.ignore();
            ss >> fuelConsumptionPerKm; ss.ignore();
            ss >> fuelCapacity; ss.ignore();
            ss >> averageSpeed; ss.ignore();
            ss >> staffCost;

            airplanes.emplace_back(id, manufacturer, model, seats, minRunwayLength, fuelConsumptionPerKm, fuelCapacity, averageSpeed, staffCost);
        }
        return airplanes;
    }


void FlightCompany::addAirplane(const Airplane& airplane) {
    airplanes.push_back(airplane);
}

void FlightCompany::addFlight(const Flight& flight) {
    flights.push_back(flight);
}

void FlightCompany::searchAirplanesByDestination(const string& destination) {
    cout << "\nAirplanes available for destination: " << destination << "\n";
    bool found = false;

    for (const auto& flight : flights) {
        if (flight.getOrigin() == destination || flight.getDestination() == destination) {
            cout << "Flight from " << flight.getOrigin() << " to " << flight.getDestination();

            Airplane* airplane = flight.getAirplane();
            if (airplane) {
                cout << " uses airplane: " << *airplane << endl;
                double distance = flight.getDistance();

                cout << "Flight cost: " << airplane->calculateFlightCost(distance) << " USD" << endl;
                cout << "Max distance: " << airplane->getMaxDistance() << " km" << endl;
                cout << "Flight duration: " << airplane->calculateFlightDuration(distance) << " hours" << endl;
                cout << "Fuel efficiency (L per seat for this distance): "
                    << airplane->calculateFuelEfficiency(distance) << " L" << endl;
            }
            else {
                cout << " (No airplane information available)\n";
            }

            found = true;
        }
    }

    if (!found) {
        cout << "No flights found for destination: " << destination << endl;
    }
}

void FlightCompany::menu() {
    string filename = "airplanes.txt";
    int choice;
    do {
        cout << "\n1. Add Airplane\n2. Search by Destination\n3. Add Flight\n4. Save to File\n5. Load from File\n6. Exit\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string id, manufacturer, model;
            int seats;
            double minRunwayLength, fuelConsumptionPerKm, fuelCapacity, averageSpeed, staffCosts;

            cout << "Enter ID: "; cin >> id;
            cout << "Enter Manufacturer: "; cin >> manufacturer;
            cout << "Enter Model: "; cin >> model;
            cout << "Enter Seats: "; cin >> seats;
            cout << "Enter Min Runway Length: "; cin >> minRunwayLength;
            cout << "Enter Fuel Consumption per Km: "; cin >> fuelConsumptionPerKm;
            cout << "Enter Fuel Capacity: "; cin >> fuelCapacity;
            cout << "Enter Average Speed: "; cin >> averageSpeed;
            cout << "Enter Staff Costs: "; cin >> staffCosts;

            Airplane newAirplane(id, manufacturer, model, seats, minRunwayLength, fuelConsumptionPerKm, fuelCapacity, averageSpeed, staffCosts);
            addAirplane(newAirplane);
        }
        else if (choice == 2) {
            string destination;
            cout << "Enter destination to search: "; cin >> destination;
            searchAirplanesByDestination(destination);
        }
        else if (choice == 3) {
            string origin, destination;
            double distance;
            string airplaneId;

            cout << "Enter Origin: "; cin >> origin;
            cout << "Enter Destination: "; cin >> destination;
            cout << "Enter Distance: "; cin >> distance;
            cout << "Enter Airplane ID: "; cin >> airplaneId;

            Airplane* airplane = nullptr;
            for (auto& plane : airplanes) {
                if (plane.getId() == airplaneId) {
                    airplane = &plane;
                    break;
                }
            }

            if (airplane != nullptr) {
                Flight newFlight(origin, destination, airplane, distance);
                addFlight(newFlight);
                cout << "Flight added successfully!" << endl;
            }
            else {
                cout << "Error: Airplane with given ID not found!" << endl;
            }
        }
        else if (choice == 4) {
            saveAirplanesToFile(airplanes, filename);
        }
        else if (choice == 5) {
            airplanes = loadAirplanesFromFile(filename);
            for (auto& plane : airplanes) {
                cout << plane << endl;
            }
        }

    } while (choice != 6);

    cout << "Goodbye!\n";
}