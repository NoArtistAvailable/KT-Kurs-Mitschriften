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

	int code;
	bool CheckRentalStatus();

	virtual std::string ToString();

private:
	time_t timestamp;
	User* lastRentedBy;
};

class Book : Media{
public:
	std::string bookId;
	Book(std::string title, std::string author, std::string bookId);
	std::string ToString() {
		return title + " | by " + author + " | " + bookId;
	}
};

class CD : Media {
public:
	float playLength;
	CD(std::string title, std::string author, float playLength);
	std::string ToString() {
		return title + " | by " + author;
	}
};