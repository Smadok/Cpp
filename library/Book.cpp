#include "Book.h"

Book::Book() : bookID(0), title(""), author(""), genre(""), isAvailable(true) {}

Book::Book(int id, std::string t, std::string a, std::string g)
    : bookID(id), title(t), author(a), genre(g), isAvailable(true) {}

bool Book::borrowBook() {
    if (isAvailable) {
        isAvailable = false;
        return true;
    }
    return false;
}

void Book::returnBook() { isAvailable = true; }

void Book::displayDetails() const {
    std::cout << "ID: " << bookID << ", Title: " << title
        << ", Author: " << author << ", Genre: " << genre
        << ", Available: " << (isAvailable ? "Yes" : "No") << std::endl;
}

bool Book::getAvailability() const { return isAvailable; }

int Book::getBookID() const { return bookID; }
