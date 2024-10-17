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

    std::cout << "Logge Kreis: " << kreis;

}

