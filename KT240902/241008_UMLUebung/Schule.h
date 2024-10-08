#pragma once
#include <string>
#include<vector>
#include "Person.h"

class Schule {
	std::string name;
	
public:
	Schule(const std::string name) : name(name) {};
	std::string getName() { return name; };

	//std::vector<SchulKlasse*> klassen;
	std::vector<Lehrer*> lehrer;
	std::vector<Schueler*> schueler;

	~Schule() {
		for (auto l : lehrer) delete l;
		for (auto s : schueler) delete s;
	}
};

class SchulKlasse {
	std::string name;
	Lehrer* klassenLehrer;
	std::vector<Schueler*> schueler;
public:
	SchulKlasse(const std::string name) : name(name) {};
	void addSchueler(Schueler* p_schueler) { schueler.push_back(p_schueler); };
	void addKlassenLehrer(Lehrer* lehrer) { klassenLehrer = lehrer; };
	void Print(std::ostream& stream) {
		stream << "Klasse: " << name << std::endl;
		stream << "Klassenlehrer: "; 
		klassenLehrer->Print(stream);
		stream << std::endl << "Schüler: ";
		for (int i = 0; i < schueler.size(); i++) {
			stream << std::endl;
			schueler[i]->Print(stream);
		}
		stream << std::endl;
	}
};