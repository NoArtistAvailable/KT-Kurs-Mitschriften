#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int zahl1 = 0b00100101;
    int zahl2 = 0b10010101;

    // Schiebeoperation
    // <<: Verschiebt die Bits in zahl1 um zahl2 Positionen nach links
    // 
    int leftShift = zahl1 << 3;
    cout << "Dezimal: " << leftShift << " | Hexadezimal: " << hex << leftShift << endl;
}

