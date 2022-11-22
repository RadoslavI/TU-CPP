#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

class electoralDistrict {
	char *name;
	int electorsCount;
	int partiesCount;
public:
	map<string, int> votes;

	electoralDistrict(char *_name, int _electorsCount,
		int _partiesCount, map<string, int> _votes)
	{
		int sizeOfText = strlen(_name) + 1;

		// Dynamically allocate the correct amount of memory.
		name = new char[sizeOfText];

		// If the allocation succeeds, copy the initialization string.
		if (name)
			strcpy_s(name, sizeOfText, _name);

		electorsCount = _electorsCount;
		partiesCount = _partiesCount;
		votes = _votes;
	};

	char* getName() {
		return name;
	}

	int getElectorsCount() {
		return electorsCount;
	}

	int getpartiesCount() {
		return partiesCount;
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
		cout << it->getName() << "\n";
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

void printResults(vector<electoralDistrict> g1)
{
	cout << "Voting results for all of the districts: \n";
	
	sort(g1.begin(), g1.end(), mycomp);

	for (auto it = g1.begin(); it != g1.end(); it++) {
		
		cout << it->getName() << ": \n";
		for (auto p = it->votes.begin(); p != it->votes.end(); p++) {
			int currVotes = p->second;
			int electors = it->getElectorsCount();
			double result = (currVotes / (double) electors);
			cout << p->first << " - " << result << "%" << endl;
		}
		cout << "==============================" << endl;
	}
}

int findEntryWithLargestValue(
	map<string, int> sampleMap)
{

	// Reference variable to help find
	// the entry with the highest value
	int entryWithMaxValue
		= 0;

	// Iterate in the map to find the required entry
	map<string, int>::iterator currentEntry;
	for (currentEntry = sampleMap.begin();
		currentEntry != sampleMap.end();
		++currentEntry) {

		// If this entry's value is more
		// than the max value
		// Set this entry as the max
		if (currentEntry->second
	> entryWithMaxValue) {

			entryWithMaxValue = currentEntry->second;
		}
	}

	return entryWithMaxValue;
}

void printNoWinnerReg(vector<electoralDistrict> g1, int operation)
{
	cout << "Districts with no winners: \n";

	for (auto it = g1.begin(); it != g1.end(); it++) {
		int maxVotes = findEntryWithLargestValue(it->votes);
		int numberOfMax = 0;
		int totalVotes = 0;

		for (auto p = it->votes.begin(); p != it->votes.end(); p++)
		{
			int currVotes = p->second;
			totalVotes += currVotes;
			if (currVotes == maxVotes) {
				numberOfMax++;
			}
		}

		if (numberOfMax != 1) {

			if (operation != 1)
			{
				cout << it->getName() << endl;
			}

			else if (operation == 1) 
			{
				ofstream myfile("NoWinnersList.txt", ios::app);
				if (myfile.is_open())
				{
					
					double value = (it->getElectorsCount() - totalVotes) 
						/ (double)it->getElectorsCount();
					
					cout << it->getName() << " - " << value << "%" << endl;

					myfile << std::fixed;
					myfile << std::setprecision(2);
					myfile << it->getName() << " - " << value << "%" << endl;
					myfile.close();
				}
			}
			cout << "==============================" << endl;
		}
	}
}


int main() 
{
	cout << std::fixed;
	cout << std::setprecision(2);

	vector<electoralDistrict> dataSet;

	map<string, int> seedVotes;

	seedVotes.insert(pair<string, int>("Gerb", 10));
	seedVotes.insert(pair<string, int>("pp", 5));
	seedVotes.insert(pair<string, int>("db", 10));

	electoralDistrict ed1((char*) "Studentski grad", 100, 3, seedVotes);

	seedVotes.clear();

	seedVotes.insert(pair<string, int>("Gerb", 10));
	seedVotes.insert(pair<string, int>("pp", 30));
	seedVotes.insert(pair<string, int>("db", 0));
	seedVotes.insert(pair<string, int>("Vuzr", 100));
	seedVotes.insert(pair<string, int>("zeleni", 50));

	electoralDistrict ed2((char*) "Luilin", 250, 5, seedVotes);

	seedVotes.clear();

	seedVotes.insert(pair<string, int>("Gerb", 25));
	seedVotes.insert(pair<string, int>("pp", 25));
	seedVotes.insert(pair<string, int>("db", 5));
	seedVotes.insert(pair<string, int>("Vuzr", 0));
	seedVotes.insert(pair<string, int>("zeleni", 0));

	electoralDistrict ed3((char*) "Krasno selo", 60, 5, seedVotes);

	dataSet.insert(dataSet.begin(), ed1);
	dataSet.insert(dataSet.end(), ed2);
	dataSet.insert(dataSet.end(), ed3);

	int operation = -1;

	while (operation != 0) 
	{
		cout << "Please select an operation: " << endl;
		cout << "1) - Create file from objects" << endl;
		cout << "2) - Print vote percentage per region" << endl;
		cout << "3) - Print regions with no winner" << endl;
		cout << "4) - Create a file with the regions with no winner" << endl;
		cout << "0) - Exit" << endl;
		cin >> operation;

		if (operation == 1)
		{
			writeFile(dataSet);
			cout << "Operation successfull" << endl;
		}
		else if (operation == 2) 
		{
			printResults(dataSet);
			cout << "Operation successfull" << endl;
		}
		else if (operation == 3) 
		{
			printNoWinnerReg(dataSet, 0);
			cout << "Operation successfull" << endl;
		}
		else if (operation == 4) 
		{
			printNoWinnerReg(dataSet, 1);
			cout << "Operation successfull" << endl;
		}
	}

	return 0;
}

