#pragma once
#include <math.h>
class Punkt {
public:
	double x, y;
	Punkt(double x = 0, double y = 0) : x(x), y(y) {}
	double GetDistanceTo(const Punkt& other) const {
		return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
	};
};