#include <iostream>
#include <bitset>
using namespace std;

void Aufgabe1();
void Aufgabe2();
void Aufgabe3();
void Aufgabe4();
void Aufgabe5();

int main()
{
    /*while (true)*/ {
        //Aufgabe1();
        //Aufgabe2();
        //Aufgabe3();
        //Aufgabe4();
        Aufgabe5();
    }
}

int setBit(int number, int position, bool setToOne);
long long setBit(long long number, int position, bool setToOne);
void Aufgabe1() {
    int position = 1;
    bool setToOne = false;

    // i scope here so I can reuse the variable name 'result'
    {
        int bit32Value = 9;
        cout << "set int32 number: ";
        cin >> bit32Value;
        cout << "set position: ";
        cin >> position;
        cout << "to true? (0 for false | 1 for true)\n";
        cin >> setToOne;
        int result = setBit(bit32Value, position, setToOne);
        cout << "int32 result: " << result << "\n\n" << endl;
    }
    {
        long long bit64Value = 9;
        cout << "set int64 number: ";
        cin >> bit64Value;
        cout << "set position: ";
        cin >> position;
        cout << "to true? (0 for false | 1 for true)\n";
        cin >> setToOne;
        long long result = setBit(bit64Value, position, setToOne);
        cout << "int32 result: " << result << "\n\n" << endl;
    }
}

int setBit(int number, int position, bool setToOne) {
    // check if input value is 32 bit or 64 bit
    // int = 32 bit || long long = 64 bit
    
    // check if position is > 0 and < 32 || < 64 respectively
    if (position < 0 || position >= 32) {
        cerr << position << " is not in range of int" << endl;
        return -1;
    }
    if (setToOne) return number | 1 << position;
    else return number ^ 1 << position;
    // XOR - so the only position that is set on the right side, will have the same bit set as the original or if both are 0, we don't care.
}
long long setBit(long long number, int position, bool setToOne) {
    if (position < 0 || position >= 64) {
        cerr << position << " is not in range of long" << endl;
        return -1;
    }
    if (setToOne) return number | 1 << position;
    else return number ^ 1 << position;
}

//---------------------------------------
int invertBit(int number);
long long invertBit(long long number);
void Aufgabe2() {

    while (true) {
        int int32value = 0;
        cout << "\nnumber: ";
        cin >> int32value;
        int result = invertBit(int32value);
        cout << "\nresult: " << result << endl;
    }
}
int setBit(int number, int position) {
    return number | (1 << position);
}
int clearBit(int number, int position) {
    return number & ~(1 << position);
}
bool checkBit(int number, int position) {
    return (number & (1 << position)) != 0;
}

int invertBit(int number) {
    cout << "ich verstehe die aufgabe nicht. :(" << endl;
    return -1;
}

//-----------------------------------------

void Aufgabe3() {
    while (true) {
        int number;
        int result;
        cout << "\nVertausche Bit-Paare von Zahl: ";
        cin >> number;

        if(false) {   // quick and dirty
            int movedLeft = number << 1;
            // 0100'1011
            // 1001'0110
            int movedRight = number >> 1;
            // 0100'1011
            // 0010'0101
            result = movedLeft;
            // keine schöne bit schreibweise aber immerhin funktioniert's
            for (int i = 0; i < 32; i += 2) {
                result = checkBit(movedRight, i) ? setBit(result, i) : clearBit(result, i);
            }
        }

        {
            // Maske für ungerade Bits: 0xAAAAAAAA (0b.....10101010)
            int oddBits = number & 0xAAAA'AAAA; // 0b1010 1010 1010 1010 1010 1010 1010 1010
            // Maske für gerade Bits: (0b...01010101)
            int evenBits = number & 0x5555'5555;
            oddBits >>= 1;
            evenBits <<= 1;
            result = oddBits | evenBits;
        }

        bitset<32> originalBit(number);
        bitset<32> resultBit(result);
        cout << "getauschte bits:\n" << originalBit << "\n" << resultBit;
    }
}

void Aufgabe4() {
    // count the set bits in number
    int number;
    cout << "nummer: ";
    cin >> number;
    bitset<32> bit_num(number);
    int count = 0;
    if (false){ // meine version
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            if ((number & mask) == mask) count++;
        }
    }
    else {  // aarons version
        while (number) {
            count += number & 1;    // check least signifcant bit
            number >>= 1;           // shift all bits right
        }
    }
    
    cout << "0b" << bit_num << "\n1er bits: " << count << endl;
}

void Aufgabe5() {
    /*  Schreibe eine Funktion, die eine Ganzzahl und eine Anzahl von Bits als Parameter akzeptiert.Die Funktion soll
        die Bits der Zahl zirkulär nach links verschieben, d.h.die Bits, die links herausgeschoben werden, sollen rechts
        wieder hineingeschoben werden.Gib die veränderte Zahl zurück.
        int rotateLeft(int number, int bits);
            Hinweis: Verwende eine Kombination aus Links - und Rechtsverschiebungen sowie bitweisen OR - Operationen,
            um die Bits zu zirkulieren.
     */

    int number;
    cout << "nummer: ";
    cin >> number;
    bitset<32> bit_num(number);
    int positions;
    cout << "verschiebe um Anzahl Stellen: ";
    cin >> positions;

    // save bits that would get lost
    int safety = number >> (sizeof(number)*8 - positions);    // bei positions = 1 ist dann das letzte Bit das erste
    int moved = number << positions;
    int result = moved | safety;

    bitset<32> bit_result(result);
    cout << "og bit:\n" << bit_num << "\n" << bit_result << endl;

}

void Aufgabe6() {
    // extract bit range

    int number = 42;

    int startPosition = 2;
    int length = 2;

    int result = (number >> startPosition) & ((1 << length) - 1);
    // number = 0b00101010
    // start = 1; length = 4
    // mask = ((1 << length) - 1)
    // (0b0001'0101) & mask
    // (0b0001'0101) & ((0b0000'1000) - 0b0000'0001)
    // (0b0001'0101) & (0b0000'0111)
    // return = 0b0000'0101

}



