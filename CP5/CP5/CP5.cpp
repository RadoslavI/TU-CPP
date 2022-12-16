#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <list>
#include <map>
#include <iomanip>

using namespace std;

class Material {
	string name;
	double price;
public:
	Material() {

	}
	Material(string n, double p) {

	}
	void setName(string n) {
		name = n;
	}
	void setPrice(double p) {
		price = p;
	}
	string getName() {
		return name;
	}
	double getPrice() {
		return price;
	}
};

class Optic {
	string type;
	double width;
	double dioptre;
	Material material;
public:
	Optic()
	{
		type = "default type";
		width = 0.0;
		dioptre = 0.0;
		material.setName("plastic");
		material.setPrice(0.0);
	}

	Optic(string t, double w, double d, Material m) {
		type = t;
		width = w;
		dioptre = d;
		material = m;
	}

	void setType(string t) {
		type = t;
	}

	string getType() {
		return type;
	}

	void setWidth(double w) {
		width = w;
	}
	
	double getWidth() {
		return width;
	}

	void setDioptre(double d) {
		dioptre = d;
	}

	double getDioptre() {
		return dioptre;
	}

	void setMaterial(Material m) {
		material = m;
	}

	Material getMaterial() {
		return material;
	}
};

class Distributor 
{
	string bulstat;
	string name;
	string location;
	string phone;
	vector<Optic> optics;
public:
	Distributor()
	{
		bulstat = "default bulstat";
		name = "default name";
		location = "Sofia";
		phone = "+359999999";
		optics.push_back(Optic());
	}

	Distributor(string b, string n, string l, string p)
	{
		bulstat = b;
		name = n;
		location = l;
		phone = p;
	}

	void setBulstat(string b) {
		bulstat = b;
	}

	string getBulstat() {
		return bulstat;
	}

	void setName(string n) {
		name = n;
	}

	string getName() {
		return name;
	}

	void setLocation(string l) {
		location = l;
	}

	string getLocation() {
		return location;
	}

	void setPhone(string p) {
		phone = p;
	}

	string getPhone() {
		return phone;
	}

	void addOptic(Optic o) { 
		this->optics.push_back(o);
	}

	vector<Optic> getOptics() {
		return this->optics;
	}

	friend ostream& operator<<(ostream& os, const Distributor& d);
};

ostream& operator<<(ostream& os, const Distributor& d)
{
	fstream myfile("DistributorInfo.txt", ios::app);
	if (myfile.is_open()) {
		os << "Distributor info: " << endl;
		myfile << "Distributor info: " << endl;
		os << "Bulstat: " << d.bulstat << endl;
		myfile << "Bulstat: " << d.bulstat << endl;
		os << "Name: " << d.name << endl;
		myfile << "Name: " << d.name << endl;
		os << "Location: " << d.location << endl;
		myfile << "Location: " << d.location << endl;
		os << "Phone number: " << d.phone << endl;
		myfile << "Phone number: " << d.phone << endl;
		os << "Delivers optics: " <<  endl;
		myfile << "Delivers optics: " << endl;
		for (int i = 0; i < d.optics.size(); i++)
		{
			Optic currOptic = d.optics[i];
			os << currOptic.getMaterial().getName() << endl;
			myfile << currOptic.getMaterial().getName() << endl;
		}

		myfile.close();
	}

	return os;
}

