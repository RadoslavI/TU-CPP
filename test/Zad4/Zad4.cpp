#include <iostream>
#include <vector>

using namespace std;

class Bank
{
public:
	string name;
	string accNum;
	double interestRate;
	double balance;
	Bank(string _name, string _accNum, double _balance)
	{
		name = _name;
		accNum = _accNum;
		balance = _balance;
		interestRate = 1.2;
	}

	double calcInterest(int months) 
	{
		return (double)(balance * interestRate) * months;
	}

	void deposit(double amount) {
		balance += amount;
	}

	virtual void withdraw(double amount) {
		balance -= amount;
	}

	double getBalance() {
		return balance;
	}

	void setBalance(double in) {
		balance = in;
	}
};

class SaveAccount : public Bank
{
public:
	string date;
	SaveAccount(string _date, string _name, string _accNum, double _balance) : Bank(_name, _accNum, _balance)
	{
		date = _date;
	}

	void withdraw(double amount, string _date)
	{
		if (date == _date) 
		{
			setBalance(balance -= amount);
		}
		else 
		{
			cout << "Cannot withdraw on that date!" << endl;
		}
	};
};

int main()
{
	vector<SaveAccount> accounts;

	SaveAccount a1("07.12.2022", "Ivan", "101", 1000);
	SaveAccount a2("07.12.2023", "Tanq", "102", 2500);
	SaveAccount a3("07.12.2022", "Tanq", "103", 100000);

	accounts.insert(accounts.begin(), a1);
	accounts.insert(accounts.begin(), a2);
	accounts.insert(accounts.begin(), a3);

	for (int i = 0; i < accounts.size(); i++)
	{
		if (accounts[i].date == "07.12.2022") {
			cout << " Account Number: " << accounts[i].accNum << " Balance: " << accounts[i].balance << endl;
		}
	}
}