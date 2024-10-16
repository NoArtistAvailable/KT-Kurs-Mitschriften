#include <iostream>
#include <tuple>

// UEBUNG 1 
template<typename... Args>
int sum(Args...args) {
    return (args + ...);    // fold expression needs c++17
}

// UEBUNG 2
template<typename... Args>
int max(Args...args) {
    int max = INT16_MIN;
    for (auto i : { args... }) {
        if (i > max) max = i;
    }
    return max;
}

// UEBUNG 3
template<typename... Args>
void print(Args...args) {
    ((std::cout << args << " "), ...);   // fold expression needs c++17
    std::cout << std::endl;
}

// UEBUNG 4
template<typename T, typename... Args>
void printTypes(const T& first, Args...args) {
    //auto info = typeid(first);
    std::cout << typeid(first).name() << " ";
    if constexpr (sizeof...(args) > 0)
        printTypes(args...);
    else std::cout << std::endl;
}

// UEBUNG 5
template<typename... Args>
std::tuple<Args...> createTuple(Args... args) {
    return std::tuple<Args...>(args...);
}

// UEBUNG 6
template<typename... Args>
int mult(Args...args) {
    return (args * ...);
}

// UEBUNG 7
template<typename... Args>
int averageOf(Args... args) {
    int sum = (args + ...);
    int count = sizeof...(args);
    return sum / count;
}

int main() {
    std::cout << "SUM: " << sum(13.0, 14, 27.0, 18.3) << std::endl;

    std::cout << "MAX: " << max(3, 4, 18, 22, 0, 4, 17) << std::endl;

    std::cout << "PRINT: ";
    print("Halloe ", 1, 2, 3, 'c', 3.0);

    std::cout << "TYPES: ";
    printTypes(1.0, 1, "Hallo", 'c', []() { }, 3L);

    std::cout << "TUPLE: ";
    auto tuple = createTuple(1, 'c', "Freundliches Tuple");
    std::cout << std::get<0>(tuple) << " ";
    std::cout << std::get<1>(tuple) << " ";
    std::cout << std::get<2>(tuple) << std::endl;

    std::cout << "MULT: " << mult(3.2, 4, 6, 0.2) << std::endl;
    std::cout << "AVERAGE: " << averageOf(3, 5, 6, 1, -20, -1000);

    return 0;
}