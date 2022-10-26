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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
