#include <iostream>
#include <vector>

using namespace std;

class Bank
{
public:
	string name;
	double interestRate;
	double balance;
	Bank(string _name, double _balance, double _interestRate)
	{
		name = _name;
		balance = _balance;
		interestRate = _interestRate;
	}

	double calcInterest(int months)
	{
		return (double)(balance * interestRate) * months;
	}
};


class Deposit : public Bank
{
public:
	Deposit(string _name, double _balance, double _interestRate) : Bank(_name, _balance, _interestRate)
	{
	}

	void deposit(double amount) {
		balance += amount;
	}

	void withdraw(double amount)
	{
		balance -= amount;
	};
};

class Credit : public Bank
{
public:
	Credit(string _name, double _balance, double _interestRate) : Bank(_name, _balance, _interestRate)
	{
	}

	void deposit(double amount) {
		balance += amount;
	}
};

int main()
{
	vector<Bank> accounts;

	Deposit a1("Ivan", 1000, 1.5);
	Deposit a2("Tanq", 2500, 2.0);
	Credit a3("Tina", 100000, 0.4);
	Credit a4("Radi", 10000, 1.1);

	accounts.insert(accounts.begin(), a1);
	accounts.insert(accounts.begin(), a2);
	accounts.insert(accounts.begin(), a3);
	accounts.insert(accounts.begin(), a4);

	double currMax = accounts[0].interestRate;

	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i].interestRate > currMax) {
			currMax = accounts[i].interestRate;
		}
	}

	cout << currMax;
}