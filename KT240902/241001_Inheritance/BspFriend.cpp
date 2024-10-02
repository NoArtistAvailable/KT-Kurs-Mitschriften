#include <iostream>
#include <windows.h>

class Kreis {
private: 
	double radius;
public:
	Kreis(double r) : radius(r){}
	// friend methode
	friend double berechneFlaeche(const Kreis& k);
};

// definition der friend-methode auﬂerhalb der Klasse
double berechneFlaeche(const Kreis& k) {
	return 3.14 * k.radius * k.radius;	// zugriff auf den privaten Member
}

// friend class
class Geheimnis {
private:
	std::string geheimerText;
public:
	Geheimnis(const std::string& text) : geheimerText(text) {}

	//deklaration der Freundesklasse
	friend class Detektiv;	//Detektiv hat Zugroff auf den geheimen Text
};

class Detektiv {
public:
	void luefteGeheimnis(const Geheimnis& g) {
		std::cout << "Das Geheimnis lautet: " << g.geheimerText << std::endl;
	}
};

int main() {
	SetConsoleOutputCP(1252);
	setlocale(LC_ALL, "de_DE");

	Kreis k(5.0);
	std::cout << "Flaeche des Kreises: " << berechneFlaeche(k) << std::endl;

	Geheimnis g("Die Wahrheit ist eine L¸ge");
	Detektiv sherlock;
	sherlock.luefteGeheimnis(g);

	return 0;
}