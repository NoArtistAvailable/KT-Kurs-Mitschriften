#include <iostream>
#include <string.h>
using namespace std;

void Aufgabe1();
void Aufgabe2();
void Aufgabe3();

int main()
{
    Aufgabe2();
}

int* GetBiggestMember(int* arrayPointer, int arraySize);
void Aufgabe1() {
    int intArray[]{ 10,10,-4,900,16,24,33,265 };
    auto result = GetBiggestMember(intArray, size(intArray));
    cout << "pointer adress: " << result << "\npointer value: " << *result << endl;
}

int* GetBiggestMember(int* arrayPointer, int arraySize) {
    int max = INT_MIN;
    int* maxPointer = nullptr;
    for (int i = 0; i < arraySize; i++) {
        auto currentPointer = arrayPointer + i;
        auto currentValue = *currentPointer;
        if (currentValue > max) {
            max = currentValue;
            maxPointer = currentPointer;
        }
    }
    return maxPointer;
}

void AFunction(int inputArray[]) {
    constexpr int MAXIMUM_SIZE = 666;       //Der maximale Zahlenwert soll sich nie ändern können
    const int FIRST_VALUE = inputArray[0];  //Das erste element kann sich ändern vor funktionsaufruf aber nicht mehr danach
    cout << FIRST_VALUE << endl;
}

void Aufgabe2() {

    int intArray[]{ 10,10,-4,900,16,24,33,265 };
    int intArray2[]{ 4 };
    AFunction(intArray);
    AFunction(intArray2);
}

void Aufgabe3() {
    string cString = "Hallo Welt";
    // Pointer arithmetik (??)
}




