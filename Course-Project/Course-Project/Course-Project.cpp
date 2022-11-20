#include <iostream>
#include <fstream>
#include "Course-Project.h"
#include <list>
using namespace std;

class electoralDistrict {
public:
	string* name = new string();
	int electorsCount;
	int partiesCount;
	int* votes = new int(partiesCount);
	char pInitials[];
};

void print(std::list<electoralDistrict> &mylist)
{
	for (auto v : mylist)
		std::cout << &v.name << "\n";
}

int main() {
	electoralDistrict ed1;
	*ed1.name = "Studentski grad";
	ed1.electorsCount = 100;
	ed1.partiesCount = 3;

	electoralDistrict ed2;
	*ed2.name = "Lozenets";
	ed2.electorsCount = 250;
	ed2.partiesCount = 5;
	
	std::list<electoralDistrict> dataSet;
	dataSet.insert(dataSet.begin(), ed1);
	dataSet.insert(dataSet.end(), ed2);

	print(dataSet);


	//Wriring this data to Districts.txt
	ofstream file1;
	file1.open("Districts.txt", ios::out);
	file1.write((char*)&ed1, sizeof(ed1));
	file1.close();
	
	//Reading data from Districts.txt
	ifstream file2;
	file2.open("Districts.txt", ios::in);
	file2.seekg(0);
	file2.read((char*)&ed1, sizeof(ed1));
	

	printf("Name : % s\n", ed1.name->c_str());
	printf("Number of electors : % d\n", ed1.electorsCount);
	printf("Number of parties : % d\n", ed1.partiesCount);
	
	file2.close();
	
	

	return 0;
}

