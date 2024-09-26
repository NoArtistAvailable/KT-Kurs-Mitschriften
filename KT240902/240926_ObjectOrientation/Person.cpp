#include "Person.h"
#include<iostream>
using std::string;

Person::Person(const string &name, int age) : name(name), age(age) {}
Person::~Person() {
	std::cout << "person beendet" << std::endl;
}

string Person::getName() const { return name; }
int Person::getAge() const { return age; }

void Person::setName(const string& name) { this->name = name; }
void Person::setAge(int age) { this->age = age; }

void Person::introduce() const {
	std::cout << "Hallo, mein Name ist " << name << " und ich bin " << age << " Jahre alt." << std::endl;
};

void Person::printMyAdress() {
	std::cout << reinterpret_cast<void*>(this) << std::endl;
}