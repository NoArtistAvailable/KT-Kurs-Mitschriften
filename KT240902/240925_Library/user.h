#pragma once
#include<string>
#include "media.h"

class User {
public:
	std::string name;
	std::string adress;
	std::string contact;

	std::string memberNumber;

	std::vector<Media*> rented;

	User(std::string name, std::string adress, std::string contact);
};