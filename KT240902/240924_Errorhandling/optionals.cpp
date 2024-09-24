#include <iostream>
#include <optional>	// uses c++ > 2017

std::optional<int> divide_opt(int, int);

void main__() {
	auto result = divide_opt(2, 0);
	if (result) {
		std::cout << "Ergebnis: " << *result << std::endl;
	}
	else std::cerr << "Fehler!" << std::endl;
}

std::optional<int> divide_opt(int a, int b) {
	if (b == 0) return std::nullopt;
	return a / b;
}