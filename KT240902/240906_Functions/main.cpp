#include <iostream>
#include <bitset>
using namespace std;

int setBit(int number, int position);
int clearBit(int number, int position);
bool checkBit(int numer, int position);

int addMask(int number, int mask);
int clearMask(int number, int mask);
bool checkMask(int number, int mask);

int main()
{
    int number = 0b1010; // in dezimal = 10
    int position = 2;
    bitset<4> bin_number(number);   // Zahl in binär umwandeln
    bitset<4> bin_position(position);
    
    cout << "original number: 0b" << bin_number << endl;
    // Setze das Bit an Position 3
    bin_number = setBit(number, position);
    cout << "nach dem setzen von bit " << position << " | binaer: 0b" << bin_number << endl;

    // Löschen des Bits an Position 1
    bin_number = setBit(number, 1);
    cout << "nach dem löschen von bit 1 | binaer: 0b" << bin_number << endl;
}

/// Bit an Stelle @position auf 1 setzen
int setBit(int number, int position) {
    return number | (1 << position);
    // ich verschiebe die Zahl 1 | 0b0001 um 'position' Stellen nach links
}

/// Bit an Stelle @position auf 0 setzen
int clearBit(int number, int position) {
    return number & ~(1 << position);
}

/// Überprüfe ob Bit an Stelle @position 1 ist
bool checkBit(int number, int position) {
    return (number & (1 << position)) != 0;
}

int addMask(int number, int mask) {
    return number | mask;
}

int clearMask(int number, int mask) {
    return number & ~mask;
}

bool checkMask(int number, int mask) {
    return (number & mask) == mask;
}

