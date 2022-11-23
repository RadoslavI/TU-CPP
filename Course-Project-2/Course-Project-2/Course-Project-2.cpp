#include <iostream>
#include <vector>

using namespace std;

class Library {
	int booksCount;
	char* titles[];
public:
	Library(int _booksCount)
	{
		booksCount = _booksCount;
	};

	void addTitles() {
		for (int i = 0; i < booksCount; i++)
		{
			cout << "Enter the title for book number " << i+1 << endl;
			cin >> titles[i];
		};
	}

	void getTitles(char* outStr) {
		for (int i = 0; i < booksCount; i++) {
			outStr[i] = *titles[i];
		}
	}
};

class Information : Library {
	char* authorNames[];
	bool isAvalible;

};