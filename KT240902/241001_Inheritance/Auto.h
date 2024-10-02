#pragma once
#include "Fahrzeug.h"

/// <summary>
/// Die Klasse Auto ist eine Spezialisierung der Klasse Fahrzeug
/// </summary>
class Auto : public Fahrzeug {
private:
	int sitzPlaetze;
public:
	Auto(const std::string& marke, int baujahr, int anzahlReifen, int sitzPlaetze);

	// �berschreiben der virtuellen Methoden
	void anzeigen() const override;
	void start() const override;
	~Auto() override;
};