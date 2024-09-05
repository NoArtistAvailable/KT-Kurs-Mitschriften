#include <iostream>
using namespace std;

auto show_classification(double x)
{
    switch (std::fpclassify(x))
    {
    case FP_INFINITE:
        return "Inf";
    case FP_NAN:
        return "NaN";
    case FP_NORMAL:
        return "normal";
    case FP_SUBNORMAL:
        return "subnormal";
    case FP_ZERO:
        return "zero";
    default:
        return "unknown";
    }
}

int main()
{
    /*int count1 = 0;
    int count2 = 0;

    std::cout << "Beispiel mit ++count1:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Wert von count1: " << ++count1 << std::endl;
    }

    std::cout << "Beispiel mit count2++:" << std::endl;
    for (int j = 0; j < 5; j++) {
        std::cout << "Wert von count2: " << count2++ << std::endl;
    }*/

    cout << show_classification(1.0 - 1.0) << endl;

}



