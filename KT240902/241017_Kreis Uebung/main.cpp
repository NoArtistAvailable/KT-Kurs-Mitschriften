#include <iostream>
#include "Kreis.h"

int main()
{
    auto kreis = Kreis();

    auto punktInnnerhalb = Punkt(0.2, -0.3);
    auto punktAusserhalb = Punkt(1.1, 0.0);

    std::cout << "Inenerhalb: " << kreis.CheckIfInside(punktInnnerhalb) << std::endl;
    std::cout << "Ausserhalb: " << kreis.CheckIfInside(punktAusserhalb) << std::endl;

    kreis = kreis * 13.0;
    std::cout << "Ausserhalb nach vergroesserung: " << kreis.CheckIfInside(punktAusserhalb) << std::endl;

    std::cout << "Flaecheninhalt: " << kreis.CalculateSurface() << std::endl;
    std::cout << "Umfang: " << kreis.CalculateCircumference() << std::endl;

    std::cout << "Logge Kreis: " << kreis << std::endl;

    kreis = kreis << Kreis(1, 1, 0.1);
    std::cout << kreis << std::endl;

    std::cout << "schaffe einen neuen punkt:" << std::endl;
    Punkt p;
    std::cin >> p;
    std::cout << "dein eingebener punkt: " << p << std::endl;
}

