#pragma once
#include<string>
#include "media.h"

class User {
public:
	std::string name;
	std::string adress;
	std::string contact;

	std::string memberNumber;
	// beginne mit gro�en Initialen,
	// 4 Ziffern: zuf�llig
	// Pr�fziffer

	std::vector<Media*> rented;

	User(std::string name, std::string adress, std::string contact);
};