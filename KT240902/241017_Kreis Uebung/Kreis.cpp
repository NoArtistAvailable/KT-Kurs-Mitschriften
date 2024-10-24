#include "Kreis.h"
#include<string>

const double PI = 3.14159;

double Kreis::CalculateSurface() const {
	return radius * radius * PI;
}

double Kreis::CalculateCircumference() const {
	return 2 * PI * radius;
}

bool Kreis::CheckIfInside(Punkt p) const {
	return position.GetDistanceTo(p) < radius;
}

std::ostream& operator<<(std::ostream& stream, const Kreis& kreis) {
	stream << "Kreis (" << kreis.position.x << ", " << kreis.position.y << ") radius: " << kreis.radius << " ";
	return stream;
}

Kreis operator<<(const Kreis& a, const Kreis& b) {
	return Kreis(
		a.position.x + b.position.x + b.radius,
		a.position.y + b.position.y + b.radius,
		a.radius
	);
}

std::string toString(const Kreis& kreis) {
	return "Kreis (" + std::to_string(kreis.position.x) + ", " + std::to_string(kreis.position.y) + ") radius: " + std::to_string(kreis.radius);
}