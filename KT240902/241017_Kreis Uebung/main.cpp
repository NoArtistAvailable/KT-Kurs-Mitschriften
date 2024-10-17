#include <iostream>
#include "Kreis.h"

int main()
{
    auto einheitsKreis = Kreis();

    auto punktInnnerhalb = Punkt(0.2, -0.3);
    auto punktAusserhalb = Punkt(1.1, 0.0);

    std::cout << "Inenerhalb: " << einheitsKreis.CheckIfInside(punktInnnerhalb) << std::endl;
    std::cout << "Ausserhalb: " << einheitsKreis.CheckIfInside(punktAusserhalb) << std::endl;

    einheitsKreis = einheitsKreis * 13.0;
    std::cout << "Ausserhalb nach vergrösserung: " << einheitsKreis.CheckIfInside(punktAusserhalb) << std::endl;

    std::cout << "Flaecheninhalt: " << einheitsKreis.CalculateSurface() << std::endl;
    std::cout << "Umfang: " << einheitsKreis.CalculateCircumference() << std::endl;

}

