#include <iostream>
#include <variant>	// uses c++ > 2017
#include <string>

std::variant<int, std::string> divide_var(int, int);

int main___() {
	auto result = divide_var(10, 2);
	result = divide_var(10, 0);
	if (std::holds_alternative<std::string>(result)) {
		std::cout << "ergebnis (string): " << std::get<std::string>(result) << std::endl;
	}
	if (std::holds_alternative<int>(result)) {
		std::cout << "ergebnis (int): " << std::get<int>(result) << std::endl;
	}
	return 0;
}

std::variant<int, std::string> divide_var(int a, int b) {
	if (b == 0) return "Division durch 0!";
	else return a / b;
}