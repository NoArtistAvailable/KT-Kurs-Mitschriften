#pragma once
#include "Fahrzeug.h"

/// <summary>
/// Vererbt durch Fahrzeug
/// </summary>
class Motorrad : public Fahrzeug {
private:
	bool hatBeiwagen;
public:
	Motorrad(const std::string& marke, int baujahr, int anzahlReifen, bool hatBeiwagen);

	void anzeigen() const override;
	void start() const override;
	~Motorrad() override;
};