#include <iostream>
#include <fstream>
#include "Course-Project.h"
using namespace std;

class electoralDistrict {
public:
	string* name = new string();
	int electorsCount;
	int partiesCount;
	int* votes = new int(partiesCount);
	char pInitials[];
};

int main() {
	electoralDistrict eD_1;
	*eD_1.name = "Studentski grad";
	eD_1.electorsCount = 100;
	eD_1.partiesCount = 3;
	
	//Wriring this data to Districts.txt
	ofstream file1;
	file1.open("Districts.txt", ios::out);
	file1.write((char*)&eD_1, sizeof(eD_1));
	file1.close();
	
	//Reading data from Districts.txt
	ifstream file2;
	file2.open("Districts.txt", ios::in);
	file2.seekg(0);
	file2.read((char*)&eD_1, sizeof(eD_1));
	

	printf("Name : % s\n",eD_1.name->c_str());
	printf("Number of electors : % d\n",eD_1.electorsCount);
	printf("Number of parties : % d\n",eD_1.partiesCount);
	
	file2.close();
	
	return 0;
}