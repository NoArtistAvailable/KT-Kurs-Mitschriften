#pragma once
#include <string>
#include <vector>
#include "shelf.h"
#include "media.h"
#include "user.h"

class Library {
	std::vector<Media> ownedMedia;
	std::vector<Shelf> shelves;

	std::vector<User> customers;

public:
	User* AddNewCustomer(std::string name, std::string adress, std::string contact);
	bool RemoveCustomer(User* customer);
	void AddCustomersFromDirectory(std::string path);

	Media* AddNewMedia(Media toAdd);
	bool RemoveMedia(Media* media);
	void AddMediaFromDirectory(std::string path);

	std::vector<Media*> QueryMedia(std::string query);
	bool RentMedia(Media* media, User* customer);
	bool ReturnMedia(Media* media);
	bool CheckRentalStatus(Media* media);

	bool CheckIfOverdue(Media* media);

};