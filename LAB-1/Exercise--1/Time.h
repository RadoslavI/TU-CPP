#pragma once
#include <iostream>
using namespace std;

class Time
{
private:
	int hour, minutes, seconds, hourAM;
	string AMPM;
public:
	Time()
	{
		cout << " Enter hour, minutes, seconds: " << endl;
		cin >> hour >> minutes >> seconds;

		if (hour > 12) {
			hourAM = hour - 12;
			AMPM = "PM";
		}
		else {
			hourAM = hour;
			AMPM = "AM";
		}
	}

	void print()
	{
		if (hour > 0 && hour < 24 && minutes > 0 && minutes < 60 && seconds > 0 && seconds < 60) {
			cout << "Time in normal format: "<<hour<<":"<<minutes<<":"<<seconds<<endl;

			cout << "Time in AM/PM format: "<<hourAM<<":"<<minutes<<":"<<seconds<<" "<<AMPM<<endl;
		}

		else {
			cout << "Invalid time!";
		}
		
	}

	~Time() {
		cout << "\n Desructing object Time!\n";
	}
};