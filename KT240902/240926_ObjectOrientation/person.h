#pragma once
#include <string>

class Person {
private:
	std::string name;
	int age;
public:
	Person(const std::string& name, int age);
	~Person();

	std::string getName() const;	// const doesn't mark the return value, but shows that the function can not modify attributes
	int getAge() const;

	void setName(const std::string& value);
	void setAge(int age);

	void introduce() const;
	void printMyAdress();
};