#include <iostream>
using namespace std;

void notes()
{
    {
        short* pShortVar;
        long* pCounter;
        char* pChar;

        int* pVar1, pVar2; // *pVar1 ist ein Zeiger, pVar2 ist KEIN Zeiger
        int* pVar3;
        int* pVar4;

        short var;      // Deklaration Wert
        short* pVar;    // Deklaration von Zeiger   | * Zeigeroperator / Dereferenzierungsoperator
        pVar = &var;    // Zuweisung von Adresse    | & Adressoperator / Referenzierungsoperator

        short** nested = &pVar;
        short*** nestedDeeper = &nested;
    }
    {
        // Adresse 0x2000 in char-zeiger laden
        auto pChVar = reinterpret_cast<char*>(0x2000);

        int* pInt = nullptr;
    }
    {
        short shortValue = 10;
        short* pShortValue = &shortValue;
        (*pShortValue)++;
        *pShortValue++; // zählt die adresse hoch (?)
    }
    {
        // Zeichen konstante
        const char someValue = 'A';
        // Zeichen Variable
        char someVar = 'a';

        //decltype(variable) nimmt den typen der variable

        // Zeiger auf char-konstante
        const decltype(someValue)* somePointer = &someValue;
        // const-Zeiger auf eine Variable
        decltype(someVar)* const someOtherPointer = &someVar;
        // const zeiger auf eine char-konstante
        const decltype(someValue)* const constantPointerAtConstantValue = &someValue;
        // const decltype(someValue)* ist das gleiche wie decltype(someValue) const*;

        // *somePointer = 'B'   // nicht erlaubt
        somePointer++;  // zählt die Adresse hoch        
        *someOtherPointer = 'b';    // ist erlaubt
        // *someOtherPointer++;    // nicht erlaubt weil die Adresse fest ist

        cout << sizeof(somePointer) << endl;    // größe vom pointer ist immer 4 byte in 32 Bit systemen und 8 byte in 64 bit systemen

    }

}

void main() {
    // ARRAYS
    int intArray[10] = {1,3,4,4,4,5,6};
    for (int i = 0; i < size(intArray); i++) {
        cout << intArray[i] << ", ";
    }
    cout << "\n\n";


    // short shortArray[]; <- nicht zulässig
    short shortArray[]{ 10,20,20,20 };  // automatische größe

    constexpr int SIZE = size(shortArray);
    // const: Markiert eine Variable als unveränderlich, kann jedoch zur Compile-Zeit oder Laufzeit ausgewertet werden.
    // constexpr: Markiert eine Konstante oder Funktion, die garantiert zur Compile - Zeit ausgewertet werden muss.

    cout << "for (auto pItem = shortArray; pItem < (shortArray + SIZE); pItem++)" << endl;
    // wir iterieren so lange unsere adresse kleiner ist als unsere start adresse + länge des arrays
    for (auto pItem = shortArray; pItem < (shortArray + SIZE); pItem++) {
        cout << *pItem << ", ";
    }
    cout << "\n\n";

    cout << "for (short item : shortArray)" << endl;
    for (short item : shortArray) {
        cout << item << ", ";
    }
    cout << "\n\n";

}

