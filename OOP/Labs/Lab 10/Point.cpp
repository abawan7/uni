#include <iostream>
#include"Point.h"

using namespace std;

Point::Point(int x1, int y1) {
	x = x1;
	y = y1;
	cout << "Point Constructor called ";
}

void Point::print() {
	cout << " (" << x << "," << y << ")";
}

Point::~Point() {
	cout << "\nPoint Destructor called ";
}