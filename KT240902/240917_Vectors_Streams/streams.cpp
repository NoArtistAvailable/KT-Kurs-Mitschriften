#include <iostream>	// input/output Stream (cint, cout)
#include <string>
#include <iomanip>	// input/output manipulator

void using_inputoutput_streams();
void using_iomanip();
void read_only_int();


void main() {
	//using_iomanip();
	//read_only_int();
	int arr[4][3];
	std::cout << std::size(arr) << std::endl;
}

void using_inputoutput_streams() {
	int i = 45324;
	double dVal = 4.0 * 12.0;

	std::string name = "Aaron";
	auto sWert{ "Das ist ein Text" };

	// std::cout << std::string("##### INFO #####\ni=") + std::to_string(i) + "\ndValue=" + std::to_string(dVal) + "\n##### END #####" << std::endl;
	// std::cerr << "some error" << std::endl;

	
	// std::cin.tie(&std::cout);	// Verkopplung von cin und cout
	// std::cin.tie(nullptr);		// Bindung aufgehoben
	std::cout << "Name eingeben: ";
	std::cin >> name;
	std::cout << "\nHallo " << name << "!" << std::endl;
}
void using_iomanip() {
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			std::cout << std::right << std::setw(4) << i * j;
		}
		std::cout << std::endl;
	}
}

/// <summary>
/// soll nur integer werte akzeptieren
/// </summary>
void read_only_int() {
	int num = 0;

	
	while (true) {
		std::cout << "Gib eine Ganzzahl zwischen 13 und 100 ein: ";
		std::cin >> num;

		if (num < 13 || num > 100 || std::cin.fail()) {		// cin.fail fängt alle nicht integer werte ab und scheint num zu clearen
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Keine gueltiger Eingabe." << std::endl;
		}
		else break;
	}
	std::cout << "deine zahl ist: " << num << std::endl;

}