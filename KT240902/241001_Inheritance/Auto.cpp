#include "Auto.h"

/// <summary>/// Autooo /// </summary>/// <param name="marke"></param>/// <param name="baujahr"></param>/// <param name="anzahlReifen"></param>/// <param name="sitzPlaetze"></param>
Auto::Auto(const std::string& marke, int baujahr, int anzahlReifen, int sitzPlaetze):Fahrzeug(marke,baujahr,anzahlReifen), sitzPlaetze(sitzPlaetze) {}

/// <summary>
/// Anzeige, spezialisiert für Auto
/// </summary>
void Auto::anzeigen() const {
	Fahrzeug::anzeigen();
	std::cout << "Sitzplaetze: " << this->sitzPlaetze << std::endl;
}

/// <summary>
/// Start Funktion des Autos
/// </summary>
void Auto::start() const {
	std::cout << "Auto startet!" << std::endl;
}

/// <summary>/// Destruktor von Auto /// </summary>
Auto::~Auto() {
	std::cout << "Auto aufgelöst" << std::endl;
}