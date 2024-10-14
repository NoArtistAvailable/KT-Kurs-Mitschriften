#include "einkaufsliste.h"
#include<iostream>
#include "pch.h"

template<typename T>
void Einkaufsliste<T>::hinzufuegen(T item, int anzahl) {
	items[item] = items[item] + anzahl;
}

template<typename T>
void Einkaufsliste<T>::entfernen(T item) {
	items.erase(item);
}

template<typename T>
void Einkaufsliste<T>::anzeigen() {
    for (const auto& pair : items) {
        std::cout << "Produkt: " << pair.first.getName() << ", Anzahl: " << pair.second << std::endl;
    }
}