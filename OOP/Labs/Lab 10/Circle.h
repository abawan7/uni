#pragma once
#include "Point.h"

class Circle {
public:
    Circle(int,int,float);
    void print();
    ~Circle();
private:
    Point center;
    float radius;
};
