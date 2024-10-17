#include "Kreis.h"

const double PI = 3.14159;

double Kreis::CalculateSurface() {
	return radius * radius * PI;
}

double Kreis::CalculateCircumference() {
	return 2 * PI * radius;
}

bool Kreis::CheckIfInside(Punkt p) {
	double distanceX = abs( p.x - position.x);
	double distanceY = abs( p.y - position.y);
	return (distanceX + distanceY) < radius;
}

std::ostream& operator<<(std::ostream& stream, const Kreis& kreis) {
	stream << "Kreis (" << kreis.position.x << ", " << kreis.position.y << ") radius: " << kreis.radius << " ";
	return stream;
}