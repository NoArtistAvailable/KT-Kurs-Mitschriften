#include<iostream>
#include <fstream>	// file stream
#include <string>
#include <array>

int exercise1(), exercise2(), exercise3(), exercise4(), exercise5(), exercise6(), exercise7(), exercise8(), exercise9(), exercise10();

int main() {

	int choice = 0;
	while (choice != -1) {
		std::cout << "Excercise: ";
		std::cin >> choice;

		switch (choice) {
		case 1: exercise1(); break;
		case 2: exercise2(); break;
		case 3: exercise3(); break;
		case 4: exercise4(); break;
		case 5: exercise5(); break;
		case 6: exercise6(); break;
		case 7: exercise7(); break;
		case 8: exercise8(); break;
		case 9: exercise9(); break;
		case 10: exercise10(); break;
		}
		choice = 0;
	}

	return 0;
}

/*

Aufgabe 1: Division durch Null verhindern
Problem: Verhindere eine Division durch Null und gib eine Fehlermeldung aus, wenn der Divisor Null ist.

*/

double divide(double a, double b) {
	if (b == 0) throw std::logic_error("Division by 0");
	return a / b;
}

int exercise1() {

	double num = 10;
	double div = 0;

	try {
		divide(num, div);
	}
	catch (const std::exception& e) {
		std::cout << "caught error! " << e.what() << std::endl;
	}

	return 0;
}


/*

Aufgabe 2: Ungültige Eingabe abfangen
Problem: Fange ungültige Eingaben ab, wenn der Benutzer eine Zahl eingeben soll.
Hinweis: std::cin.fail()
*/

int exercise2() {
	double num;
	std::cout << "Put in a number: ";
	std::cin >> num;
	if (std::cin.fail()) {
		std::cerr << "not a valid number!" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		num = 0;
	}
	else std::cout << "your number was " << num << std::endl;
	return 0;
}

/*

Aufgabe 3: Datei öffnen und Fehler behandeln
Problem: Öffne eine Datei und behandle den Fehler, wenn die Datei nicht existiert.

*/

int exercise3() {
	try {
		std::ifstream stream("data.txt");
		if (!stream.good()) {
			throw std::exception("bad file input");
		}

		stream.open("data.txt", std::ios::in);
		char buffer[20];
		stream.read(buffer, 20);
		std::cout << buffer << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "error: " << e.what() << std::endl;
	}
	return 0;
}

/*

Aufgabe 4: Array-Index überprüfen
Problem: Überprüfe, ob ein Array-Index innerhalb der gültigen Grenzen liegt.

*/

int exercise4() {
	int array[20];
	int index;
	std::cout << "suche index: ";
	std::cin >> index;

	if (index >= std::size(array) || index < 0) {
		std::cerr << index << "not inside range of array" << std::endl;
		return -1;
	}

	std::cout << "Index " << index << "was inside of array";

	return 0;
}


/*

Aufgabe 5: Speicherallokation überprüfen
Problem: Überprüfe, ob die Speicherallokation erfolgreich war.
Hinweis: new(std::nothrow)
*/

void allocate(int size) {
	int* ptr = new(std::nothrow) int[size];
	if (!ptr) {
		throw std::runtime_error("Error on allocation!");
	}
}

int exercise5() {
	try {
		allocate(20000000000);
	}
	catch (const std::exception& e) {
		std::cout << "caught exception: " << e.what() << std::endl;
	}
	return 0;
}


/*

Aufgabe 6: Nullzeiger überprüfen
Problem: Überprüfe, ob ein Zeiger null ist, bevor er dereferenziert wird.

*/

int exercise6() {
	char* ptr = nullptr;

	if (ptr == nullptr) {
		std::cerr << "pointer is null" << std::endl;
		return -1;	//mein error code
	}
	std::cout << "pointer is" << *ptr << std::endl;

	return 0;
}

/*

Aufgabe 7: Überlauf bei Ganzzahlen verhindern
Problem: Verhindere einen Überlauf bei Ganzzahlen und gib eine Fehlermeldung aus, wenn ein Überlauf auftritt.
Hinweis: std::numeric_limits<int>::max()

*/

int bump(int number) {
	if (number == std::numeric_limits<int>::max()) {
		throw std::overflow_error("Number is getting to large for int, use long long");
	}
	return number+1;
}

int exercise7() {

	int biggestNumber = std::numeric_limits<int>::max() - 1;
	try {
		biggestNumber = bump(biggestNumber);
		std::cout << biggestNumber << " | ";
		biggestNumber = bump(biggestNumber);
		std::cout << biggestNumber << " | ";
		biggestNumber = bump(biggestNumber);
	}
	catch (const std::exception& e) {
		std::cerr << "caught: " << e.what() << std::endl;
	}
	
	std::cout << "Even bigger than the biggest: " << biggestNumber << std::endl;

	return 0;
}


/*

Aufgabe 8: Zeichenkettenlänge überprüfen
Problem: Überprüfe, ob eine Zeichenkette eine bestimmte Länge überschreitet und gib eine Fehlermeldung aus.

*/

void checkLength(std::string text, int maxLength) {
	if (size(text) > maxLength) throw std::exception("string was too long");
}

int exercise8() {
	std::string text = "some character name that is too long";
	try {
		checkLength(text, 3);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

/*

Aufgabe 9: Ungültige Zeichen in einer Zeichenkette überprüfen
Problem: Überprüfe, ob eine Zeichenkette ungültige Zeichen enthält und gib eine Fehlermeldung aus.

*/

void checkString(std::string& text) {
	for (unsigned char c : text) {
		if (c <= 0x80 && !isalnum(c) && !isspace(c) && !ispunct(c)) {
			throw std::invalid_argument("\ninvalid character");
		}
		else if (c > 0x80) {
			throw std::invalid_argument("\ncharacter outside of ASCII range");
		}
		else std::cout << c;
	}
}

int exercise9() {

	std::string inputText;
	std::cout << "check text: \n";

	try {

		// Clear the newline character left in the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::getline(std::cin, inputText);

		checkString(inputText);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	return 0;
}

/*

Aufgabe 10: Speicherzugriffsfehler verhindern
Problem: Verhindere Speicherzugriffsfehler, indem du sicherstellst,
dass ein Array-Index innerhalb der gültigen Grenzen liegt.

*/

int safeGet(std::array<int, 32> arr, int index) {
	int maxIndex = arr.size();
	if (index < 0 || index >= maxIndex) {
		throw std::out_of_range("Index was out of range of array");
	}
	else return arr.at(index);
}

std::array<int, 32> arr = { 15,6,67,3,4 };
int exercise10() {
	
	int num;
	try {
		num = safeGet(arr, 2);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << num << std::endl;

	return 0;
}


