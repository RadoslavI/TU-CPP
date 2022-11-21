#pragma once

using namespace std;

class electoraldistrict
{
	public:
		string* name = new string();
		int electorsCount;
		int partiesCount;
		map<string, int> votes;
};

