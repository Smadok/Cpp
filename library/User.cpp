#include "User.h"


User::User() : userID(0), name("") {}

User::User(int id, std::string n) : userID(id), name(n) {}

bool User::borrowBook(Book& book) {
    if (book.borrowBook()) {
        borrowedBooks.push_back(&book);
        return true;
    }
    return false;
}

bool User::returnBook(Book& book) {
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); ++it) {
        if ((*it)->getBookID() == book.getBookID()) {
            book.returnBook();
            borrowedBooks.erase(it);
            return true;
        }
    }
    return false;
}

void User::displayBorrowedBooks() const {
    std::cout << name << "'s Borrowed Books:" << std::endl;
    for (const auto& book : borrowedBooks) {
        book->displayDetails();
    }
}

int User::getUserID() const { return userID; }
