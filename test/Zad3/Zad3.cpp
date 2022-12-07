#include <iostream>

using namespace std;

class Temperature 
{
	double temp;
public:
	Temperature(double t)
	{
		temp = t;
	}
	
	void setTemp(double t) {
		temp = t;
	}

	double getTemp() {
		return temp;
	}

	virtual double Convert() {
		return temp;
	};
};

class Farenheit : public Temperature
{
public:
	Farenheit(double temp) : Temperature(temp)
	{
	}

	virtual double Convert() {
		double tempF = this->getTemp();

		double C = (double) 5 / 9 * (tempF - 32);

		return C;
	};
};

int main()
{
	Farenheit f1(50);

	cout << "Temp in F: " << f1.getTemp() << " Temp in C: " << f1.Convert() << endl;
}