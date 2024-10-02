#include "Fahrzeug.h"

/// <summary>/// Konstruktor des Fahrzeugs /// </summary>/// <param name="marke"></param>/// <param name="baujahr"></param>/// <param name="anzahlReifen"></param>
Fahrzeug::Fahrzeug(const std::string& marke, int baujahr, int anzahlReifen) : marke(marke), baujahr(baujahr), anzahlReifen(anzahlReifen){}

/// <summary>
/// Virtuelle Methode zum Anzeigen verschiedener Fahrzeug-Komponenten
/// </summary>
void Fahrzeug::anzeigen() const {
	std::cout << "Fahrzeug mit der Marke: " << this->marke 
		<< ", Baujahr: " << this->baujahr 
		<< ", Anzahl der Reifen: " << this->anzahlReifen 
		<< std::endl;
}

/// <summary>/// virtueller Destruktor /// </summary>
Fahrzeug::~Fahrzeug() {}