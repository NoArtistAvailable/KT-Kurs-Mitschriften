#include "pch.h"

enum TriangleType {
	GLEICHSEITIG = 1 << 0, 
	GLEICHSCHENKLIG = 1 << 1,
	UNGLEICHSEITIG = 1 << 2,
	RECHTWINKLIG = 1 << 3,
	STUMPF = 1 << 4,
	UNGUELTIG = 0
};

bool isTriangle(int a, int b, int c) {
	return a > 0 && b > 0 && c > 0 && a+b > c && b+c > a && a+c > b;
}

int triangleType(int a, int b, int c) {
	if (!isTriangle(a, b, c)) return UNGUELTIG;
	if (a == b && a == c) return GLEICHSEITIG;
	if (a == b || b == c || a == c) return GLEICHSCHENKLIG;
	int a2 = a * a;
	int b2 = b * b;
	int c2 = c * c;
	if (a2 + b2 == c2 || a2 + c2 == b2 || b2 + c2 == a2) return RECHTWINKLIG;
	return STUMPF;
}

//-------TEST-EBENE-------
TEST(TriangleTest, invalidTriangle) {
	EXPECT_FALSE(isTriangle(-1, 0, 5));
	EXPECT_FALSE(isTriangle(0, 0, 0));
	EXPECT_FALSE(isTriangle(1, 1, 10));
	
}

TEST(TriangleTest, validTriangle) {
	EXPECT_TRUE(isTriangle(1, 1, 1));
	EXPECT_TRUE(isTriangle(3, 4, 5));
	EXPECT_TRUE(isTriangle(5, 4, 5));
	EXPECT_TRUE(isTriangle(7, 7, 7));
}

TEST(TriangleTest, equirect) {
	EXPECT_EQ(triangleType(3, 3, 3), GLEICHSEITIG) << "Der Typ 3,3,3 ist gleichseitig";
}

TEST(TriangleTest, scaleneTriangle) {
	EXPECT_NE(triangleType(3, 4, 6), GLEICHSEITIG) << "Dreieck 3,4,6 ist nicht gleichseitig";
}

TEST(TriangleTest, isoscalesTriangle) {
	EXPECT_EQ(triangleType(2, 3, 3), GLEICHSCHENKLIG) << "Dreieck 2, 3, 4 ist gleichschenklig";
	EXPECT_EQ(triangleType(4, 4, 3), GLEICHSCHENKLIG) << "Dreieck 4, 4, 3 ist gleichschenklig";
}

TEST(TriangleTest, rightAngle) {
	EXPECT_EQ(triangleType(3, 4, 5), RECHTWINKLIG) << "Dreieck 3,4,5 ist rechtwinklig";
}