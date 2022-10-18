#pragma once
#include <iostream>
using namespace std;

class Line
{
private:
	int len;
public:
	Line(int _len) {
		len = _len;

		for (int i = 0; i < len; i++)
		{
			cout << "*";
		}

		cout << "\nLine length: " << len;
	}

	~Line() {
		cout << "\n Desructing object Line!\n";
	}
};

