#pragma once
#include <string>

struct User {
	std::string name;
	int id;
};

void setUser(User& user, const std::string name, const int id);
void showUser(const User& user);