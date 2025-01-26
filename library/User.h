#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include "Book.h" // Include Book.h to access Book class

class User {
private:
    int userID;
    std::string name;
    std::vector<Book*> borrowedBooks;

public:
    // Default constructor
    User();
    // Parameterized constructor
    User(int id, std::string n);

    bool borrowBook(Book& book);
    bool returnBook(Book& book);
    void displayBorrowedBooks() const;

    int getUserID() const; // Changed return type to int
};

#endif // USER_H
