#include <iostream>
using namespace std;

class Roman_Number
{
public:
	Roman_Number(int);
	void setter();
	void Converter();
	Roman_Number operator + (const Roman_Number);
	Roman_Number operator - (const Roman_Number);
	Roman_Number operator * (const Roman_Number);
	Roman_Number operator / (const Roman_Number);
	friend bool operator == (Roman_Number, Roman_Number);
	friend bool operator != (Roman_Number, Roman_Number);
	friend int operator < (Roman_Number, Roman_Number);
	friend int operator > (Roman_Number, Roman_Number);
	void Display();
private:
	int num;
};

Roman_Number::Roman_Number(int n=0)
{
	num = n;
}


void Roman_Number::Converter() {
	string str_romans[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
	int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 ,0};
	int n;
	string result = "";
	n = num;
	if (num == 0) { cout << "No Zero In Roman" << endl; }
	else {
		for (int i = 0; i < 13; ++i)
		{
			while (n - values[i] >= 0)
			{
				result += str_romans[i];
				n -= values[i];
			}
		}
		cout << result << endl;
	}
}

Roman_Number Roman_Number:: operator + (const Roman_Number  obj) {
	Roman_Number temp;
	temp.num = num + obj.num;
	return temp;
}

Roman_Number Roman_Number:: operator - (const Roman_Number  obj) {
	Roman_Number temp;
	if (num - obj.num == 0) {
		temp.num = 0;
	}
	else {
		temp.num = num - obj.num;
	}
	return temp;
}

Roman_Number Roman_Number:: operator * (const Roman_Number  obj) {
	Roman_Number temp;
	temp.num = num * obj.num;
	return temp;
}

Roman_Number Roman_Number:: operator / (const Roman_Number  obj) {
	Roman_Number temp;
	temp.num = num / obj.num;
	return temp;
}


bool operator== (Roman_Number c1, Roman_Number c2) {
	if (c1.num == c2.num) {
		return true;
	}
	else {
		return false;
	}
}


bool operator!= (Roman_Number c1, Roman_Number c2) {
	if (c1.num != c2.num) {
		return false;
	}
	else {
		return true;
	}
}


int operator < (Roman_Number c1, Roman_Number c2) {
	if (c1.num < c2.num) {
		return 0;
	}
	else if (c1.num > c2.num) {
		return 1;
	}
	else {
		return 2;
	}
}

int operator > (Roman_Number c1, Roman_Number c2) {
	if (c1.num > c2.num) {
		return 0;
	}
	else if (c1.num < c2.num) {
		return 1;
	}
	else {
		return 2;
	}
}


void Roman_Number::Display() {
	if (num == 0) {
		cout << "0" << endl;
	}
	else {
		cout << num << endl;
	}
}

int main() {
	int x;
	bool flag;
	int x1,x2;
	cout << "Enter Number: \t";
	cin >> x1;
	Roman_Number R1(x1), oper;
	cout << "Your Object Value is = ";
	R1.Converter();
	cout << "-----------------------" << endl << endl;
	cout << "Enter Number: \t";
	cin >> x2;
	Roman_Number R2(x2);
	cout << "Your Object Value is = ";
	R2.Converter();

	cout << "-----------------------" << endl << endl;
	cout << "After Performing Addition:\t";
	oper = R1+R2;
	oper.Display();
	cout << "\nRoman Number After Performing Addition:\t";
	oper.Converter();

	cout << "-----------------------" << endl << endl;
	cout << "After Performing Substraction:\t";
	oper = R1-R2;
	oper.Display();
	cout << "\nRoman Number After Performing Substraction:\t";
	oper.Converter();

	cout << "-----------------------" << endl << endl;
	cout << "After Performing Multiplication:\t";
	oper = R1*(R2);
	oper.Display();
	cout << "\nRoman Number After Performing Multiplication:\t";
	oper.Converter();

	cout << "-----------------------" << endl << endl;
	cout << "After Performing Division:\t";
	oper = R1/(R2);
	oper.Display();
	cout << "\nRoman Number After Performing Divison:\t";
	oper.Converter();

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
		cout << "It is neither Greater nor Less: \t" << "Equal" << endl;
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
		cout << "It is neither Greater nor Less: \t" << "Equal" << endl;
	}
}