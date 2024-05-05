#include<iostream>
#include "Circle.h"

using namespace std;

Circle::Circle(int x, int y, float r) : center(x, y) {
    radius = r;
    cout << "\nCircle Constructor called ";
}

void Circle::print() {
    center.print();
    cout << endl << radius;
}

Circle::~Circle() {
    cout << "\nCircle Destructor called ";
}
