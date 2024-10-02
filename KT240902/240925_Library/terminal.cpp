#include <iostream>
#include <string>
#include "library.h";
#include<vector>
#include<stack>
#include<Windows.h>
#include <cstdlib> // required for system and clear
using std::string;

enum TerminalState {
    MAIN = 0, 
    SEARCH = 1,

    MEDIA_CHOICE = 2, 
    MEDIA_ADD = 3, 
    MEDIA_REMOVE = 4, 

    USER_CHOICE = 5, 
    USER_ADD = 6, 
    USER_REMOVE = 7
};

std::stack<TerminalState> stateMachine;
Library lib;

class Choice {
public:
    string prompt;
private:
    void (*action)();

public:
    Choice(const string& p, void (*a)()) : prompt(p), action(a) {}
    void invoke() {
        if (action) action();
    }
};

void printLine(const string& input) {
    std::cout << input << std::endl;
}

void waitForUserInput() {
    char unread;
    std::cin >> unread;
}

void notImplementedLine() {
    std::cout << "nicht implementiert" << std::endl;
    waitForUserInput();
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

void showStateMenu(TerminalState state) {
    switch (state) {
    case MAIN:
    {
        std::vector<Choice> currentChoice = {
            Choice("Medien Suche", []() { stateMachine.push(SEARCH); }),
            Choice("Alle Medien Anzeigen", []() {
                    lib.ShowEveryThing();
                    waitForUserInput();
                }),
            Choice("Medien Bearbeiten", []() { stateMachine.push(MEDIA_CHOICE); }),
            Choice("Nutzer Bearbeiten", []() { stateMachine.push(USER_CHOICE); }),
            Choice("Beenden", []() { stateMachine.pop(); })
        };
        if (!choice("Haupt Menü", currentChoice)) stateMachine.pop();
        break;
    }
    case SEARCH:
    {
        std::vector<Choice> currentChoice = {
            Choice("Such Eingabe nicht implementiert", notImplementedLine),
            Choice("Zurück", []() {stateMachine.pop(); })
        };
        if (!choice("Medien Suche", currentChoice)) stateMachine.pop();
        break;
    }
    case MEDIA_CHOICE:
    {
        std::vector<Choice> currentChoice = {
            Choice("Medien Hinzufügen", []() {stateMachine.push(MEDIA_ADD); }),
            Choice("Medien Entfernen", []() {stateMachine.push(MEDIA_REMOVE); }),
            Choice("Zurück", []() {stateMachine.pop(); })
        };
        if (!choice("Medien Menü", currentChoice)) stateMachine.pop();
        break;
    }
    case MEDIA_ADD:
    {
        std::vector<Choice> currentChoice = {
            Choice("Buch Hinzufügen nicht implementiert", notImplementedLine),
            Choice("CD Hinzufügen nicht implementiert", notImplementedLine),
            Choice("Zurück", []() {stateMachine.pop(); })
        };
        if (!choice("Medien Hinzufügen", currentChoice)) stateMachine.pop();
        break;
    }
    case MEDIA_REMOVE:
    {
        std::vector<Choice> currentChoice = {
            Choice("Medium Entfernen nicht implementiert", notImplementedLine),
            Choice("Zurück", []() {stateMachine.pop(); })
        };
        if (!choice("Medien Entfernen", currentChoice)) stateMachine.pop();
        break;
    }
    case USER_CHOICE:
    {
        std::vector<Choice> currentChoice = {
            Choice("Nutzer Hinzufügen", notImplementedLine),
            Choice("Nutzer Entfernen", notImplementedLine),
            Choice("Zurück", []() {stateMachine.pop(); })
        };
        if (!choice("Nutzer Menü", currentChoice)) stateMachine.pop();
        break;
    }
    case USER_ADD:
    {
        std::vector<Choice> currentChoice = {
            Choice("Nutzer Hinzufügen nicht implementiert", notImplementedLine),
            Choice("Zurück", []() {stateMachine.pop(); })
        };
        if (!choice("Nutzer Hinzufügen", currentChoice)) stateMachine.pop();
        break;
    }
    case USER_REMOVE:
    {
        std::vector<Choice> currentChoice = {
            Choice("Nutzer Entfernen nicht implementiert", notImplementedLine),
            Choice("Zurück", []() {stateMachine.pop(); })
        };
        if (!choice("Nutzer Entfernen", currentChoice)) stateMachine.pop();
        break;
    }
    }   // END OF SWITCH
}

int main()
{
    SetConsoleOutputCP(1252);
    setlocale(LC_ALL, "de_DE");
    printLine("Welcome to C++ Library!");
    // load library
    lib = Library();
    lib.Init();
    stateMachine.push(MAIN);    // initial state
    while (!stateMachine.empty()) {
        system("cls");  // clearing console
        TerminalState current = stateMachine.top();
        showStateMenu(current);
    }
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