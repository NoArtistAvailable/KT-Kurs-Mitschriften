#include "book.h"
#include <iostream>

void setBook(Book& book, const std::string& title, const std::string& author, int id) {
	book.author = author;
	book.title = title;
	book.id = id;
	book.rented = false;
}

void showBook(const Book& book) {
	std::cout << "Book [" << book.id << "] " << book.title << "\nby " << book.author << (book.rented ? "\nist verliehen" : "\nist verfuegbar") << std::endl;
}

void rentBook(Book& book) {
	if (!book.rented) {
		book.rented = true;
		std::cout << "Das Buch " << book.title << " erfolgreich verliehen.";
	}
	else std::cout << "Buch schon verliehen!" << std::endl;
}
void returnBook(Book& book) {
	if (book.rented) {
		book.rented = false;
		std::cout << "Das Buch " << book.title << " wurde zurück gegeben.";
	}
	else std::cout << "Buch noch vorhanden, wird 2 mal zurückgegeben?!" << std::endl;
}