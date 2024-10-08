#pragma once
#include <string>
#include <vector>
#include "shelf.h"
#include "media.h"
#include "user.h"

class Library {
	std::vector<Media*> ownedMedia;
	std::vector<Shelf*> shelves;
	std::vector<User*> customers;

public:
	void Init();
	void ShowEveryThing();
	Media* AddNewMedia(Media toAdd);
	bool RemoveMedia(Media* media);
	void AddBooksFromDirectory(const std::string& path);	
	std::vector<Book*> LoadBooksFromPath(const std::string& path);

	User* AddNewCustomer(const std::string& name, const std::string& adress, const std::string& contact);
	bool RemoveCustomer(User* customer);
	void AddCustomersFromDirectory(const std::string& path);

	std::vector<Media*> QueryMedia(const std::string& query);
	bool RentMedia(Media* media, User* customer);
	bool ReturnMedia(Media* media);
	bool CheckRentalStatus(Media* media);

	bool CheckIfOverdue(Media* media);

	~Library() {
		for (auto m : ownedMedia) delete m;
		for (auto s : shelves) delete s;
		for (auto c : customers) delete c;
	}
};