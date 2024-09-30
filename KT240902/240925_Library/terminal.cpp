#include <iostream>
#include <string>
//#include "library.h";
#include<vector>
using std::string;


class Choice {
public:
    string prompt;
private:
    // this would probably lead us down a functional path,
    // maybe we want to evaluate Single State Machine approach first
    void (*action)();

public:
    // Constructor
    Choice(const string& p, void (*a)()) : prompt(p), action(a) {}

    void invoke() {
        if (action) action();
    }
};

void printLine(const string& input) {
    std::cout << input << std::endl;
}

bool choice(const string& prompt, std::vector<Choice>& choices){
    printLine(prompt);
    int count = choices.size(); // casting long long to int
    //std::cout << choices.size() << std::endl;
    for (long long i = 0; i < count; i++)
        printLine("   " + std::to_string(i + 1) + ": " + choices.at(i).prompt);
    int chosen;
    std::cin >> chosen;
    chosen--;   // we want to show the user a choice between 1 and count, instead of between 0 and count - 1 
    if (chosen < 0 || chosen >= count) return false;
    choices.at(chosen).invoke();
    return true;
}

void sampleFunction() {
    printLine("this happened");
}

void sampleFunctionWithParameter(int param) {
    printLine(std::to_string(param));
}

int main()
{
    printLine("Welcome to C++ Library!");
    // load library
    //Library library = Library();
    //library.Init();

    auto secondChoice = []() {sampleFunctionWithParameter(2); };    // we're using a lambda to use parameterized functions
    // anatomy of a lambda: [] <- capture clause (what variables get captured from the enclosing scope)
    // anatomy of a lambda: () <- parameters to be used in the lambda function ( eg we could (int count = 2) {print(count);} )
    // anatomy of a lambda: {} <- function body
    std::vector<Choice> mainChoice = { 
        Choice("Medien Suche", sampleFunction), 
        Choice("Medien Bearbeiten", secondChoice),
        Choice("Nutzer Bearbeiten", sampleFunction)
    };
    while( choice("Select one: ", mainChoice));

}



/*Projekt Bibliothek
Projektbeschreibung:
Es soll eine Bibliothek simuliert werden mit einem Terminal/ Schalter, an
dem Aufgaben erledigt werden können wie z.B.
1. Medium/ Medien hinzufügen/ entfernen/ einsortieren
2. Suche nach Medien
3. Verleihstatus feststellen
4. Nutzer hinzufügen/ entfernen
Klassen sollen in *hpp und *cpp - Dateien modularisiert werden.
Für Strukturen ohne Methoden genügen *hpp - Dateien.
Vorstellbar ist hier die Bibliothek als Singleton (kann später als solche
implementiert werden) und ggf. Aggregation mit den Klassen (bzw.
Strukturen) Nutzer, Medien, Regale.
Das Terminal ist der Entry- Point des Programms, solange es keine GUI
gibt.
Medien sollten als Klasse dargestellt werden, um damit eine Vererbung
vorzunehmen. Somit kann ‚Medien‘ als abstrakte Klasse implementiert
werden, von der sich dann z.B. ‚Buch‘, , ‚CD‘ usw. ableiten
Medien- Attribute z.B.:
• Art (z.B. Buch, CD)
• Autor
• Titel (bei CDs zusätzlich noch Titelliste)
• Kategorie (z.B. Sachbuch, Punkrock)
• Code (z.B. ISBN oder EAN)
• letzter Nutzer
• Timestamp, wenn verliehen
Das Hinzufügen soll über eine CSV- Datei erfolgen und in einen
geeigneten C++ Container eingelesen werden. Aus diesem soll gesucht und
entfernt werden. Zu einem späteren Zeitpunkt soll eine Datenbank
einbezogen werden.
Überziehungen sollen anhand des Timestamps ermittelt werden (Alarm/
Reporting?).
Die Nutzer sollen neben den typischen Attributen
• Name
• Adresse
• Kontakt
auch eine Mitgliedsnummer bekommen, die aus den Initialen am Beginn
besteht gefolgt von 5- stelligen Ziffernfolge, deren letzte eine Prüfziffer ist,
die als Modulo 10 der Summe aller Ziffern berechnet wird.
Regale (als Vectoren/ Map ?) sollen mit Medien jeder Art befüllt werden
können. Das Einsortieren soll über eine Funktion erfolgen, die manuell
ausgeführt werden kann (um Neuzugänge einsortieren zu können), aber bei
Programmstart auch automatisch einmal aufgerufen wird. Regale sollen
eine bestimmte Größe (Kapazität) nicht überschreiten können.*/