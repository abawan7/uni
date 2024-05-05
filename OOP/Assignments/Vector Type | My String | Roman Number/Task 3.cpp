#include <iostream>
using namespace std;

class Roman_Number
{
public:
	Roman_Number();
	void setter();
	void Converter();
	bool inputChecker(char);
	int value(char);
	Roman_Number operator + (const Roman_Number);
	Roman_Number operator - (const Roman_Number);
	Roman_Number operator * (const Roman_Number);
	Roman_Number operator / (const Roman_Number);
	friend bool operator == (Roman_Number, Roman_Number);
	friend bool operator != (Roman_Number, Roman_Number);
	friend int operator < (Roman_Number, Roman_Number);
	friend int operator > (Roman_Number, Roman_Number);

	void Display();
	~Roman_Number();

private:
	char *c;
	static int count;
	int x;
};

Roman_Number::Roman_Number()
{
	c = new char[10];
	x = 0;
}

bool Roman_Number::inputChecker(char r) {
	if (r == 'M') {
		return true;
	}
	else if (r == 'D') {
		return true;
	}
	else if (r == 'C') {
		return true;
	}
	else if (r == 'L') {
		return true;
	}
	else if (r == 'X') {
		return true;
	}
	else if (r == 'V') {
		return true;
	}
	else if (r == 'I') {
		return true;
	}
	else {
		return false;
	}
}

void Roman_Number::setter() {
	bool flag = false;
	while (flag == false) {
		if (flag == false) {
			cout << "Enter String: ";
			cin.getline(c, 10);
		}
		for (int i = 0; c[i] != '\0'; i++) {
			flag = inputChecker(c[i]);
			if (flag == false){
				cout << "Invalid Input" << endl;
				cout << "-----------------------" << endl;
				break;
			}
		}
	}
}


int Roman_Number::value(char r) {
	if (r == 'M') {
		return 1000;
	}
	else if (r == 'D') {
		return 500;
	}
	else if (r == 'C') {
		return 100;
		}
	else if (r == 'L') {
		return 50;
		}
	else if (r == 'X') {
		return 10;
	}
	else if (r == 'V') {
		return 5;
	}
	else if (r == 'I') {
		return 1;
	}
}

void Roman_Number::Converter() {
	for (int i = 0; c[i]!='\0'; i++) {
		if (c[i] < c[i + 1])
		{
			x += value(c[i + 1]) - value(c[i]);
			i++;
			continue;
		}
		x += value(c[i]);
	}
	cout << "Your Object Value is = " << x << endl;
}


Roman_Number Roman_Number:: operator + (const Roman_Number  obj) {
	Roman_Number temp;
	temp.x = x + obj.x;
	return temp;
}

Roman_Number Roman_Number:: operator - (const Roman_Number  obj) {
	Roman_Number temp;
	temp.x = x - obj.x;
	return temp;
}

Roman_Number Roman_Number:: operator * (const Roman_Number  obj) {
	Roman_Number temp;
	temp.x = x * obj.x;
	return temp;
}

Roman_Number Roman_Number:: operator / (const Roman_Number  obj) {
	Roman_Number temp;
	temp.x = x / obj.x;
	return temp;
}

bool operator== (Roman_Number c1, Roman_Number c2) {
	if (c1.x == c2.x) {
		return true;
	}
	else {
		return false;
	}
}

bool operator!= (Roman_Number c1, Roman_Number c2) {
	if (c1.x != c2.x) {
		return false;
	}
	else {
		return true;
	}
}

int operator < (Roman_Number c1, Roman_Number c2) {
	if (c1.x < c2.x) {
		return 0;
	}
	else if(c1.x > c2.x) {
		return 1;
	}
	else {
		return 2;
	}
}

int operator > (Roman_Number c1, Roman_Number c2) {
	if (c1.x > c2.x) {
		return 0;
	}
	else if (c1.x < c2.x) {
		return 1;
	}
	else {
		return 2;
	}
}

void Roman_Number::Display() {
	cout << x << endl;
}

Roman_Number::~Roman_Number()
{
}

int main() {
	int x;
	bool flag;
	Roman_Number R1, R2, oper;
	R1.setter();
	R1.Converter();
	cout << "-----------------------" << endl << endl;
	R2.setter();
	R2.Converter();

	cout << "-----------------------" << endl << endl;
	cout << "After Performing Addition:\t";
	oper = R1.operator+(R2);
	oper.Display();

	cout << "-----------------------" << endl << endl;
	cout << "After Performing Substraction:\t";
	oper = R1.operator-(R2);
	oper.Display();

	cout << "-----------------------" << endl << endl;
	cout << "After Performing Multiplication:\t";
	oper = R1.operator*(R2);
	oper.Display();

	cout << "-----------------------" << endl << endl;
	cout << "After Performing Division:\t";
	oper = R1.operator/(R2);
	oper.Display();

	cout << "-----------------------" << endl << endl;
	flag = operator == (R1, R2);
	if (flag == false) {
		cout << "Object 1 is Not Equal to Object 2: \t" << "False" << endl;
	}
	else {
		cout << "Object 1 is Equal to Object 2: \t" << "True" << endl;
	}

	cout << "-----------------------" << endl << endl;
	flag = operator != (R1, R2);
	if (flag == false) {
		cout << "Object 1 is Not Equal to Object 2: \t" << "True" << endl;
	}
	else {
		cout << "Object 1 is Equal to Object 2: \t" << "False" << endl;
	}

	cout << "-----------------------" << endl << endl;
	x = operator < (R1, R2);
	if (x == 0) {
		cout << "Object 1 is Less Than Object 2: \t" << "True" << endl;
	}
	else if (x == 1) {
		cout << "Object 1 is not Less Than Object 2: \t" << "False" << endl;
	}
	else if (x == 2) {
		cout << "It is neither Greater nor Less  : \t" << "Equal" << endl;
	}

	cout << "-----------------------" << endl << endl;
	x = operator > (R1, R2);
	if (x == 0) {
		cout << "Object 1 is Greater Than Object 2: \t" << "True" << endl;
	}
	else if (x == 1) {
		cout << "Object 1 is Not Greater Than Object 2: \t" << "False" << endl;
	}
	else if (x == 2) {
		cout << "It is neither Greater nor Less  : \t" << "Equal" << endl;
	}
}