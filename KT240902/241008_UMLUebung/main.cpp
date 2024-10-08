#include <iostream>
#include "Windows.h"
#include "Schule.h"

int main()
{
    SetConsoleOutputCP(1252);
    setlocale(LC_ALL, "de_DE");

    auto schule = Schule("August Bebel Schule");

    schule.lehrer.push_back(new Lehrer("August Mann"));
    schule.lehrer[0]->addFach("Mathe");
    schule.lehrer[0]->addFach("Ethik");
    schule.lehrer.push_back(new Lehrer("Frederike Lishold"));
    schule.lehrer[1]->addFach("Deutsch");
    schule.lehrer[1]->addFach("Englisch");
    schule.lehrer[1]->addFach("Geschichte");
    schule.lehrer.push_back(new Lehrer("Franz Guenther"));
    schule.lehrer[2]->addFach("Sport");
    schule.lehrer[2]->addFach("Englisch");

    schule.schueler.push_back(new Schueler("Simon Fritz"));
    schule.schueler[0]->addNote(2);
    schule.schueler.push_back(new Schueler("Vera Fritz"));
    schule.schueler.push_back(new Schueler("Albert Fried"));
    schule.schueler.push_back(new Schueler("Lucy Lang"));
    schule.schueler.push_back(new Schueler("Franz Stein"));
    schule.schueler.push_back(new Schueler("Sarbina Meissen"));

    auto a3 = SchulKlasse("3A");
    a3.addKlassenLehrer(schule.lehrer[0]);
    for (int i = 0; i < 3; i++) {
        a3.addSchueler(schule.schueler[i]);
    }
    auto b3 = SchulKlasse("3B");
    b3.addKlassenLehrer(schule.lehrer[1]);
    for (int i = 3; i < 6; i++) {
        b3.addSchueler(schule.schueler[i]);
    }

    a3.Print(std::cout);
    std::cout << std::endl;
    b3.Print(std::cout);

}

