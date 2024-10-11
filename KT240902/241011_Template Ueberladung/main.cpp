#include <iostream>

//----------Überladung----------
template <typename T>
void print(T value) {
    std::cout << "Generische Funktion: " << value << std::endl;
}

void print(int value) {
    std::cout << "Überladene Funktion für int: " << value << std::endl;
}

void print(double value) {
    std::cout << "Überladene Funktion für double: " << value << std::endl;
}

//-----------Spezialisierung------------
// Spezialisierung für int
template<>
void print<int>(int value) {
    std::cout << "Spezialisiertes Template für int: " << value << std::endl;
}

//----------Klassen Template-------------
template<typename T1, typename T2>
class MeineKlasse{
public:
    void print() {
        std::cout << "Generische klasse" << std::endl;
    }
};

template<typename T2>
class MeineKlasse<int, T2> {
public:
    void print() {
        std::cout << "Partielle Spezialisierung mit erstem Typ int" << std::endl;
    }
};

template<typename T>
class MeineKlasse<T, T> {
public:
    void print() {
        std::cout << "Spezialisierung wobei beide Typen gleich sind" << std::endl;
    }
};

int main()
{
    print(10);
    print(2.3);
    print("Hallo");

    MeineKlasse<double, char> obj1;
    MeineKlasse<int, char> obj2;
    MeineKlasse<float, float> obj3;

    obj1.print();
    obj2.print();
    obj3.print();

    return 0;
}

