#pragma once
#include<string>
#include<vector>
#include<time.h>
#include "user.h"

class Media {
public:
	std::string title;
	std::string author;
	std::vector<std::string> tags;
	// todo: deconstructor needs to remove assigned vector

	int code;
	bool CheckRentalStatus();

	virtual std::string ToString() = 0;
	// pure virtual -> du kannst media nicht mehr instanzieren (ist abstrakt)

private:
	time_t timestamp;
	User* lastRentedBy;
};

class Book : Media{
public:
	std::string isbn;
	Book(std::string title, std::string author, std::string bookId);
	std::string ToString() {
		return title + " | by " + author + " | " + isbn;
	}
};

class CD : Media {
public:
	std::string ean;
	std::vector<std::string> titleList;
	CD(std::string title, std::string author, float playLength);
	std::string ToString() {
		return title + " | by " + author;
	}
};