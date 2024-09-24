// #define NDEBUG <- disables all assertions

#include <iostream>
#include <cassert>	// sollte nur während debug / entwicklung verwendet werden

//using namespace std;

int divide_assert(int, int);

void main_() {
	int result = divide_assert(6, 2);
	std::cout << "Ergebnis: " << result << std::endl;

	result = divide_assert(10, 0);	// wird assertion triggern
	std::cout << "Ergebnis: " << result << std::endl;
}

int divide_assert(int a, int b) {
	assert(b != 0 && "Division durch 0!");
#if NDEBUG
	if (b == 0) throw ("Division by 0!");
#endif
	return a / b;
}