int main()
{
	vector<Distributor> distributors;
	vector<Optic> optics;

	int operation = -1;

	while (operation != 0)
	{
		cout << "Please select an operation: " << endl;
		cout << "1) - Create a Distributor" << endl;
		cout << "2) - Create an Optic and add it to a destributor" << endl;
		cout << "3) - Make an order" << endl;
		cout << "0) - Exit" << endl;
		cin >> operation;

		if (operation == 1)
		{
			string currBulstat;
			string currName;
			string currLocation;
			string currPhone;

			cout << "Enter bulstat: " << endl;
			cin >> currBulstat;
			cout << "Enter name: " << endl;
			cin >> currName;
			cout << "Enter location: " << endl;
			cin >> currLocation;
			cout << "Enter phone number: " << endl;
			cin >> currPhone;
			Distributor currDestr(currBulstat, currName, currLocation, currPhone);
			cout << "Operation successfull" << endl;
		}
		else if (operation == 2)
		{
			string searchBulstat;
			cout << "Enter destributor bulstat" << endl;
			cin >> searchBulstat;

			Distributor* currDistr = &distributors[0];
			bool result = false;
			for (int i = 0; i < distributors.size(); i++)
			{
				string currBulstat = distributors[i].getBulstat();
				if (currBulstat == searchBulstat) {
					currDistr = &distributors[i];
					result = true;
				}
			}

			if (result) {
				string currType;
				double currWidth;
				double currDioptre;
				string currMaterialName;
				double currMaterialPrice;

				cout << "Enter type: " << endl;
				cin >> currType;
				cout << "Enter width: " << endl;
				cin >> currWidth;
				cout << "Enter dioptre: " << endl;
				cin >> currDioptre;
				cout << "Enter material name: " << endl;
				cin >> currMaterialName;
				cout << "Enter material price: " << endl;
				cin >> currMaterialPrice;

				currDistr->addOptic(Optic(currType, currWidth, currDioptre,
					Material(currMaterialName, currMaterialPrice)));
			}
			else {
				cout << "A distributor with the entered Bulstat doesn't exist!" << endl;
			}
			cout << "Operation successfull" << endl;
		}
		else if (operation == 3)
		{
			Distributor* currDistr = &distributors[0];
			string searchDistrName;

			cout << "Choose a distributor from the list: " << endl;
			cout << "====================================" << endl;
				for (size_t i = 0; i < distributors.size(); i++)
				{
					cout << "Distributor " << i + 1 << distributors[i].getName();
				}
			cout << "====================================" << endl;
			cin >> searchDistrName;

			bool result = false;
			for (int i = 0; i < distributors.size(); i++)
			{
				string currDistrName = distributors[i].getName();

				if (currDistrName == searchDistrName) {
					currDistr = &distributors[i];
					result = true;
				}
			}

			int command = -1;

			if (result) {
				double totalPrice = 0;
				string searchOpticType;
				int quantity = 0;
				Optic* searchOptic = &distributors[0].getOptics()[0];
				cout << "This distributor has these types of optics and prices: " << endl;
				cout << "====================================" << endl;
				bool result2 = false;
				for (int i = 0; i < currDistr->getOptics().size(); i++)
				{
					Optic currOptic = currDistr->getOptics()[i];
					Material currMaterial = currOptic.getMaterial();
					cout << currOptic.getType() << currMaterial.getPrice() << endl;
				}
				cout << "====================================" << endl;
				while (command != 0) {
					cout << "Enter desired optic's type: " << endl;
					cin >> searchOpticType;
					for (int i = 0; i < currDistr->getOptics().size(); i++)
					{
						Optic currOptic = currDistr->getOptics()[i];
						if (currOptic.getType() == searchOpticType) {
							searchOptic = &currOptic;
							result2 = true;
						}
					}
					if (result) {
						while (quantity <= 0) {
							cout << "Enter desired quantity: ";
							cin >> quantity;
							if (quantity <= 0) {
								cout << "Quantity cannot be 0 or less!";
							}
						}
						totalPrice += (double)(quantity * searchOptic->getMaterial().getPrice());
					}
					else {
						cout << "A distributor with the entered Name doesn't exist!" << endl;
					}
					cout << "If you want to continue shopping choose 1 or if you want to checkout choose 0: " << endl;
					cin >> command;
				}
				cout << "Total money spent: " << totalPrice << endl;
			}
			else {
				cout << "A distributor with the entered Name doesn't exist!" << endl;
			}

			cout << "Operation successfull" << endl;
		}
	}

	return 0;
}