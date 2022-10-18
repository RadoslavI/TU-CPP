#pragma once
#include <iostream>
using namespace std;

class Worker
{
private:
	int SSN, age, WXP, salariesNum;
	string name, role;
	double salaries[10];
public:
	Worker()
	{
		SSN = 0;
		WXP = 0;
		cout << "Enter the Position: " << endl;
		cin >> role;
	}
	void setData() {
		cout << "Enter the worker's name, age, number of salaries: " << endl;
		cin >> name >> age >> salariesNum;

		for (int i = 0; i < salariesNum; i++)
		{
			cout << "Enter salary number " << i + 1 << ":" << endl;
			cin >> salaries[i];
		}
	}
	double Avg() {
		double salarySum = 0;

		for (int i = 0; i < salariesNum; i++)
		{
			salarySum += salaries[i];
		}

		return salarySum / salariesNum;
	}
	double FindMin() {
		double currMin = salaries[0];

		for (int i = 1; i < salariesNum; i++)
		{
			if (currMin > salaries[i]) {
				currMin = salaries[i];
			}
		}

		return currMin;
	}

	void viewData() {
		cout << "Workers name, age, role: " << name << " " << age << " " << role << endl;
		cout << "Workers avarage salary: " << Avg() << endl;
		cout << "Workers minimum salary: " << FindMin() << endl;
	}

	~Worker() {
		cout << "\n Desructing object worker!\n";
		delete[] salaries;
	}
};
