#include<iostream>
#include "Circle.h"
#include "Point.h"

using namespace std;

int main() {
    int x, y;
    float r;
    cout << "Enter x coordinates:   ";
    cin >> x;
    cout << "Enter y coordinates:   ";
    cin >> y;
    cout << "Enter Radius:   ";
    cin >> r;
    Circle c(x, y, r);
    c.print();
}
