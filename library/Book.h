#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>

class Book {
private:
    int bookID;
    std::string title;
    std::string author;
    std::string genre;
    bool isAvailable;

public:
    // Default constructor
    Book();
    // Parameterized constructor
    Book(int id, std::string t, std::string a, std::string g);

    bool borrowBook();
    void returnBook();
    void displayDetails() const;

    bool getAvailability() const;
    int getBookID() const; // Changed return type to int
};

#endif // BOOK_H
