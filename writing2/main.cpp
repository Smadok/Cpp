#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Date {
private:
    int day, month, year;
public:
    Date(int d = 1, int m = 1, int y = 2024) : day(d), month(m), year(y) {}

    // Copy constructor
    Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

    // Overloaded << operator for printing
    friend ostream& operator<<(ostream& os, const Date& date) {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }
};


class Visit {
private:
    string egn;       
    string name;      
    string complaint;
    Date visitDate;   
    vector<string> prescribedMedicines; 

public:
    Visit(string e, string n, string c, Date d, vector<string> meds)
        : egn(e), name(n), complaint(c), visitDate(d), prescribedMedicines(meds) {}

 
    friend ostream& operator<<(ostream& os, const Visit& visit) {
        os << "EGN: " << visit.egn << ", Name: " << visit.name << ", Complaint: "
            << visit.complaint << ", Date: " << visit.visitDate << ", Medicines: ";
        for (const auto& med : visit.prescribedMedicines)
            os << med << " ";
        return os;
    }

    string getComplaint() const {
        return complaint;
    }
};


void group4Task() {
    vector<Visit> visits;
    visits.push_back(Visit("1234567890", "John Doe", "Headache", Date(10, 6, 2024), { "Paracetamol" }));
    visits.push_back(Visit("0987654321", "Jane Smith", "Fever", Date(12, 6, 2024), { "Ibuprofen", "Vitamin C" }));

    string targetComplaint = "Fever";
    cout << "Patients with complaint: " << targetComplaint << endl;
    for (const auto& visit : visits) {
        if (visit.getComplaint() == targetComplaint) {
            cout << visit << endl;
        }
    }
}


class Reader {
protected:
    string name;
    int id;
public:
    Reader(string n = "", int i = 0) : name(n), id(i) {}

    virtual void display() const {
        cout << "Reader ID: " << id << ", Name: " << name << endl;
    }
};


class Library : public Reader {
private:
    string bookName;
    string status; 

public:
    Library(string n, int i, string b, string s)
        : Reader(n, i), bookName(b), status(s) {}

    bool isFree() const {
        return status == "free";
    }

    void borrowBook() {
        if (status == "free") {
            status = "taken";
            cout << "Book '" << bookName << "' has been borrowed successfully." << endl;
        }
        else {
            cout << "Book '" << bookName << "' is already taken." << endl;
        }
    }

  
    void display() const override {
        Reader::display();
        cout << "Book: " << bookName << ", Status: " << status << endl;
    }
};

void libraryTask() {
    vector<Library> books;
    books.push_back(Library("Alice", 1, "C++ Programming", "taken"));
    books.push_back(Library("Bob", 2, "Data Structures", "free"));
    books.push_back(Library("Charlie", 3, "Algorithms", "free"));

    cout << "Books with status 'free':" << endl;
    for (auto& book : books) {
        if (book.isFree()) {
            book.display();
            book.borrowBook();
        }
    }

    cout << "\nUpdated book list:" << endl;
    for (const auto& book : books) {
        book.display();
    }
}


int main() {
    cout << "--- Group 4 Task ---" << endl;
    group4Task();

    cout << "\n--- Library Task ---" << endl;
    libraryTask();

    return 0;
}
