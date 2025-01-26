#include <iostream>
#include <string>
#include <vector>
#include <limits>  
using namespace std;

class Worker
{
private:
    int socialNumber;
    string name;
    int yearsExperience;
    string position;
    vector<double> salaries;
public:

    Worker() {
        socialNumber = 0;
        yearsExperience = 0;
        cout << "Въведете текуща длъжност: ";
        cin >> position;
    }
   
    Worker(int socNum, string workerName, int experience, string jobPosition) {
        socialNumber = socNum;
        name = workerName;
        yearsExperience = experience;
        position = jobPosition;
    }
  
    void setSocialNumber(int socNum) { socialNumber = socNum; }
    int getSocialNumber() { return socialNumber; }

    void setName(string workerName) { name = workerName; }
    string getName() { return name; }

    void setYearsExperience(int experience) { yearsExperience = experience; }
    int getYearsExperience() { return yearsExperience; }

    void setPosition(string jobPosition) { position = jobPosition; }
    string getPosition() { return position; }

    void addSalary(double salary) { salaries.push_back(salary); }
    vector<double> getSalaries() { return salaries; }

    double calculateAverageSalary() {
        if (salaries.empty()) return 0.0;

        double sum = 0;
        for (double salary : salaries) {
            sum += salary;
        }
        return sum / salaries.size();
    }
    
    double findMinSalary() {
        if (salaries.empty()) return 0.0;

        double minSalary = numeric_limits<double>::max();
        for (double salary : salaries) {
            if (salary < minSalary) {
                minSalary = salary;
            }
        }
        return minSalary;
    }
   
    void showInfo() {
        cout << "Социален номер: " << socialNumber << endl;
        cout << "Име: " << name << endl;
        cout << "Години трудов стаж: " << yearsExperience << endl;
        cout << "Текуща длъжност: " << position << endl;
        cout << "Заплати: ";
        for (double salary : salaries) {
            cout << salary << " ";
        }
        cout << endl;
    }

};

int main() {
    Worker worker1;

    worker1.setSocialNumber(123456);
    worker1.setName("Иван Иванов");
    worker1.setYearsExperience(10);

    worker1.addSalary(1200);
    worker1.addSalary(1300);
    worker1.addSalary(1250);
    worker1.showInfo();
    cout << "Средна заплата: " << worker1.calculateAverageSalary() << endl;

    cout << "Минимална заплата: " << worker1.findMinSalary() << endl;

    return 0;
}

