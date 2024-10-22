#pragma once
#include "Punkt.h"
#include<iostream>
class Kreis {
private:
	Punkt position;
	double radius;
public:
	Kreis(double x = 0, double y = 0, double radius = 1) : Kreis(Punkt(x, y), radius) {}
	Kreis(const Punkt& p, double radius) : position(p),radius(radius){
		if (radius <= 0) {
			throw std::exception("Radius can not be equal or smaller than 0");
		}
	}
	
	Punkt getPosition() const { return position; }
	void setPosition(const Punkt& p) { position = p; }
	void setPosition(double x, double y) { position = Punkt(x, y); }

	double getRadius() const { return radius; }
	void setRadius(double value) {
		if (value <= 0) {
			throw std::exception("Radius can not be equal or smaller than 0");
		}
		radius = value;
	}

	double CalculateSurface() const;
	double CalculateCircumference() const;
	bool CheckIfInside(Punkt p) const;

	Kreis operator*(double scalar) {
		return Kreis(position, radius * scalar);
	}

	friend std::ostream& operator<< (std::ostream & stream, const Kreis & kreis);
	friend Kreis operator<<(const Kreis& a, const Kreis& b);
	friend std::string toString(const Kreis& kreis);
};