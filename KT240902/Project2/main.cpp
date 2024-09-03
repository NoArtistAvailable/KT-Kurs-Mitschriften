#include <iostream>
using namespace std;

int main()
{
    int count1 = 0;
    int count2 = 0;

    std::cout << "Beispiel mit ++count1:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Wert von count1: " << ++count1 << std::endl;
    }

    std::cout << "Beispiel mit count2++:" << std::endl;
    for (int j = 0; j < 5; j++) {
        std::cout << "Wert von count2: " << count2++ << std::endl;
    }
}

