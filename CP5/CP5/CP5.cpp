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
	void setName(string n){
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

	void setMaterial(string m) {
		material.setName(m);
	}

	string getMaterial() {
		return material.getName();
	}
};

class Deliverer 
{
	string bulstat;
	string name;
	string location;
	string phone;
public:
	vector<Optic> optics;
	Deliverer()
	{
		bulstat = "default bulstat";
		name = "default name";
		location = "Sofia";
		phone = "+359999999";
		optics.push_back(Optic());
	}

	Deliverer(string b, string n, string l, string p, vector<Optic> op)
	{
		bulstat = b;
		name = n;
		location = l;
		phone = p;
		optics = op;
	}

	void getBulstat(string b) {
		bulstat = b;
	}
	string setBulstat() {
		return bulstat;
	}

	void getName(string n) {
		name = n;
	}
	string setName() {
		return name;
	}
	void getLocation(string l) {
		location = l;
	}
	string setLocation() {
		return location;
	}
	void getPhone(string p) {
		phone = p;
	}
	string setPhone() {
		return phone;
	}


	friend ostream& operator<<(ostream& os, const Deliverer& d);
};

ostream& operator<<(ostream& os, const Deliverer& d)
{

	fstream myfile("DelivererInfo.txt", ios::app);
	if (myfile.is_open()) {
		os << "Deliverer info: " << endl;
		myfile << "Deliverer info: " << endl;
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
			os << currOptic.getMaterial() << endl;
			myfile << currOptic.getMaterial() << endl;
		}
		myfile.close();
	}
	return os;
}