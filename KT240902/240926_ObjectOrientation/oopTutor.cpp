#include <iostream>
#include <bitset>

struct Point {
	// verwendet primär als daten container (konvention)
private:	//struct attributes are public by default
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	void Show() {	//Methods are functions of classes
		std::cout << "Punkt (" << x << "|" << y << ")" << std::endl;
	}
};

class Circle {
	double radius;	// class attributes are private by default
public:
	Circle(double r) : radius(r) {}
	Circle() = delete;	// removing default constructor
	~Circle() {			// destructor
		std::cout << "Kreis entladen" << std::endl;
	}


	double CalculateSurface() {
		// could also be Circle::radius or this->radius
		return 3.14159265 * radius * radius;
	}
	double getRadius() { return radius; }
	void setRadius(double value) { radius = value; }
};

union Number {
	// union attributes are public by default
	// union attribute teilen sich den gleichen speicher bereich
	// daher die gleichen bytes
	int intNum;
	float floatNum;
};

enum Typ { GANZEZAHL = 1 << 1, KOMMAZAHL = 1 << 2, BUCHSTABE = 1 << 3 };

int main_() {
	// Objekterstellung / Instanzierung
	Point p1 = { 10, 2 };
	p1.Show();

	Circle circle1 = Circle(20.3);

	Number num;
	num.intNum = 42;
	std::cout << "Ganze Zahl: " << num.intNum << " Komma Zahl: " << num.floatNum << std::endl;

	Typ zahlenTyp = (Typ)0;
	int eineZahl = (int) GANZEZAHL;

	std::cout << zahlenTyp << std::endl;

	return 0;
}

