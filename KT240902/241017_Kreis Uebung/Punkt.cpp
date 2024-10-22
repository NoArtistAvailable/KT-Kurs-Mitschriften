#include "Punkt.h"
std::istream& operator>>(std::istream& stream, Punkt& punkt) {
	stream >> punkt.x;
	stream >> punkt.y;
	return stream;
}
std::ostream& operator<<(std::ostream& stream, const Punkt& p) {
	stream << "(" << p.x << " | " << p.y << ")";
	return stream;
}