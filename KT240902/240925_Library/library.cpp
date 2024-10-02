#include "library.h"
#include "media.h"
#include<iostream>
#include <fstream>
#include<sstream>
using std::string;

void Library::Init() {
	AddBooksFromDirectory("books.txt");
	auto b = Book("r", "g", "b");
}

void Library::ShowEveryThing() {
	for (const auto& media : ownedMedia) {
		std::cout << media->ToString() << std::endl;
	}
}

void Library::AddBooksFromDirectory(const string& path) {
	auto newMedia = LoadBooksFromPath(path);
	ownedMedia.insert(ownedMedia.end(), newMedia.begin(), newMedia.end());
}

std::vector<Book*> Library::LoadBooksFromPath(const string& path){
	auto vec = std::vector<Book*>();
	std::ifstream fileStream;
	fileStream.open(path, std::ios::in);
	
	std::string line;

	while (std::getline(fileStream, line)) {
		std::stringstream ss(line);
		std::string title, author, category;

		if (!std::getline(ss, title, ';')) continue;
		if (!std::getline(ss, author, ';')) continue;
		if (!std::getline(ss, category, ';')) continue;

		Book* b = new Book(title, author, category);
		vec.push_back(b);
	}
	fileStream.close();
	return vec;
}