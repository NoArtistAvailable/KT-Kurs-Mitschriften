#pragma once
#include <math.h>
#include<iostream>
class Punkt {
public:
	double x, y;
	Punkt(double x = 0, double y = 0) : x(x), y(y) {}
	double GetDistanceTo(const Punkt& other) const {
		return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
	};
	Punkt operator+(Punkt other) {
		return Punkt(x + other.x, y + other.y);
	}
	friend std::istream& operator>>(std::istream& stream, Punkt& p);
	friend std::ostream& operator<<(std::ostream& stream, const Punkt& p);
};