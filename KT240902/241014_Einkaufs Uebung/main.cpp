#include <iostream>
#include "pch.h"
#include "Windows.h"
#include "einkaufsliste.h"

const int DAY = 24 * 60 * 60;

int main(int argc, char** argv) {
	SetConsoleOutputCP(1252);
	setlocale(LC_ALL, "de_DE");

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	std::cout << "\n\n";

	auto liste = Einkaufsliste<Produkt>();
	
	liste.hinzufuegen(new LebensMittel("Packung Eier", 2.5, 200, 10 * DAY), 1);
	liste.hinzufuegen(new LebensMittel("Milch", 1.2, 1000, 60 * DAY), 2);

	liste.hinzufuegen(new Elektronik("Fernseher", 400, 356 * DAY));

	liste.anzeigen();

	return 0;
}