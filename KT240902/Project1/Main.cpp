#include <iostream>
using namespace std;

//Kurs Helloworld
//int main() {
//	std::cout << "Hello World" << std::endl;
//	return 0;
//}

//Uebungsaufgabe A


// A)
//int main() {
//	int myAge;
//	cout << "Enter your age: ";
//	cin >> myAge;
//	std::cout << (myAge * 2);
//}

int main() {
	int num;

	cout << "Bitte gib eine Zahl ein: ";
	cin >> num;

	cout << "\aDu hast folgenden Wert eingegeben Wert eingegeben: " << num << endl;

	
	// implizit
	int i = 10;
	double d = i;

	// C-Style Cast
	d = 6.987;
	i = (int)d;

	// functional casting
	d = 6.879;
	i = int(d);

	// static cast
	i = static_cast<int>(d);

	// dynamic cast
	class Basis {virtual void func() {} };
	class Ableitung : public Basis{};

	Basis* b = new Ableitung();
	Ableitung* a = dynamic_cast<Ableitung*>(b);

	cout << "Typecast D " << d << "I " << i << endl;

	return num;
}