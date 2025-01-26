#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <string>
#include <iostream>
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
    Airplane(const string& id, const string& manufacturer, const string& model,
        int seats, double minRunwayLength, double fuelConsumptionPerKm,
        double fuelCapacity, double averageSpeed, double staffCosts);

    // Getters and Setters
    string getId() const;
    void setId(const string& value);
    string getManufacturer() const;
    void setManufacturer(const string& value);
    string getModel() const;
    void setModel(const string& value);
    int getSeats() const;
    void setSeats(int value);
    double getMinRunwayLength() const;
    void setMinRunwayLength(double value);
    double getFuelConsumptionPerKm() const;
    void setFuelConsumptionPerKm(double value);
    double getFuelCapacity() const;
    void setFuelCapacity(double value);
    double getAverageSpeed() const;
    void setAverageSpeed(double value);
    double getStaffCosts() const;
    void setStaffCosts(double value);

    // ??????
    double calculateFlightCost(double distance) const;
    double getMaxDistance() const;
    double calculateFlightDuration(double distance) const;
    double calculateFuelEfficiency(double distance) const;

    friend ostream& operator<<(ostream& os, const Airplane& airplane);
};

#endif 
