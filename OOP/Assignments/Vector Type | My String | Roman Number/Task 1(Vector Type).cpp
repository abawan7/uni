#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

class Vector_Type
{
public:
	Vector_Type(double, double, double);
	void setter();
	Vector_Type(const Vector_Type&);
	void operator =  (const Vector_Type&);
	void Display();
	void Display2();
	double length();
	double angle(Vector_Type);
	double Product(Vector_Type);
	Vector_Type operator - (const Vector_Type);
	Vector_Type operator + (const Vector_Type);
	Vector_Type operator ++();
	Vector_Type operator ++(int);
	Vector_Type operator --();
	Vector_Type operator --(int);
	friend bool operator == (Vector_Type, Vector_Type);
	friend bool operator != (Vector_Type, Vector_Type);
	friend bool operator >> (Vector_Type, Vector_Type);
	friend bool operator << (Vector_Type, Vector_Type);
	~Vector_Type();

private:
	double* x;
	double* y;
	double* z;
	double a, b, c;
};

//Overloaded & Default Constructor
Vector_Type::Vector_Type(double a = 1, double b = 1, double c = 1)
{
	x = new double[a];
	y = new double[b];
	z = new double[c];
}

void Vector_Type::setter() {
	cout << "Enter X Value: ";
	cin >> *x;
	a = *x;
	cout << "Enter Y Value: ";
	cin >> *y;
	b = *y;
	cout << "Enter Z Value: ";
	cin >> *z;
	c = *z;
}


Vector_Type::Vector_Type(const Vector_Type& obj)
{
	x = new double;
	*x = *obj.x;
	a = obj.a;
	y = new double;
	*y = *obj.y;
	b = obj.b;
	z = new double;
	*z = *obj.z;
	c = obj.c;

}


void Vector_Type:: operator = (const Vector_Type& obj) {
	x = new double;
	*x = *obj.x;
	a = obj.a;
	y = new double;
	*y = *obj.y;
	b = obj.b;
	z = new double;
	*z = *obj.z;
	c = obj.c;
}

double Vector_Type::Product(Vector_Type c) {
	double product;
	product = (*x * *c.x) + (*y * *c.y) + (*z * *c.z);
	return product;
}

double Vector_Type::length() {
	double a;
	a = (*x * *x) + (*y * *y) + (*z * *z);
	a = sqrt(a);
	return a;
}
double Vector_Type::angle(Vector_Type c) {
	double angle;
	angle = (Product(c) / (length() * c.length())) * 180 / 3.1415;
	return angle;
}

Vector_Type Vector_Type:: operator - (const Vector_Type  obj) {
	Vector_Type temp;
	*temp.x = *x - *obj.x;
	*temp.y = *y - *obj.y;
	*temp.z = *z - *obj.z;
	return temp;
}

Vector_Type Vector_Type:: operator + (const Vector_Type  obj) {
	Vector_Type temp;
	*temp.x = *x + *obj.x;
	*temp.y = *y + *obj.y;
	*temp.z = *z + *obj.z;
	return temp;
}

Vector_Type Vector_Type:: operator ++() {
	++a;
	++b;
	++c;
	return *this;
}

Vector_Type Vector_Type:: operator ++(int) {
	a++;
	b++;
	c++;
	return *this;
}

Vector_Type Vector_Type:: operator --() {
	--a;
	--b;
	--c;
	return *this;
}

Vector_Type Vector_Type:: operator --(int) {
	a--;
	b--;
	c--;
	return *this;
}



bool operator== (Vector_Type c1, Vector_Type c2) {
	if (*c1.x == *c2.x && *c1.y == *c2.y && *c1.z == *c2.z) {
		cout << "Equal   ";
		return true;
	}
	else {
		cout << "Not Equal   ";
		return false;
	}
}

bool operator!= (Vector_Type c1, Vector_Type c2) {
	if (*c1.x != *c2.x && *c1.y != *c2.y && *c1.z != *c2.z) {
		cout << "Not Equal    ";
		return true;
	}
	else {
		cout << "Equal    ";
		return false;
	}
}

bool operator >> (Vector_Type c1, Vector_Type c2) {
	if (*c1.x > *c2.x && *c1.y > *c2.y && *c1.z > *c2.z) {
		cout << "Obj 1 Greater Than Obj 2     ";
		return true;
	}
	else {
		cout << "Not Greater    ";
		return false;
	}
}

bool operator << (Vector_Type c1, Vector_Type c2) {
	if (*c1.x < *c2.x && *c1.y < *c2.y && *c1.z < *c2.z) {
		cout << "Obj 1 Lesser Than Obj 2     ";
		return true;
	}
	else {
		cout << "Not Less    ";
		return false;
	}
}




void Vector_Type::Display() {
	cout << *x << "i  " << *y << "j  " << *z << "z  " << endl;
}

void Vector_Type::Display2() {
	cout << a << "i  " << b << "j  " << c << "z  " << endl;
}


Vector_Type::~Vector_Type()
{
	delete x;
	delete y;
	delete z;
}


int main() {
	bool flag;
	Vector_Type V, U(V), sub, add;
	V.setter();
	U = V;
	cout << "---------------------------" << endl << endl;
	cout << "Object 1:   ";
	V.Display();
	cout << "Object 2 After Calling Assignment Operator:   ";
	U.Display();
	cout << "---------------------------" << endl << endl;
	cout << "The Product is: " << V.Product(U) << endl;
	cout << "The Length of the vector is: " << V.length() << endl;
	cout << "The Length of the vector is: " << U.length() << endl;
	cout << "Angle: " << V.angle(U) << endl;
	cout << "---------------------------" << endl << endl;
	sub = V.operator-(U);
	cout << "After Subtraction:   ";
	sub.Display();
	add = V.operator+(U);
	cout << "After Addition:   ";
	add.Display();
	cout << "---------------------------" << endl << endl;
	flag = operator == (V, U);
	cout << " Flag: " << flag << endl;
	flag = operator != (V, U);
	cout << " Flag: " << flag << endl;
	flag = operator >> (V, U);
	cout << " Flag: " << flag << endl;
	flag = operator << (V, U);
	cout << " Flag: " << flag << endl;
	cout << "---------------------------" << endl << endl;

	V++;
	cout << "V after Calling Post - Increment:   ";
	V.Display2();

	++V;
	cout << "V after Calling Pre - Increment:   ";
	V.Display2();

	cout << "---------------------------" << endl << endl;

	U--;
	cout << "U after Calling Post - Decrement:   ";
	U.Display2();

	--U;
	cout << "U after Calling Pre - Decrement:   ";
	U.Display2();

	cout << "---------------------------" << endl << endl;
	cout << "Freeing memory!" << endl << endl;

}