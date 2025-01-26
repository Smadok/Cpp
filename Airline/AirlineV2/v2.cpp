#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

class Airplane {
private:
    string id;
    string manufacturer;
    string model;
    int seats;
    double minRunwayLength;
    double fuelConsumptionPerKm;
    double fuelCapacity;
    double averageSpeed;
    double staffCosts;

public:
    // Constructor
    Airplane(string id, string manufacturer, string model, int seats, double minRunwayLength,
        double fuelConsumptionPerKm, double fuelCapacity, double averageSpeed, double staffCosts)
        : id(id), manufacturer(manufacturer), model(model), seats(seats),
        minRunwayLength(minRunwayLength), fuelConsumptionPerKm(fuelConsumptionPerKm),
        fuelCapacity(fuelCapacity), averageSpeed(averageSpeed), staffCosts(staffCosts) {}

    // Getters and setters
    string getId() const { return id; }
    void setId(const string& value) { id = value; }

    string getManufacturer() const { return manufacturer; }
    void setManufacturer(const string& value) { manufacturer = value; }

    string getModel() const { return model; }
    void setModel(const string& value) { model = value; }

    int getSeats() const { return seats; }
    void setSeats(int value) { seats = value; }

    double getMinRunwayLength() const { return minRunwayLength; }
    void setMinRunwayLength(double value) { minRunwayLength = value; }

    double getFuelConsumptionPerKm() const { return fuelConsumptionPerKm; }
    void setFuelConsumptionPerKm(double value) { fuelConsumptionPerKm = value; }

    double getFuelCapacity() const { return fuelCapacity; }
    void setFuelCapacity(double value) { fuelCapacity = value; }

    double getAverageSpeed() const { return averageSpeed; }
    void setAverageSpeed(double value) { averageSpeed = value; }

    double getStaffCosts() const { return staffCosts; }
    void setStaffCosts(double value) { staffCosts = value; }

    // Calculate flight cost (fuel consumption per km * seats + staff costs)
    double calculateFlightCost(double distance) const {
        return distance * fuelConsumptionPerKm * seats + staffCosts;
    }

    // Calculate max distance (based on fuel capacity and fuel consumption)
    double getMaxDistance() const {
        return fuelCapacity / fuelConsumptionPerKm;
    }

    // Calculate flight duration (based on average speed and distance)
    double calculateFlightDuration(double distance) const {
        return distance / averageSpeed;
    }

    // Efficiency: fuel consumption per seat for a given distance
    double calculateFuelEfficiency(double distance) const {
        return (fuelConsumptionPerKm * distance) / seats;
    }

    // Output
    friend ostream& operator<<(ostream& os, const Airplane& airplane) {
        os << "ID: " << airplane.id
            << ", Manufacturer: " << airplane.manufacturer
            << ", Model: " << airplane.model
            << ", Seats: " << airplane.seats
            << ", Min Runway Length: " << fixed << setprecision(2) << airplane.minRunwayLength << " m"
            << ", Fuel Consumption: " << airplane.fuelConsumptionPerKm << " L/km"
            << ", Fuel Capacity: " << airplane.fuelCapacity << " L"
            << ", Average Speed: " << airplane.averageSpeed << " km/h"
            << ", Staff Costs: " << airplane.staffCosts << " USD";
        return os;
    }
};

class Flight {
private:
    string origin;
    string destination;
    Airplane* airplane;
    double distance;

public:
    Flight(string origin, string destination, Airplane* airplane, double distance)
        : origin(origin), destination(destination), airplane(airplane), distance(distance) {}

    string getOrigin() const { return origin; }
    string getDestination() const { return destination; }
    Airplane* getAirplane() const { return airplane; }
    double getDistance() const { return distance; }

    double calculateFlightDuration() const {
        return distance / airplane->getAverageSpeed();
    }
};

// File operations
void saveAirplanesToFile(const vector<Airplane>& airplanes, const string& filename) {
    ofstream file(filename);
    for (const auto& airplane : airplanes) {
        file << airplane.getId() << "," << airplane.getManufacturer() << "," << airplane.getModel() << ","
            << airplane.getSeats() << "," << airplane.getMinRunwayLength() << "," << airplane.getFuelConsumptionPerKm()
            << "," << airplane.getFuelCapacity() << "," << airplane.getAverageSpeed() << "," << airplane.getStaffCosts() << endl;
    }
}

vector<Airplane> loadAirplanesFromFile(const string& filename) {
    vector<Airplane> airplanes;
    ifstream file(filename);
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

class FlightCompany {
private:
    vector<Airplane> airplanes;
    vector<Flight> flights;

public:
    void addAirplane(const Airplane& airplane) {
        airplanes.push_back(airplane);
    }

    void addFlight(const Flight& flight) {
        flights.push_back(flight);
    }

    void searchAirplanesByDestination(const string& destination) {
        cout << "\nAirplanes available for destination: " << destination << "\n";
        bool found = false;

        for (const auto& flight : flights) {
            if (flight.getOrigin() == destination || flight.getDestination() == destination) {
                cout << "Flight from " << flight.getOrigin() << " to " << flight.getDestination();

                // Check if the airplane pointer is valid before dereferencing
                Airplane* airplane = flight.getAirplane();
                if (airplane) {
                    cout << " uses airplane: " << *airplane << endl;
                    double distance = flight.getDistance();

                    // Calculate and display additional information
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

    void menu() {
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

                // Find the airplane by ID
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
                for (auto& plane : airplanes)
                {
                    cout << plane << endl;
                }
            }

        } while (choice != 6);

        cout << "Goodbye!\n";
    }
};

int main() {
    FlightCompany fc;
    fc.menu();
    return 0;
}