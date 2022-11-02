// 01.Exercise-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Rectangle {
private:
	double a, b;
public:
	Rectangle() //Дефиниция на конструктора
	{
		do
		{
			cout << "\n\nEnter two values for the sides of rectangle : \n";
			cin >> a >> b;
		} while (!((a > 0) && (b > 0)));
	}
	double face() //Дефиниция на член-функция face() без аргументи
	{
		double s;
		s = a * b;
		return s;
	};
	double face(double* p) //Член-функция face() с един аргумент
	{
		double pp = (a + b) * 2;
		*p = pp; //Връщане на втория резултат чрез аргумент-указател
		pp /= 2;
		double s;
		s = a * b;
		return s;
	} 
	void show(const char* name)
	{
		cout << "Sides of the rectangle " << name << ":\n";
		cout << "a = " << a << ", b = " << b;
	}
	~Rectangle() { cout << "\n\nDestructing object rectangle!\n"; }
};

int main()
{
	Rectangle r1; //Обект tr1; извиква се конструкторът на класа
	double p, s;
	r1.show("tr1");
	cout << "\nThe face of rectangle 1 is s = " << r1.face(); //Зарежда се член-функция
	//tr1.face(); // без аргумент
	Rectangle r2; //Обект tr2; извиква се конструкторът на класа
	r2.show("tr2");
	s = r2.face(&p); //Зарежда се член-функция face() с аргумент
	cout << "\nThe face of rectangle 2 is s = " << s << ", and the perimeter is p = " << p;
}

