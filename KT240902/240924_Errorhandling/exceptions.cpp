#include <iostream>

int divide(int, int, int&);
int divide_except(int, int);

int _main()
{
    int result = 0, num = 0, div = 0, errResult = 0;

    try {
        /*if (div == 0) {
            throw "Fehler: Division durch Null!";
        }*/
        result = divide_except(num, div);
        errResult = 0;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime Error: " << e.what() << std::endl;
        throw std::logic_error("Fehler im aeusseren try-block!");
    }
    catch (const std::exception& e) {
        std::cerr << "General excepetion: " << e.what() << std::endl;
    }
    catch (const char* errMsg) {
        std::cerr << "threw message: " << errMsg << std::endl;
    }
    catch (...){    // für alle möglichen exceptions
        std::cerr << "Unbekannter Fehler" << std::endl;
        errResult = -1;
    }

    return errResult;
}

int divide(int a, int b, int& result) {
    if (b == 0) {
        return -1;  // Fehlercode für Division durch 0
    }
    result = a / b;
    return 0;
}

int divide_except(int a, int b) {
    try {
        if (b == 0) {
            throw std::runtime_error("Division durch 0 im inneren try-Block!");
        }
    }
    catch (...) {
        return -1;
    }
    return a / b;
}

