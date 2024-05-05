Task 1:
#include <iostream>
using namespace std;

class Diablos
{
private:
	string color;
	int cubic_capacity;
	int number_of_seats;
	int year;
	int engine_number;
	int frame_number;
	string name;


public:
	Diablos(string, int, int);
	~Diablos()
	{

	}
	void setter();
	int yeargetter();
	int enginegetter();
	int framegetter();
	string namegetter();
	string colorgetter();
	int cubicgetter();
	int seatgetter();
	Diablos(const Diablos& obj);

};

void Diablos::setter()
{
	cout << "Enter Year: ";
	cin >> year;
	cout << "Enter Engine: ";
	cin >> engine_number;
	cout << "Enter Frame: ";
	cin >> frame_number;
	cout << "Enter Name: ";
	cin >> name;

}
int	 Diablos::yeargetter() {
	return year;
}

int	 Diablos::enginegetter() {
	return engine_number;
}

int	 Diablos::framegetter() {
	return frame_number;
}

string Diablos::namegetter() {
	return name;
}


Diablos::Diablos(string color1 = "Hot Red", int cubic = 1000, int seats = 4) {
	color = color1;
	cubic_capacity = cubic;
	number_of_seats = seats;
}

Diablos::Diablos(const Diablos& obj1) {
	color = obj1.color;
	cubic_capacity = obj1.cubic_capacity;
	number_of_seats = obj1.number_of_seats;
}

string Diablos::colorgetter() {
	return color;
}

int Diablos::cubicgetter() {
	return cubic_capacity;
}

int Diablos::seatgetter() {
	return number_of_seats;
}

int main() {
	Diablos obj1, obj2(obj1);



	obj1.setter();
	cout << endl << endl;
	cout << "Owner Name: " << obj1.namegetter() << endl;
	cout << "Engine Number: " << obj1.enginegetter() << endl;
	cout << "Year: " << obj1.yeargetter() << endl;
	cout << "Frame Number: " << obj1.framegetter() << endl;
	cout << "Color: " << obj1.colorgetter() << endl;
	cout << "Cubic_Capacity: " << obj1.cubicgetter() << endl;
	cout << "Seat: " << obj1.seatgetter() << endl;

	cout << endl << endl;

	obj2.setter();
	cout << endl << endl;
	cout << "Owner Name: " << obj2.namegetter() << endl;
	cout << "Engine Number: " << obj2.enginegetter() << endl;
	cout << "Year: " << obj2.yeargetter() << endl;
	cout << "Frame Number: " << obj2.framegetter() << endl;
	cout << "Color: " << obj2.colorgetter() << endl;
	cout << "Cubic_Capacity: " << obj2.cubicgetter() << endl;
	cout << "Seat: " << obj2.seatgetter() << endl;

	cout << endl << endl;

	return 0;
}
		

Task 2:

#include <iostream>
using namespace std;

class Student
{
public:
	Student();
	void setmark(int, int);
	void print();
	void Delete();
	void Display();
	~Student();
private:
	int* p;
};

Student::Student()
{
	p = new int[5];

}

void Student::setmark(int i, int mark) {
	p[i] = mark;
}

void Student::print()
{
	for (int i = 0; i < 5; i++) {
		cout << p[i] << endl;
	}

}


void Student::Display() {
	for (int i = 0; i < 5; i++) {
		cout << "Mark: ";
		cout << p[i] << endl;
	}
	cout << endl;
}

void Student::Delete() {
	delete[] p;
}

Student::~Student() {
	delete[] p;
}

int main() {
	int mark;
	Student std1;
	for (int i = 0; i < 5; i++) {
		cout << "Enter Mark ";
		cin >> mark;
		std1.setmark(i, mark);
	}
	cout << endl;
	Student std2(std1);
	std1.Display();
	cout << endl;
	std2.Display();
	std1.Delete();
	std2.Display();
}

Task 3:
#include <iostream>
using namespace std;

class Student
{
public:
	Student();
	void setmark(int, int);
	void print();
	Student(const Student& obj);
	void Display();
	~Student();
private:
	int* p;
};

Student::Student()
{
	p = new int[5];

}

void Student::setmark(int i, int mark) {
	p[i] = mark;
}

void Student::print()
{
	for (int i = 0; i < 5; i++) {
		cout << p[i] << endl;
	}

}

Student::Student(const Student& obj)
{
	p = new int[5];
	for (int i = 0; i < 5; i++) {
		p[i] = obj.p[i];
	}
}

void Student::Display() {
	for (int i = 0; i < 5; i++) {
		cout << "Mark: ";
		cout << p[i] << endl;
	}
	cout << endl;
}

Student::~Student() {
	delete[] p;
}

int main() {
	int mark;
	Student std1;
	for (int i = 0; i < 5; i++) {
		cout << "Enter Mark ";
		cin >> mark;
		std1.setmark(i, mark);
	}
	cout << endl;
	Student std2(std1);
	std1.Display();
	cout << endl;
	std1.~Student();
	std2.Display();
}