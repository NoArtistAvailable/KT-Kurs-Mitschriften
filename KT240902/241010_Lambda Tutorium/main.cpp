#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// Lamda Aufbau:
// [capture](parameter) -> return_type { body }
// capture wird als konstant erfasst, parameter können verändert werden

// capture: welche Variablen aus der lokalen Umgebung soll die Lambda Funktion verwenden
// [ ]: Keine Variablen erfasst
// [=]: Alle Variablen als Wert erfassen
// [&]: Alle Variablen als Referenz erfassen
// [x]: Nur die Variable x als Wert erfassen
// [&x]: Nur die Variable x als Referenz erfassen
// [x, y]: Nur die Variablen x und y als Wert erfasst
// Variablen werden zum Zeitpunkt der definition erfasst

int main()
{
    auto sageHallo = []() {std::cout << "Hallo" << std::endl; };

    sageHallo();

    //std::string line = "wird sofort ausgegeben";
    //[](std::string& line) -> std::string {
    //    std::cout << line << std::endl;
    //    }(&line);

    int x = 10, y = 20;

    auto printSum = [x, y]() {std::cout << "Summe: " << x + y << std::endl; };
    auto increase = [&x]() { x++; };

    increase();
    std::cout << "x: " << x << std::endl;
    printSum();
    
    std::vector<int> nummern = { 1,2,3,4,5 };

    for_each(nummern.begin(), nummern.end(), [](int x) {
        std::cout << x << " ";
        });


    return 0;
}

