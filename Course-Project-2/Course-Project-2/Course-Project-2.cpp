#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Library {
	int booksCount;
	vector<char*> titles;
public:
	Library(int _booksCount, vector<char*> _titles)
	{
		booksCount = _booksCount;
		titles = _titles;
	};

	void addTitles() {
		for (int i = 0; i < booksCount; i++)
		{
			cout << "Enter the title for book number " << (i + 1) << endl;
			cin >> titles[i];
		};
	}

	void getTitles(char* outStr) {
		for (int i = 0; i < booksCount; i++) {
			outStr[i] = *titles[i];
		}
	}
};

class Information : public Library {
	bool isAvalible;
	vector<string> authorNames;
	string rentDate;
public: 
	Information(bool iA, vector<string> aN, string rD, int bC, vector<char*> t) : Library(bC, t)
	{
		isAvalible = iA;
		authorNames = aN;
		rentDate = rD;
	}
	friend ostream& operator<<(ostream& os, const Information& dt);
};

ostream& operator<<(ostream& os, const Information& i)
{
	os << "Availability: " << i.isAvalible << '/' << "Number of authors: " << i.authorNames.size() << '/' << "Rented on: " << i.rentDate;

	fstream myfile("BookInformation.txt", ios::app);
	if (myfile.is_open())
	{
		myfile << "Information about the book: " << endl;

		myfile << i.isAvalible << '/' << i.rentDate << endl;
		myfile.close();
	}
	return os;
}