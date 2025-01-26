#include "Airplane.h"
using namespace std;

Airplane::Airplane(const string& id, const string& manufacturer, const string& model,
    int seats, double minRunwayLength, double fuelConsumptionPerKm,
    double fuelCapacity, double averageSpeed, double staffCosts)
    : id(id), manufacturer(manufacturer), model(model), seats(seats),
    minRunwayLength(minRunwayLength), fuelConsumptionPerKm(fuelConsumptionPerKm),
    fuelCapacity(fuelCapacity), averageSpeed(averageSpeed), staffCosts(staffCosts) {}

string Airplane::getId() const { return id; }
void Airplane::setId(const string& value) { id = value; }

string Airplane::getManufacturer() const { return manufacturer; }
void Airplane::setManufacturer(const string& value) { manufacturer = value; }

string Airplane::getModel() const { return model; }
void Airplane::setModel(const string& value) { model = value; }

int Airplane::getSeats() const { return seats; }
void Airplane::setSeats(int value) { seats = value; }

double Airplane::getMinRunwayLength() const { return minRunwayLength; }
void Airplane::setMinRunwayLength(double value) { minRunwayLength = value; }

double Airplane::getFuelConsumptionPerKm() const { return fuelConsumptionPerKm; }
void Airplane::setFuelConsumptionPerKm(double value) { fuelConsumptionPerKm = value; }

double Airplane::getFuelCapacity() const { return fuelCapacity; }
void Airplane::setFuelCapacity(double value) { fuelCapacity = value; }

double Airplane::getAverageSpeed() const { return averageSpeed; }
void Airplane::setAverageSpeed(double value) { averageSpeed = value; }

double Airplane::getStaffCosts() const { return staffCosts; }
void Airplane::setStaffCosts(double value) { staffCosts = value; }
//логика
double Airplane::calculateFlightCost(double distance) const {
    double fuelCostPerLiter = 1.5; 
    double totalFuelConsumed = distance * fuelConsumptionPerKm;
    double fuelCost = totalFuelConsumed * fuelCostPerLiter;
    return fuelCost + staffCosts; 
}

double Airplane::getMaxDistance() const {
    return fuelCapacity / fuelConsumptionPerKm;
}

double Airplane::calculateFlightDuration(double distance) const {
    return distance / averageSpeed;
}

double Airplane::calculateFuelEfficiency(double distance) const {
    return (fuelConsumptionPerKm * distance) / seats;
}
//предефиниране
ostream& operator<<(ostream& os, const Airplane& airplane) {
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
