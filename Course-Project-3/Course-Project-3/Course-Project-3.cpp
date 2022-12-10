#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <list>
#include <map>
#include <iomanip>

using namespace std;

class Date {
	int day;
	int month;
	int year;
public:
	Date() {
		this->day = 1;
		this->month = 1;
		this->year = 1999;
	}

	Date(int d, int m, int y) {
		this->day = d;
		this->month = m;
		this->year = y;
	}

	void setDay(int d) {
		if (d > 0 && d < 31) {
			this->day = d;
		}
		else {
			cout << "Please enter a valid day!" << endl;
		}
	}

	int getDay() {
		return this->day;
	}

	void setMonth(int m) {
		if (m > 0 && m < 12) {
			this->month = m;
		}
		else {
			cout << "Please enter a valid month!" << endl;
		}
	}

	int getMonth() {
		return this->month;
	}

	void setYear(int y) {
		if (y > 0) {
			this->year = y;
		}
		else {
			cout << "Please enter a valid year!" << endl;
		}
	}

	int getYear() {
		return this->year;
	}
};

class Student {
	string name;
	int facultyNum;
	Date birthdate;
	double avgScore;
public:
	Student() {
		this->name = "Default constructor";
		this->facultyNum = 1;
		this->birthdate = Date();
		this->avgScore = 6;
	}

	Student(string n, int fn, Date bd, double as) {
		this->name = n;
		this->facultyNum = fn;
		this->birthdate = bd;
		this->avgScore = as;
	}

	void setName(string n) {
		this->name = n;
	}

	string getName() {
		return this->name;
	}

	void setFacultyNum(int fn) {
		this->facultyNum = fn;
	}

	int getFacultyNum() {
		return this->facultyNum;
	}

	void setAvgScore(int as) {
		this->avgScore = as;
	}

	int getAvgScore() {
		return this->avgScore;
	}

	void setBirthdate(int d, int m, int y) {
		this->birthdate.setDay(d);
		this->birthdate.setMonth(m);
		this->birthdate.setYear(y);
	}

	Date getBirthdate() {
		return this->birthdate;
	}

	int calcAge(Date _date) {
		int currDay = _date.getDay();
		int currMonth = _date.getMonth();
		int currYear = _date.getYear();
		int result = 0;

		if (this->birthdate.getYear() < currYear) {
			result = currYear - this->birthdate.getYear();

			if (this->birthdate.getMonth() > currMonth) {
				result -= 1;
			}
			else if (this->birthdate.getMonth() == currMonth){
				if (this->birthdate.getDay() > currDay) {
					result -= 1;
				}
			}
		}

		return result;
	}
};

class StudentStream {
public:
	StudentStream() {};

	vector<Student> students;

	Student getExellent() {
		Student currMax;
		currMax.setAvgScore(0);
		for (int i = 0; i < this->students.size(); i++)
		{
			if (students[i].getAvgScore() > currMax.getAvgScore()) {
				currMax = students[i];
			}
		}

		return currMax;
	}

	friend ostream& operator<<(ostream& os, const StudentStream& dt);
};

ostream& operator<<(ostream& os, const StudentStream& ss)
{
	
	fstream myfile("StudentsInfo.txt", ios::app);
	if (myfile.is_open()) {
		os << "Students with age between 18 and 26: " << endl;
		myfile << "Students with age between 18 and 26: " << endl;
		for (int i = 0; i < ss.students.size(); i++)
		{
			Student currStudent = ss.students[i];
			if (currStudent.calcAge(Date(10, 12, 2022)) >= 18 &&
				currStudent.calcAge(Date(10, 12, 2022)) <= 26) {
				os << currStudent.getName() << endl;
				myfile << currStudent.getName() << endl;
			}
		}

		myfile.close();
	}
	
	return os;
}

int main()
{
	StudentStream stream;

	Student st1("Ivan", 10102020, Date(10, 5, 1999), 3.97);
	Student st2("Gosho", 10102021, Date(15, 7, 2001), 4.23);
	Student st3("Pesho", 10102022, Date(1, 1, 2014), 5.99);

	stream.students.insert(stream.students.begin(), st1);
	stream.students.insert(stream.students.begin(), st2);
	stream.students.insert(stream.students.begin(), st3);

	cout << "The student with the highest score is: " << endl;
	cout << stream.getExellent().getName() << endl;

	cout << stream;

	return 0;
}