#include <iostream>
#include <iomanip>

using namespace std;

class truck; //Предварителна декларация
class car {
	int passengers;
	int speed;
public:
	car(int p, int s) { passengers = p; speed = s; }
	friend int sp_greater(car c, truck t);
	friend double timeNeeded(double km, int type, car c, truck t);
};
class truck {
	int weight;
	int speed;
public:
	truck(int w, int s) { weight = w; speed = s; }
	friend int sp_greater(car c, truck t);
	friend double timeNeeded(double km, int type, car c, truck t);
};

/* Връща положителна стойност, ако скоростта на колата е по-голяма от
тази на камиона. Връща 0, ако скоростите са еднакви. Връща отрицателна
стойност, ако скоростта на камиона е по-голяма от тази на колата. */

int sp_greater(car c, truck t)
{
	return c.speed - t.speed;
}

double timeNeeded(double km, int type, car c, truck t) {
	if (type == 1) 
	{
		return km / c.speed;
	}

	else if (type == 2) 
	{
		return km / t.speed;
	}

	else 
	{
		cout << "Wrong vehicle type!" << endl;
		return 0;
	}
}

int main()
{
	int t;
	int time = 30;
	car c1(6, 55), c2(2, 120);
	truck t1(10000, 55), t2(20000, 72);

	cout << "Comparing c1 and t1:\n";
	t = sp_greater(c1, t1);
	if (t < 0) cout << "Truck is faster.\n";
	else if (t == 0) cout << "Car and truck speed is the same.\n";
	else cout << "Car is faster.\n";

	cout << "\nComparing c2 and t2:\n";
	t = sp_greater(c2, t2);
	if (t < 0) cout << "Truck is faster.\n";
	else if (t == 0) cout << "Car and truck speed is the same.\n";
	else cout << "Car is faster.\n";

	//Used to print to the 2nd decimal point
	std::cout << std::setprecision(2);

	cout << "\n Time needed for the entered km for car 2:\n";
	cout << timeNeeded(50.00, 1, c2, t2) << " hours";
	cout << "\n Time needed for the entered km for truck 2:\n";
	cout << timeNeeded(50, 2, c2, t2) << " hours";


	return 0;
}