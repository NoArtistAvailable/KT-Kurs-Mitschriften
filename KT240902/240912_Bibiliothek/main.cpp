#include "library.h"
#include<iostream>
#include <string>

void stepConsole() {
    char c = ' ';
    std::cout << "\n\nweiter";
    std::cin >> c;
    system("cls");
}


int main()
{
    Book books[3];
    setBook(books[0], "Der Herr der Ringe", "J.R.R. Tolkien", 1);
    setBook(books[1], "Harry Potter", "J.K. Rowling", 2);
    setBook(books[2], "c++ - Das umfassende Handbuch", "T.T. Will", 3);

    User users[4];
    setUser(users[0], "Alice", 1);
    setUser(users[1], "Bob", 2);
    setUser(users[2], "Henry", 3);
    setUser(users[3], "Aaron", 4);

    showLibrary(books, 3, users, 4);
    stepConsole();
    rentBook(books[1]);
    showLibrary(books, 3, users, 4);

}

