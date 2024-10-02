#include <iostream>
#include <vector>
#include "Auto.h"
#include "LKW.h"
#include "Motorrad.h"



int main_()
{
    // vektor von Fahrzeugzeigern
    std::vector<Fahrzeug*> fahrzeuge;

    // Fahrzeuge erstellen
    fahrzeuge.push_back(new Auto("BMW", 2000, 4, 5));
    fahrzeuge.push_back(new Motorrad("Harley Davidson", 2003, 2, true));

    auto lkw = new LKW("Mercedes", 2010, 4, 30.0);
    // wenn mit new instaziert, dann auch delete - ansonsten gibt es memory leaks
    //fahrzeuge.push_back(lkw); // LKW hat nur protected zugriff auf Fahrzeug und ist daher nicht castbar

    for (const auto& f : fahrzeuge) {
        f->anzeigen();
        f->start();
    }
    lkw->anzeigen();
    lkw->start();

    for (auto& f : fahrzeuge) {
        delete f;
    }
    delete lkw;

    return 0;
}

