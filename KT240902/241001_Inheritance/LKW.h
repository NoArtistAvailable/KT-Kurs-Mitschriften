#pragma once
#include "Fahrzeug.h"

class LKW : protected Fahrzeug {	// Fahrzeug attribute haben maximal protected access
private:
	double ladeKapazitaet;
public:
	LKW(const std::string& marke, int baujahr, int anzahlReifen, double ladeKapazitaet);

	void anzeigen() const override;
	void start() const override;
	~LKW() override;
};