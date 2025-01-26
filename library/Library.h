#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <map>
#include "Book.h"  // Include Book.h
#include "User.h"  // Include User.h

class Library {
private:
    std::map<int, Book> books;
    std::map<int, User> users;

public:
    void addBook(const Book& book);
    void registerUser(const User& user);
    bool borrowBook(int bookID, int userID);
    bool returnBook(int bookID, int userID);
    void displayAllBooks() const;
};

#endif // LIBRARY_H
