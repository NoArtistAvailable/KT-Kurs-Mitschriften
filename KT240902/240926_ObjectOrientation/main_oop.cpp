#include<iostream>
#include "person.h"


int main() {
	
	Person person1("Max Mustermann", 33);
	Person person2("Susanne Liebergang", 18);

	person1.introduce();
	person2.introduce();

	person1.printMyAdress();
	std::cout << &person1 << std::endl;

	{
		Person* p = new Person("Steffie", 35);
	}
	std::cout << "nach dem scope" << std::endl;

	return 0;

	
}