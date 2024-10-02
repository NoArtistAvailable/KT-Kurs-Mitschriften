#include "LKW.h"

/// <summary>/// LKWwwww /// </summary>/// <param name="marke"></param>/// <param name="baujahr"></param>/// <param name="anzahlReifen"></param>/// <param name="ladeKapazitaet"></param>
LKW::LKW(const std::string& marke, int baujahr, int anzahlReifen, double ladeKapazitaet) :Fahrzeug(marke, baujahr, anzahlReifen), ladeKapazitaet(ladeKapazitaet) {}

/// <summary>
/// Anzeige, spezialisiert für LKW
/// </summary>
void LKW::anzeigen() const {
	Fahrzeug::anzeigen();
	std::cout << "Lade Kapazitaet: " << this->ladeKapazitaet << std::endl;
}

/// <summary>
/// Start Funktion des LKW
/// </summary>
void LKW::start() const {
	std::cout << "LKW startet!" << std::endl;
}

/// <summary>/// Destruktor von LKW /// </summary>
LKW::~LKW() {
	std::cout << "LKW aufgelöst" << std::endl;
}