#include <iostream>
#include <cmath>
using namespace std;

class triangle {
private:
	double a, b, c;
public:
	triangle() 
	{
		do
		{
			cout << " Enter a, b, c: " << endl;
			cin >> a >> b >> c;
		}

		while (!(a > 0) && !(b > 0) && !(c > 0) && (a + b > c) && !(a + c > b) && !(b + c > a));
	}
	
	double face()
	{
		double p, s;
		p = (a + b + c) / 2;
		s = p * ((p - a) * (p - b) * (p - c));
		return s;
	}
	void show(const char* name)
	{
		cout << " Sides of the triangle: " << name << endl;
		cout << "a = " << a << " b = " << b << " c = " << c;
	}

	~triangle() {
		cout << "\n Desructing object triangle!\n";
	}
};

