#include <iostream>
#include <string>

using namespace std;


// AUFGABE 1
void Aufgabe1() {
    int age = 10;
    float height = 100.57;
    char initial = 'd';
    string name = "hannes";
    bool isStudent = false;

    cout 
        << "Alter: " << age 
        << "\nGroesse: " << height 
        << "\nInitiale: " << initial 
        << "\nName: " << name 
        << "\nSchueler: " << (isStudent ? "Schueler" : "Kein Schueler")
        << endl;
}

void Aufgabe2() {
    int summand1, summand2;
    cout << "Summe von: ";
    cin >> summand1 >> summand2;
    cout << "= " << summand1 + summand2;
}

void Aufgabe4() {
    int dezimal = 10;
    int hexadezimal = 0x10AB;
    float gleitkomma = 2.01;
    char zeichen = 'a';
    string string = "Welt";
    cout 
        << "Dezimal Zahlen sind zahlen zur Basis 10: " << dezimal
        << "\nHexadezimal Zahlen sind Zahlen zur Basis 16: " << hexadezimal
        << "\nGleitkomma Zahlen sind gebrochene Zahlen und sind Kombinationen aus einer Mantisse und einem Exponenten: " << gleitkomma
        << "\nZeichen sind einzelne Zeichen mit einer Entsprechung in der ASCII Tabelle: " << zeichen
        << "\nStrings sind Zeichenverkettungen von mehreren Zeichen: " << string
        << endl;
}

void Aufgabe3() {
    const double PI = 3.14159;
    double radius;
    cout << "Berechnung der Fläche eines Kreises\nRadius: ";
    cin >> radius;
    cout << "\n=" << radius * radius * PI;
}

void Aufgabe5() {
    // get user decision on what they want to do:
    int option = 1;
    while (option == 1 || option == 2 || option == 3) {
        cout << "\n#################################\nMoechtest du"
            << "\n1 Grad Celsius in Fahrenheit und Celsius berechnen?"
            << "\n2 Eine Laenge in Metern angeben und diese in Zenti - , Mili - und Kilometern anzeigen lassen?"
            << "\n3 Kilogramm in Gramm und Tonnen umrechnen lassen?"
            << "\n4 Programm Beenden"
            << endl;
        cin >> option;

        // Temperature Conversion
        if (option == 1) {
            const double CELSIUS_TO_FAHRENHEIT_FACTOR = 1.8;
            const double CELSIUS_TO_FAHRENHEIT_OFFSET = 32;
            const double CELSIUS_TO_KELVIN_OFFSET = 273.15;

            double inputTemperature;
            cout << "Grad Celsius:";
            cin >> inputTemperature;
            cout << "\nFahrenheit: "
                << inputTemperature * CELSIUS_TO_FAHRENHEIT_FACTOR + CELSIUS_TO_FAHRENHEIT_OFFSET
                << "\nKelvin: "
                << inputTemperature + CELSIUS_TO_KELVIN_OFFSET
                << endl;
        }
        else if (option == 2) {
            double inputDistance;
            cout << "Laenge in Metern:";
            cin >> inputDistance;
            inputDistance = abs(inputDistance);
            cout << "\nCentimeter: " << round(inputDistance * 100)
                << "\nMilimeter: " << round(inputDistance * 1'000)
                << "\nKilometer: " << round(inputDistance / 1000)
                << endl;
        }
        else if (option == 3) {
            double weightInput;
            cout << "Gewicht in Kilogramm:";
            cin >> weightInput;
            weightInput = abs(weightInput);
            cout << "\nIn Gram: " << round(weightInput * 1000)
                << "\nIn Tonnen: " << round(weightInput / 1000)
                << endl;
        }
    }
}

void Aufgabe6() {
    const int INITIAL_BALANCE = 1000'00; //waehrung in euro cents
    int balance = INITIAL_BALANCE;
    int option = 1;
    while (option == 1 || option == 2 || option == 3) {
        cout << "\n#################################\nMoechtest du"
            << "\n1 Einzahlen"
            << "\n2 Abheben"
            << "\n3 Kontostand anzeigen"
            << "\n4 Programm Beenden"
            << endl;
        cin >> option;

        if (option == 1) {
            float inputValue;
            cout << "\nBetrag Einzahlen: (in EUR)";
            cin >> inputValue;
            balance += (int)floor(inputValue * 100);
            cout << "\nBetrag erfolgreich eingezahlt, neuer Kontostand: " << (float)balance / 100
                << "\n\n" << endl;
        }
        else if (option == 2) {
            float inputValue;
            cout << "\nBetrag Abheben: (in EUR)";
            cin >> inputValue;
            if (balance - (int)floor(inputValue * 100) > 0) { // check if user is trying to cheat the bank
                balance -= floor(inputValue * 100);
                cout << "\nBetrag erfolgreich abgehoben, neuer Kontostand: " << (float)balance / 100
                    << "\n\n" << endl;
            }
            else {
                cout << "\nNicht ausreichend Geld auf dem Konto. Kontostand: " << (float)balance / 100
                    << "\n\n" << endl;
            }
        }
        else if (option == 3) {
            cout << "\nKontostand: " << (float)balance / 100
                << "\n\n" << endl;
        }
    }
}

int main()
{
    // Aufgabe1();
    // Aufgabe2();
    // Aufgabe4();
    // Aufgabe3();
     //Aufgabe5();
    Aufgabe6();
}

