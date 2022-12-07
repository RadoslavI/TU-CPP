#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <iostream>

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

class Library {
public:
	char* titles[100];
	int titlesCount;
	Library(int _titlesCount, char* _titles[])
	{
		titlesCount = _titlesCount;

		for (int i = 0; i < titlesCount; i++)
		{
			int sizeOfText = strlen(_titles[i]) + 1;

			// Dynamically allocate the correct amount of memory.
			titles[i] = new char[sizeOfText];

			// If the allocation succeeds, copy the initialization string.
			if (titles[i])
				titles[i] = _titles[i];
		};
	};

	vector<string> getTitles()
	{
		vector<string> output;

		for (int i = 0; i < titlesCount; i++)
		{
			output.insert(output.end(), (string)titles[i]);
		}

		return output;
	}
};

class Information : public Library 
{
	bool isAvailable;
	vector<string> authorNames;
	string rentDate;
public: 
	Information(bool iA, vector<string> aN, string rD, int bC, char* t[]) : Library(bC, t)
	{
		isAvailable = iA;
		authorNames = aN;
		rentDate = rD;
	}
	friend ostream& operator<<(ostream& os, const Information& dt);

	bool getIsAvailable()
	{
		return isAvailable;
	}

	vector<string> getAuthorNames()
	{
		return authorNames;
	}

	string getRentDate()
	{
		return rentDate;
	}
};

ostream& operator<<(ostream& os, const Information& i)
{
	os << "Availability: " << i.isAvailable << '/' << "Number of authors: " << i.authorNames.size() << '/' << "Rented on: " << i.rentDate;

	fstream myfile("BookInformation.txt", ios::app);
	if (myfile.is_open())
	{
		myfile << "Information about the book: " << endl;
		myfile << i.isAvailable << '/' << i.rentDate << endl;
		myfile << "Authors: " << endl;

		for (int n = 0; n < i.authorNames.size(); n++) 
		{
			myfile << i.authorNames[n] << endl;
		}

		myfile.close();
	}

	return os;
}

bool mycomp(string a, string b) {
	//returns 1 if string a is alphabetically 
	//less than string b
	//quite similar to strcmp operation
	return a < b;
}

void availabilityInfo(vector<Information> books)
{
	//vector<Information> currBooks = *books;

	for (int i = 0; i < books.size(); i++)
	{
		Information currBook = books[i];
		if (currBook.getIsAvailable())
		{
			vector<string> currAuthorNames = currBook.getAuthorNames();
			sort(currAuthorNames.begin(), currAuthorNames.end(), mycomp);

			cout << "Information about the book: " << endl;
			cout << "Availability: " << currBook.getIsAvailable() << '/' << currBook.getRentDate() << endl;
			cout << "Authors: " << endl;

			for (int n = 0; n < currAuthorNames.size(); n++)
			{
				cout << currAuthorNames[n] << endl;
			}
		}
	}
}

void getBooksOnDate(vector<Information> books, string date)
{
	for (int i = 0; i < books.size(); i++)
	{
		Information currBook = books[i];
		if (currBook.getRentDate() == date)
		{
			for (int n = 0; n < currBook.titlesCount; n++)
			{
				cout << currBook.titles[n] << endl;
			}
		}
	}
}

void writeInFileWithMoreAuthors(vector<Information> books)
{
	for (int i = 0; i < books.size(); i++)
	{
		Information currBook = books[i];
		vector<string> currAuthorNames = currBook.getAuthorNames();

		if (currAuthorNames.size() > 1)
		{
			cout << currBook;
		}
	}
}

int main() 
{
	vector<Information> books;

	vector<string> authors1 = { "Gosho", "Ivan" };
	vector<string> authors2 = { "Ivan Vazov" };
	vector<string> authors3 = { "Toshko", "Nikola" };

	char* titles1[] = { (char*)"Igra na glada", (char*)"Mecho puh" };
	char* titles2[] = { (char*)"Pod Igoto"};
	char* titles3[] = { (char*) "Sukrovishteto", (char*) "Learn C++ for beginers" };

	Information book1(true, authors1, "10.10.2022", 2, titles1);
	Information book2(true, authors2, "12.10.2022", 1, titles2);
	Information book3(true, authors3, "10.10.2022", 2, titles3);
	
	books.insert(books.begin(), book1);
	books.insert(books.end(), book2);
	books.insert(books.end(), book3);

	cout << "Calling avalibility info" << endl;
	availabilityInfo(books);

	cout << "Calling books on data" << endl;
	getBooksOnDate(books, "10.10.2022");

	cout << "Calling file writting" << endl;
	writeInFileWithMoreAuthors(books);

	return 0;
}