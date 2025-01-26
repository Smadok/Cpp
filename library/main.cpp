#include "Library.h" 

int main() {
    Library myLibrary;

    myLibrary.addBook(Book(1, "1984", "George Orwell", "Dystopian"));
    myLibrary.addBook(Book(2, "To Kill a Mockingbird", "Harper Lee", "Classic"));

    User user1(100, "Alice");
    User user2(101, "Bob");
    myLibrary.registerUser(user1);
    myLibrary.registerUser(user2);

    if (myLibrary.borrowBook(1, 100)) {
        std::cout << "Alice borrowed '1984'." << std::endl;
    }
    if (myLibrary.returnBook(1, 100)) {
        std::cout << "Alice returned '1984'." << std::endl;
    }

    myLibrary.displayAllBooks();

    return 0;
}
