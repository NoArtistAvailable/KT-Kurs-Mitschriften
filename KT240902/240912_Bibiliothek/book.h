#pragma once

#include <string>

struct Book {
	std::string title;
	std::string author;
	int id;
	bool rented;
} typedef buch_t;	// typedef erstellt einen zusätzlichen Namen für den Type

// Funktionesdeklaration
void setBook(Book& book, const std::string& titel, const std::string& author, int id);
void showBook(const Book& book);
void rentBook(Book& book);
void returnBook(Book& book);