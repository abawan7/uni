#include <iostream>
#include<math.h>
using namespace std;

class ComplexNumber
{
private:
	int real_no;
	int imaginary_no;
public:
	ComplexNumber();
	ComplexNumber(int, int);
	~ComplexNumber();
	void Input();
	void Output();
	bool IsEqual(ComplexNumber);
	ComplexNumber Conjugate();
	ComplexNumber Add(ComplexNumber);
	ComplexNumber Subtract(ComplexNumber);
	ComplexNumber Multiplication(ComplexNumber);
	float Magnitude();
};

ComplexNumber::ComplexNumber()
{
	real_no = 0;
	imaginary_no = 0;
}

ComplexNumber::ComplexNumber(int real, int imaginary)
{
	real_no = real;
	imaginary_no = imaginary;
}

void ComplexNumber::Input() {
	cout << "Enter Real Number: ";
	cin >> real_no;
	cout << "Enter Imaginary Number: ";
	cin >> imaginary_no;
	cout << endl << endl;
}

void ComplexNumber::Output() {

	if (imaginary_no >= 0) {
		cout << real_no << " + " << imaginary_no << "i" << endl << endl;
	}
	else {
		cout << real_no << " " << imaginary_no << "i" << endl << endl;
	}

}

bool ComplexNumber::IsEqual(ComplexNumber c) {
	if (real_no == c.real_no && imaginary_no == c.imaginary_no)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

ComplexNumber ComplexNumber::Conjugate()
{
	ComplexNumber c;
	imaginary_no = imaginary_no * (-1);
	return c;
}

ComplexNumber ComplexNumber::Add(ComplexNumber C)
{
	ComplexNumber add;
	add.real_no = real_no + C.real_no;
	add.imaginary_no = imaginary_no + C.imaginary_no;
	return add;
}

ComplexNumber ComplexNumber::Subtract(ComplexNumber C)
{
	ComplexNumber subtract;
	subtract.real_no = real_no - C.real_no;
	subtract.imaginary_no = imaginary_no - C.imaginary_no;
	return subtract;
}

ComplexNumber ComplexNumber::Multiplication(ComplexNumber C)
{
	ComplexNumber mul;
	mul.real_no = ((real_no * C.real_no) - (imaginary_no * C.imaginary_no));
	mul.imaginary_no = ((real_no * C.imaginary_no) + (imaginary_no * C.real_no));
	return mul;
}

float ComplexNumber::Magnitude()
{
	float M = 0;
	M = sqrt((real_no * real_no) + (imaginary_no * imaginary_no));
	return M;
}

ComplexNumber::~ComplexNumber()
{
}

void Check(bool flag) {
	if (flag == 1) {
		cout << "C1 and C2 are Equal." << endl;
	}
	else if (flag == 0) {
		cout << "C1 and C2 are not Equal. " << endl;
	}
	cout << endl << endl;
}



int main() {
	bool flag;
	ComplexNumber C1, C2;
	ComplexNumber s, a, m;
	cout << "Enter C1: " << endl;
	C1.Input();
	cout << "Enter C2: " << endl;
	C2.Input();
	cout << "C1 =   ";
	C1.Output();
	cout << "C2 =   ";
	C2.Output();
	flag = C1.IsEqual(C2);
	Check(flag);
	cout << "Conjugate of C1 is :       ";
	C1.Conjugate();
	C1.Output();
	cout << "Conjugate of C2 is :       ";
	C2.Conjugate();
	C2.Output();
	cout << "C1 + C2 =   ";
	a = C1.Add(C2);
	a.Output();
	cout << "C1 - C2 =    ";
	s = C1.Subtract(C2);
	s.Output();
	cout << "C1 * C2 =    ";
	m = C1.Multiplication(C2);
	m.Output();
	cout << "Magnitude of C1 =      ";
	cout << C1.Magnitude() << endl << endl;
	cout << "Magnitude of C2 =       ";
	cout << C2.Magnitude() << endl << endl;
	return 0;
}