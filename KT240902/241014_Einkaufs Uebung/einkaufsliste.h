#pragma once
#include "produkt.h"
#include <map>

template<typename T>
class Einkaufsliste {
	static_assert(std::is_base_of<Produkt, T>::value, "T must be derived from Produkt");
	std::map<T*, int> items;
public:
	void hinzufuegen(T* item, int anzahl = 1) {
		items[item] = items[item] + anzahl;
	}
	void entfernen(T* item) {
		items.erase(item);
	}
	void anzeigen() {
		for (const auto& pair : items) {
			std::cout 
				<< "Produkt: " << pair.first->getName() 
				<< ", Anzahl: " << pair.second 
				<< ", Preis: " << pair.second * pair.first->getPrice() << " €"
				<< std::endl;
		}
	}

	~Einkaufsliste() {
		for (auto& pair : items) {
			delete pair.first;
		}
	}
};