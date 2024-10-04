#pragma once
#include<iostream>
// Lokaler Namensraum util
namespace util {
	extern int zaehler;

	void sucheAnfang();
	void sucheEnde();
}

namespace myUtil {
	void sucheAnfang();
}

namespace company {
	namespace hr {
		void someFunction();
	}
	namespace sales {
		void someFunction();
	}

	class Building {
	public:
		int entrances;
		Building() {
			entrances = 3;
			std::cout << "Gebäude hochgezogen" << std::endl;
		}
		~Building() {
			std::cout << "Gebäude eingerissen" << std::endl;
		}
	};
}