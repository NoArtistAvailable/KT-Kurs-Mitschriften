#pragma once
#include<string>
#include<vector>
#include<time.h>

class Media {
public:
	std::string title;
	std::string author;
	std::vector<std::string> tags;
	// todo: deconstructor needs to remove assigned vector

	Media(std::string title, std::string author) : title(title), author(author) {}

	int code;
	bool CheckRentalStatus();

	virtual std::string ToString() { return ""; }
	// pure virtual -> du kannst media nicht mehr instanzieren (ist abstrakt)

private:
	time_t timestamp;
	//User* lastRentedBy;	// <- diamanten problem
};

class Book : public Media{
public:
	std::string isbn;
	Book(std::string title, std::string author, std::string bookId) : Media(title, author), isbn(bookId){}
	std::string ToString() {
		return title + " | by " + author + " | " + isbn;
	}
};

class CD : public Media {
public:
	std::string ean;
	std::vector<std::string> titleList;
	CD(std::string title, std::string author, std::string ean) : Media(title, author), ean(ean) {}
	std::string ToString() {
		return title + " | by " + author;
	}
};