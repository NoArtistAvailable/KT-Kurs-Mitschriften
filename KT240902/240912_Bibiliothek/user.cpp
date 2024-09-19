#include "user.h"
#include <iostream>

void setUser(User& user, const std::string name, const int id) {
	user.name = name;
	user.id = id;
}
void showUser(const User& user) {
	std::cout << "nutzer: [" << user.id << "] " << user.name << std::endl;
}