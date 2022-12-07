#include <iostream>
#include <vector>

using namespace std;

class Figure
{
	int radius;
public:
	Figure(int r) {
		radius = r;
	}

	int getRadius()
	{
		return radius;
	}

	void setRadius(int in) 
	{
		radius = in;
	}

	virtual double Area() {
		return 0;
	}
};

class Circle : public Figure
{
public:
	Circle(int r) : Figure(r)
	{
	}

	double virtual Area() {
		return 3.14 * getRadius() * getRadius();
	}
};

int main()
{
	Circle c1(10);
	Circle c2(5);

	if (c1.Area() > c2.Area()) {
		cout << "First area is bigger: " << c1.Area() << endl;
	}
	else {
		cout << "Second area is bigger: " << c2.Area() << endl;
	}
}