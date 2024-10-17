#include "Kreis.h"

const double PI = 3.14159;

double Kreis::CalculateSurface() const {
	return radius * radius * PI;
}

double Kreis::CalculateCircumference() const {
	return 2 * PI * radius;
}

bool Kreis::CheckIfInside(Punkt p) const {
	double distanceX = abs( p.x - position.x);
	double distanceY = abs( p.y - position.y);
	return (distanceX + distanceY) < radius;
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