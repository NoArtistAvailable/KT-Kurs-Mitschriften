#pragma once
#include<string>
#include<vector>
#include<iostream>

class Person {
protected:
	std::string name;
	int id;
	static int lastId;
public:
	Person(std::string name) : name(name) { id = lastId; lastId++; };
	std::string getName() { return name; };
	int getId() { return id; };
	void Print(std::ostream& stream) { stream << name << " (id " << id << ")"; };
};

class Schueler : Person {
	std::vector<int> notenListe;
public:
	Schueler(std::string name) : Person(name) {};
	std::vector<int> getNoten() { return notenListe; };
	void addNote(int note) { notenListe.push_back(note); };
	void Print(std::ostream& stream) { 
		Person::Print(stream); 
		stream << " Anzahl Noten: " << notenListe.size(); 
	};
};

class Lehrer : Person {
	std::vector<std::string> faecher;
public:
	Lehrer(std::string name) : Person(name) {};
	std::vector<std::string> getFaecher() { return faecher; };
	void addFach(std::string fach) { faecher.push_back(fach); };
	void Print(std::ostream& stream) {
		Person::Print(stream);
		stream << " Anzahl Faecher: " << faecher.size();
	};
};
