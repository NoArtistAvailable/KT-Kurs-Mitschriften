#include <iostream>
#include <bitset>
using namespace std;

void Aufgabe1();
void Aufgabe2();
void Aufgabe3();

int main()
{
    //Aufgabe1();
    //Aufgabe2();
    Aufgabe3();
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
        cout << "\nVertausche Bit-Paare von Zahl: ";
        cin >> number;

        int movedLeft = number << 1;
        // 0100'1011
        // 1001'0110
        int movedRight = number >> 1;
        // 0100'1011
        // 0010'0101
        int result = movedLeft;
        // keine schöne bit schreibweise aber immerhin funktioniert's
        for (int i = 0; i < 32; i += 2) {
            result = checkBit(movedRight, i) ? setBit(result, i) : clearBit(result, i);
        }
        bitset<32> originalBit(number);
        bitset<32> resultBit(result);
        cout << "getauschte bits:\n" << originalBit << "\n" << resultBit;
    }
}



