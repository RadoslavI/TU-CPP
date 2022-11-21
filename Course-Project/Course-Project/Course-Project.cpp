#include <iostream>
#include <fstream>
#include "Course-Project.h"
#include <list>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class electoralDistrict {
	string* name = new string();
	int electorsCount;
	int partiesCount;
	map<string, int> votes;
public:
	electoralDistrict(string* _name, int _electorsCount,
		int _partiesCount, map<string, int> _votes)
	{
		name = _name;
		electorsCount = _electorsCount;
		partiesCount = _partiesCount;
		votes = _votes;
	};

	string* getName() {
		return name;
	}

	int getElectorsCount() {
		return electorsCount;
	}

	int getpartiesCount() {
		return partiesCount;
	}

	map<string, int> getVotes() {
		return votes;
	}
};

bool mycomp(electoralDistrict a, electoralDistrict b) {
	//returns 1 if string a is alphabetically 
	//less than string b
	//quite similar to strcmp operation
	return a.getName() < b.getName();
}

void print(vector<electoralDistrict> g1)
{
	//cout << "\nVector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
		cout << *it->getName() << "\n";
}

void writeFile(vector<electoralDistrict> g1)
{
	//Wriring this data to Districts.txt
	for (auto it = g1.begin(); it != g1.end(); it++) {
		ofstream file1;
		file1.open("Districts.txt", ios::app);
		file1.write((char*)&g1, sizeof(g1));
		file1.close();
	}
}

vector<electoralDistrict> seedData()
{
	vector<electoralDistrict> dataSet;

	map<string, int> seedVotes;

	seedVotes.insert(pair<string, int>("Gerb", 10));
	seedVotes.insert(pair<string, int>("pp", 5));
	seedVotes.insert(pair<string, int>("db", 10));

	electoralDistrict ed1((string*) "Studentski grad", 100, 3, seedVotes);
	
	seedVotes.clear();

	seedVotes.insert(pair<string, int>("Gerb", 10));
	seedVotes.insert(pair<string, int>("pp", 30));
	seedVotes.insert(pair<string, int>("db", 0));
	seedVotes.insert(pair<string, int>("Vuzr", 100));
	seedVotes.insert(pair<string, int>("zeleni", 50));

	electoralDistrict ed2((string*) "Luilin", 250, 5, seedVotes);
	
	seedVotes.clear();

	seedVotes.insert(pair<string, int>("Gerb", 40));
	seedVotes.insert(pair<string, int>("pp", 10));
	seedVotes.insert(pair<string, int>("db", 5));
	seedVotes.insert(pair<string, int>("Vuzr", 0));
	seedVotes.insert(pair<string, int>("zeleni", 0));

	electoralDistrict ed3((string*)"Krasno selo", 60, 5, seedVotes);

	dataSet.insert(dataSet.begin(), ed1);
	dataSet.insert(dataSet.end(), ed2);
	dataSet.insert(dataSet.end(), ed3);

	return dataSet;
}

void printResults(vector<electoralDistrict> g1)
{
	cout << "Voting results for all of the districts: \n";
	
	sort(g1.begin(), g1.end(), mycomp);

	for (auto it = g1.begin(); it != g1.end(); it++) {
		
		cout << *it->getName() << ": \n";
		for (auto p = it->getVotes().begin(); p != it->getVotes().end(); p++) {
			int currVotes = p->second;
			int electors = it->getElectorsCount();
			double result = (currVotes / (double) electors);
			cout << p->first << " - " << result << "%" << endl;
		}
		cout << "==============================" << endl;
	}
}

int main() 
{
	vector<electoralDistrict> dataSet;

	int operation;
	cout << "Please select operation: " << endl;
	cin >> operation;

	while (operation != 0) 
	{
		cout << "1) - Seed data" << endl;
		cout << "2) - Create file from objects" << endl;
		cout << "3) - Print vote percentage per region" << endl;
		cout << "4) - Print regions with no winner" << endl;
		cout << "5) - Create a file with the regions with no winner" << endl;
		cout << "0) - Exit" << endl;
		cin >> operation;

		if (operation == 1)
		{
			dataSet = seedData();
		}
		else if (operation == 2) 
		{
			writeFile(dataSet);
		}
		else if (operation == 3) 
		{
			printResults(dataSet);
		}
		else if (operation == 4) 
		{

		}
		else if (operation == 5) 
		{

		}
	}
	


	
	//Reading data from Districts.txt
	/*ifstream file2;
	file2.open("Districts.txt", ios::in);
	file2.seekg(0);
	file2.read((char*)&ed1, sizeof(ed1));*/
	
	//file2.close();

	return 0;
}

