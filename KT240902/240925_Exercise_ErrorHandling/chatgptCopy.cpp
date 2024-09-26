#include <iostream>
#include <stdexcept>
#include <limits>
#include <fstream>
#include <vector>

// Aufgabe 1: Division durch Null verhindern
double divideNumbers(double numerator, double denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Fehler: Division durch Null ist nicht erlaubt.");
    }
    return numerator / denominator;
}

void exerciseDivisionByZero() {
    try {
        double result = divideNumbers(10, 0);
        std::cout << "Ergebnis: " << result << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Aufgabe 2: Ung�ltige Eingabe abfangen
int getValidatedInput() {
    int number;
    std::cout << "Bitte eine Zahl eingeben: ";
    std::cin >> number;
    if (std::cin.fail()) {
        throw std::invalid_argument("Fehler: Ung�ltige Eingabe.");
    }
    return number;
}

void exerciseInvalidInput() {
    try {
        int number = getValidatedInput();
        std::cout << "Eingegebene Zahl: " << number << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Aufgabe 3: Datei �ffnen und Fehler behandeln
void openFileWithErrorCheck(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Fehler: Datei konnte nicht ge�ffnet werden.");
    }
    std::cout << "Datei erfolgreich ge�ffnet." << std::endl;
    file.close();
}

void exerciseFileHandling() {
    try {
        openFileWithErrorCheck("nicht_existierende_datei.txt");
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Aufgabe 4: Array-Index �berpr�fen
int getArrayElement(const std::vector<int>& vec, size_t index) {
    if (index >= vec.size()) {
        throw std::out_of_range("Fehler: Index au�erhalb der Grenzen.");
    }
    return vec[index];
}

void exerciseArrayBounds() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    try {
        int element = getArrayElement(vec, 10);
        std::cout << "Element: " << element << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Aufgabe 5: Speicherallokation �berpr�fen
void allocateLargeMemory(size_t size) {
    int* array = new(std::nothrow) int[size];
    if (!array) {
        throw std::runtime_error("Fehler: Speicherallokation fehlgeschlagen.");
    }
    std::cout << "Speicher erfolgreich allokiert." << std::endl;
    delete[] array;
}

void exerciseMemoryAllocation() {
    try {
        allocateLargeMemory(1000000000000); // Absichtlich gro�e Zahl f�r Fehler
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Aufgabe 6: Nullzeiger �berpr�fen
void checkPointerForNull(int* ptr) {
    if (ptr == nullptr) {
        throw std::runtime_error("Fehler: Nullzeiger dereferenziert.");
    }
    std::cout << "Zeigerwert: " << *ptr << std::endl;
}

void exerciseNullPointerCheck() {
    int* ptr = nullptr;
    try {
        checkPointerForNull(ptr);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Aufgabe 7: �berlauf bei Ganzzahlen verhindern
int safeAdd(int a, int b) {
    if (a > 0 && b > std::numeric_limits<int>::max() - a) {
        throw std::overflow_error("Fehler: Ganzzahlen�berlauf.");
    }
    if (a < 0 && b < std::numeric_limits<int>::min() - a) {
        throw std::underflow_error("Fehler: Ganzzahlenunterlauf.");
    }
    return a + b;
}

void exerciseIntegerOverflow() {
    try {
        int result = safeAdd(std::numeric_limits<int>::max(), 1);
        std::cout << "Ergebnis: " << result << std::endl;
    }
    catch (const std::overflow_error& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::underflow_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Aufgabe 8: Zeichenkettenl�nge �berpr�fen
void checkStringLengthLimit(const std::string& str, size_t maxLength) {
    if (str.length() > maxLength) {
        throw std::length_error("Fehler: Zeichenkette �berschreitet die maximale L�nge.");
    }
    std::cout << "Zeichenkette ist g�ltig." << std::endl;
}

void exerciseStringLengthCheck() {
    std::string str = "Dies ist eine sehr lange Zeichenkette.";
    try {
        checkStringLengthLimit(str, 10);
    }
    catch (const std::length_error& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Aufgabe 9: Ung�ltige Zeichen in einer Zeichenkette �berpr�fen
void validateStringCharacters(const std::string& str) {
    for (char c : str) {
        if (!isalnum(c) && c != ' ') {
            throw std::invalid_argument("Fehler: Ung�ltiges Zeichen in der Zeichenkette.");
        }
    }
    std::cout << "Zeichenkette ist g�ltig." << std::endl;
}

void exerciseInvalidCharactersCheck() {
    std::string str = "G�ltigeZeichen123";
    try {
        validateStringCharacters(str);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Aufgabe 10: Speicherzugriffsfehler verhindern
void exerciseMemoryAccessError() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    try {
        int element = getArrayElement(vec, 10);
        std::cout << "Element: " << element << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }
}

// Main menu function
int main_() {
    int choice;

    while (true) {
        std::cout << "\nW�hle eine Aufgabe aus (1-10) oder 0 zum Beenden: ";
        std::cin >> choice;

        if (choice == 0) {
            std::cout << "Programm beendet." << std::endl;
            break;
        }

        switch (choice) {
        case 1:
            exerciseDivisionByZero();
            break;
        case 2:
            exerciseInvalidInput();
            break;
        case 3:
            exerciseFileHandling();
            break;
        case 4:
            exerciseArrayBounds();
            break;
        case 5:
            exerciseMemoryAllocation();
            break;
        case 6:
            exerciseNullPointerCheck();
            break;
        case 7:
            exerciseIntegerOverflow();
            break;
        case 8:
            exerciseStringLengthCheck();
            break;
        case 9:
            exerciseInvalidCharactersCheck();
            break;
        case 10:
            exerciseMemoryAccessError();
            break;
        default:
            std::cout << "Ung�ltige Auswahl! Bitte w�hle eine Zahl zwischen 1 und 10 oder 0 zum Beenden." << std::endl;
            break;
        }
    }

    return 0;
}
