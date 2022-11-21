#include <iostream>
#include <fstream>
#include "Course-Project.h"
#include <list>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class electoralDistrict {
public:
	string* name = new string();
	int electorsCount;
	int partiesCount;
	map<string, int> votes;
};

bool mycomp(electoralDistrict a, electoralDistrict b) {
	//returns 1 if string a is alphabetically 
	//less than string b
	//quite similar to strcmp operation
	return a.name < b.name;
}

void print(vector<electoralDistrict> g1)
{
	//cout << "\nVector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
		cout << *it->name << "\n";
}

void printResults(vector<electoralDistrict> g1)
{
	cout << "Voting results for all of the districts: \n";
	
	sort(g1.begin(), g1.end(), mycomp);

	for (auto it = g1.begin(); it != g1.end(); it++) {
		
		cout << *it->name << ": \n";
		for (auto p = it->votes.begin(); p != it->votes.end(); p++) {
			int currVotes = p->second;
			int electors = it->electorsCount;
			double result = (currVotes / (double) electors);
			cout << p->first << " - " << result << "%" << endl;
		}
		cout << "==============================" << endl;
	}
}

int main() {
	electoralDistrict ed1;
	*ed1.name = "Studentski grad";
	ed1.electorsCount = 100;
	ed1.partiesCount = 3;
	ed1.votes.insert(pair<string, int>("Gerb", 10));
	ed1.votes.insert(pair<string, int>("pp", 5));
	ed1.votes.insert(pair<string, int>("db", 10));

	electoralDistrict ed2;
	*ed2.name = "ALozenets";
	ed2.electorsCount = 250;
	ed2.partiesCount = 5;
	ed2.votes.insert(pair<string, int>("Gerb", 10));
	ed2.votes.insert(pair<string, int>("pp", 30));
	ed2.votes.insert(pair<string, int>("db", 0));
	ed2.votes.insert(pair<string, int>("Vuzr", 100));
	ed2.votes.insert(pair<string, int>("zeleni", 50));
	
	vector<electoralDistrict> dataSet;
	dataSet.insert(dataSet.begin(), ed1);
	dataSet.insert(dataSet.end(), ed2);

	printResults(dataSet);


	//Wriring this data to Districts.txt
	ofstream file1;
	file1.open("Districts.txt", ios::out);
	file1.write((char*)&ed1, sizeof(ed1));
	file1.close();
	
	//Reading data from Districts.txt
	/*ifstream file2;
	file2.open("Districts.txt", ios::in);
	file2.seekg(0);
	file2.read((char*)&ed1, sizeof(ed1));*/
	

	printf("Name : % s\n", ed1.name->c_str());
	printf("Number of electors : % d\n", ed1.electorsCount);
	printf("Number of parties : % d\n", ed1.partiesCount);
	
	//file2.close();
	
	

	return 0;
}

