#include "Library.h"

void Library::addBook(const Book& book) {
    books[book.getBookID()] = book;
}

void Library::registerUser(const User& user) {
    users[user.getUserID()] = user;
}

bool Library::borrowBook(int bookID, int userID) {
    if (books.find(bookID) != books.end() && users.find(userID) != users.end()) {
        return users[userID].borrowBook(books[bookID]);
    }
    return false;
}

bool Library::returnBook(int bookID, int userID) {
    if (books.find(bookID) != books.end() && users.find(userID) != users.end()) {
        return users[userID].returnBook(books[bookID]);
    }
    return false;
}

void Library::displayAllBooks() const {
    std::cout << "Library Books:" << std::endl;
    for (const auto& pair : books) {
        pair.second.displayDetails();
    }
}
