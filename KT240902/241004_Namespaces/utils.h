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
			std::cout << "Geb�ude hochgezogen" << std::endl;
		}
		~Building() {
			std::cout << "Geb�ude eingerissen" << std::endl;
		}
	};
}