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
	int booksCount;
	char* titles[100];
public:
	Library(int _booksCount)
	{
		booksCount = _booksCount;
		titles[1] = (char*) "default";
	};

	void addTitles(vector<char*> input)
	{
		for (int i = 0; i < input.size(); i++)
		{
			int sizeOfText = sizeof(input[i]) + 1;

			// Dynamically allocate the correct amount of memory.
			titles[i] = new char[sizeOfText];

			// If the allocation succeeds, copy the initialization string.
			if (titles[i])
				titles[i] = input[i];
		};
	}

	vector<char> getTitles()
	{
		vector<char> output;

		for (int i = 0; i < booksCount; i++) 
		{
			output[i] = *titles[i];
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
	Information(bool iA, vector<string> aN, string rD, int bC) : Library(bC)
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
	for (int i = 0; i < books.size(); i++)
	{
		Information currBook = books[i];
		if (currBook.getIsAvailable())
		{
			sort(currBook.getAuthorNames().begin(), currBook.getAuthorNames().end(), mycomp);

			cout << "Information about the book: " << endl;
			cout << currBook.getIsAvailable() << '/' << currBook.getRentDate() << endl;
			cout << "Authors: " << endl;

			for (int n = 0; n < currBook.getAuthorNames().size(); n++)
			{
				cout << currBook.getAuthorNames()[n] << endl;
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
			for (int n = 0; n < currBook.getAuthorNames().size(); n++)
			{
				cout << currBook.getTitles()[n] << endl;
			}
		}
	}
}

void writeInFileWithMoreAuthors(vector<Information> books)
{
	for (int i = 0; i < books.size(); i++)
	{
		Information currBook = books[i];
		if (currBook.getAuthorNames().size() > 1)
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

	vector<char *> titles1 = { (char*) "Igra na glada", (char*) "Mecho puh" };
	vector<char *> titles2(1);
	titles2.insert(titles2.begin(), (char*) "Pod Igoto");
	vector<char *> titles3 = { (char*) "Sukrovishteto", (char*) "Learn C++ for beginers" };

	Information book1(true, authors1, "10.10.2022", 2);
	book1.addTitles(titles1);
	Information book2(true, authors2, "12.10.2022", 1);
	book2.addTitles(titles2);
	Information book3(true, authors3, "10.10.2022", 2);
	book3.addTitles(titles3);
	
	books.insert(books.begin(), book1);
	books.insert(books.end(), book2);
	books.insert(books.end(), book3);

	availabilityInfo(books);

	getBooksOnDate(books, "10.10.2022");

	writeInFileWithMoreAuthors(books);

	return 0;
}