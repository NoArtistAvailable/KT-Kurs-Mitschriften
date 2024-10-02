#include "Motorrad.h"

/// <summary>
/// Konstruktor für Motorrad
/// </summary>
/// <param name="marke"></param>
/// <param name="baujahr"></param>
/// <param name="anzahlReifen"></param>
/// <param name="hatBeiwagen"></param>
Motorrad::Motorrad(const std::string& marke, int baujahr, int anzahlReifen, bool hatBeiwagen) : Fahrzeug(marke, baujahr, anzahlReifen), hatBeiwagen(hatBeiwagen){}

void Motorrad::anzeigen() const {
	Fahrzeug::anzeigen();
	std::cout << (hatBeiwagen ? "mit Beiwagen" : "ohne Beiwagen") << std::endl;
}

void Motorrad::start() const {
	std::cout << "Motorrad startet!" << std::endl;
}

Motorrad::~Motorrad() {
	std::cout << "Motorrad hat die Strasse verlassen" << std::endl;
}