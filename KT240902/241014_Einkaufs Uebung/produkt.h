#pragma once
#include<string>
#include <chrono>

class Produkt {
protected:
	std::string name;
	float preis;
public:	
	Produkt(std::string name, float preis) : name(name), preis(preis) {}
	virtual void anzeigen() = 0;
	virtual ~Produkt() {}
	virtual std::string getName() { return name; }
	virtual float getPrice() { return preis; }
};

class LebensMittel : public Produkt {
	time_t haltbarkeitsDatum;
	float gewicht;
public:
	LebensMittel(std::string name, float preis, float gewicht, time_t haltbarkeitsDatum) : Produkt(name, preis), gewicht(gewicht), haltbarkeitsDatum(haltbarkeitsDatum) {}
	void anzeigen() override {
		std::cout << name << " "
			<< preis << " €"
			<< gewicht << " g"
			<< haltbarkeitsDatum
			<< std::endl;
	}
};

class Elektronik : public Produkt {
	time_t garantie;
public:
	Elektronik(std::string name, float preis, time_t garantie) : Produkt(name, preis), garantie(garantie) {}
	void anzeigen() override {
		std::cout << name << " "
			<< preis << " €"
			<< garantie
			<< std::endl;
	}
};