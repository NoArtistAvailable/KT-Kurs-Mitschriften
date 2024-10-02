#pragma once
#include<string>
#include<vector>
#include "media.h"

class User {
public:
	std::string name;
	std::string adress;
	std::string contact;

	std::string memberNumber;
	// beginne mit großen Initialen,
	// 4 Ziffern: zufällig
	// Prüfziffer

	//std::vector<Media*> rented;	<- das user <-> media verhältnis sollte wahrscheinlich nur in library leben

	User(std::string name, std::string adress, std::string contact);
};