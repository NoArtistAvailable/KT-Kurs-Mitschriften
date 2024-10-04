// Jedes Projekt hat einen globalen Namespace ::n
// Unärer Bereichsauflösungsoperator ::
#include <iostream>
#include "utils.h"

int main() {
	::std::cout << "Eine Ausgabe" << std::endl;
	//util::zaehler++;
	std::cout << util::zaehler << std::endl;

	using namespace company;
	sales::someFunction();
	hr::someFunction();

	auto building = new company::Building;
	building->entrances = 6;

	delete(building);

	return 0;
}
