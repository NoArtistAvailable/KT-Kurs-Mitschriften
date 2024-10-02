#pragma once
#include <iostream>
#include<string>

class Fahrzeug {
protected:
	std::string marke;
	int baujahr;
	int anzahlReifen;
public:
	Fahrzeug(const std::string& marke, int baujahr, int anzahlReifen);

	virtual void anzeigen() const;

	// pure virtual
	virtual void start() const = 0;

	// virtual destructor
	virtual ~Fahrzeug();
};