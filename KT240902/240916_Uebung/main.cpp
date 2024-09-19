#include <iostream>

void bits()
{
    
    unsigned int flag = 0;
    enum Cars {Trabant = 1 << 1, Isetta = 1 << 2, BMW3er = 1 << 8};
    flag = Trabant | BMW3er;

    std::cout << flag << std::endl;

    if (flag & Trabant) {
        std::cout << "Trabant freigeschaltet" << std::endl;
    }
    if (flag & Isetta) {
        std::cout << "Isetta freigeschaltet" << std::endl;
    }
    if (flag & BMW3er) {
        std::cout << "BMW3er freigeschaltet" << std::endl;
    }



}

void main() {
    int a = 10;
    int* p_a = &a;

    int& b = a; // b ist an der gleichen stelle wie a   // b ist ein alias von a
    b = 45;

    std::cout << "a: " << a << " | b: " << b << std::endl;

}

