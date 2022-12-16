#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <map>
using namespace std;

class Date {
    //creates private fields for class Date
private:
    int day;
    int month;
    int year;

public:
    //declares default constructor
    Date();
    //declares constructor that accepts and sets the fields
    Date(int day, int month, int year);
    //declares getters and setters
    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);
};
//sets the fields via the constructor
Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date::Date() {}
//getters and setters with set and return functionality
int Date::getDay() const {
    return this->day;
}

void Date::setDay(int day) {
    if (day < 31 && day >= 0)
    {
        this->day = day;
    }

}

int Date::getMonth() const {
    return this->month;
}

void Date::setMonth(int month) {
    if (month <= 12 && month > 0)
    {
        this->month = month;
    }

}

int Date::getYear() const {
    return this->year;
}

void Date::setYear(int year) {
    this->year = year;
}

//delcares Appointment class
class Appointment {
    //delacres private fields
private:
    char* name;
    size_t egn;
    Date appointmentDate;
    
    std::vector<string> previousIllness;
    std::vector<string> complaints;
    string medicine;


public:
    //premestih go da e public, zashtoto nqma get i set, 
    //a trqbva da ima dostup v main metoda
    //ako durjish mojesh da gi napravish ako ne i taka stava
    string illness;
    Appointment();
    //declaration on both default and constructor with filed set functionality
    Appointment(char* name, size_t egn, const Date& appointmentDate, const string& illness,
        const vector<string>& previousIllness, const vector<string>& complaints, const string& medicine);
    
    
    //declares opperator override
    friend std::ostream& operator<<(std::ostream& out, const Appointment& appointment);
    //declares the needed methods
    void lastMonthPatients();

    void patientsWithComplaints();

    void mostCommonIllness();

};

Appointment::Appointment() {}
//writes functionality of both constructors

Appointment::Appointment(char* name, size_t egn, const Date& appointmentDate, const string& illness,
    const vector<string>& previousIllness, const vector<string>& complaints,
    const string& medicine) : name(name), egn(egn), appointmentDate(appointmentDate),
    illness(illness), previousIllness(previousIllness),
    complaints(complaints), medicine(medicine) {}

//writes functionality of the operator <<
std::ostream& operator<<(std::ostream& out, const Appointment& appointment) {
    out << appointment.name << "\n";
    out << appointment.egn << "\n";
    out << appointment.appointmentDate.getDay() << "\n";
    out << appointment.appointmentDate.getMonth() << "\n";
    out << appointment.appointmentDate.getYear() << "\n";

    out << "{\n";
    for (size_t i = 0; i < appointment.previousIllness.size(); i++) {
        out << '\t' << appointment.previousIllness.at(i) << " - ";
        out << appointment.complaints.at(i) << '\n';
    }
    out << "}\n";


    return out;
}

void Appointment::lastMonthPatients() {
    //checks if the current month is 12 and year 2022 using the getters
    if (appointmentDate.getMonth() == 12 && appointmentDate.getYear() == 2022) {
        //prints the fields
        cout << "----------------------------------\r\n";
        cout << "Name: " << name << endl;
        cout << "Egn: " << egn << endl;
        cout << "Illness: " << illness << endl;
        //prints complaints
        for (const auto& i : complaints) {
            cout << "Complaints: " << i << endl;
        }
        cout << "Medicine: " << medicine << endl;
        cout << "Date: " << appointmentDate.getDay() << "." << appointmentDate.getDay() << "."
            << appointmentDate.getDay() << endl;
    }

}

void Appointment::patientsWithComplaints() {
    //for cycle of all complaints
    for (size_t i = 0; i < complaints.size(); i++) {
        //checks if it isn't empty
        if (!complaints.at(i).empty()) {
            cout << "----------------------------------\r\n";
            cout << "Name: " << name << endl;
            cout << "Egn: " << egn << endl;
            cout << "Illness: " << illness << endl;
            for (const auto& i : complaints) {
                cout << "Complaints: " << i << endl;
            }
            cout << "Medicine: " << medicine << endl;
            cout << "Date: " << appointmentDate.getDay() << "." << appointmentDate.getMonth() << "."
                << appointmentDate.getYear() << endl;
        }
    }
}

void Appointment::mostCommonIllness() {

}

int main() {


    //vector<Appointment> appointments;
    //hardcoded elements for testing purposes
    /*Date date1;
    date1.setDay(21);
    date1.setMonth(12);
    date1.setYear(2022);
    Date date2;
    date2.setDay(11);
    date2.setMonth(11);
    date2.setYear(2022);
    Date date3;
    date3.setDay(11);
    date3.setMonth(11);
    date3.setYear(2022);*/

    //creates a vector of Appointments and fills it with data
    //with Date, vectors containing complaints and appointments 
    vector<Appointment> appointments;
    Date date1(1, 11, 2022);
    vector<string> previousIllnesses = { "bolest","bolest1","bolest2" };
    vector<string>complaints = { "cm","cm1","cm2" };
    Appointment appointment1((char*)"name1", 123, date1, "nqkakva bolest", previousIllnesses, complaints, "medicine");
    appointments.push_back(appointment1);

    //vector<Appointment> appointments;
    Date date2(1, 12, 2022);
    vector<string> previousIllnesses2 = { "bolest","bolest1","bolest2" };
    vector<string>complaints2 = { "cm11","cm12","cm23" };
    Appointment appointment2((char*)"name2", 2345, date2, "nqkakva bolest", previousIllnesses2, complaints2, "medicine");
    appointments.push_back(appointment2);


    //vector<Appointment> appointments;
    Date date3(1, 12, 2022);
    vector<string> previousIllnesses3 = { "bolest","bolest1","bolest2" };
    vector<string>complaints3 = { "cm3","cm13","cm23" };
    Appointment appointment3((char*)"name3", 345, date3, "nqkakva bolest3", previousIllnesses3, complaints3, "medicine");
    appointments.push_back(appointment3);


    //adding everything in file
    ofstream file("appointments.txt");
    if (!file.is_open()) {
        cerr << "error open file\n";
    }

    for (size_t i = 0; i < appointments.size(); i++) {
        file << appointments[i];
    }
    cout << endl;
    cout << "________________________________\n";


    cout << "________________________________\n";
    cout << "Appointments for the last month\n";
    //prints all last month patients
    for (size_t i = 0; i < appointments.size(); i++) {
        Appointment* currAppointment = &appointments[i];
        currAppointment->lastMonthPatients();
    }
    cout << endl;
    cout << "________________________________\n";

    cout << "________________________________\n";
    cout << "Patients with Complaints\n";
    //prints all patients with complaints
    for (size_t i = 0; i < appointments.size(); i++) {
        appointments[i].patientsWithComplaints();
    }
    cout << endl;
    cout << "________________________________\n";

    cout << "________________________________\n";
    cout << "Most Common Illness\n";
    int counter = 1;
    //creates map that will hold illness name and count
    map<string, int> numOfEachIllness;
    //тука е < appointmentssize() - 1 защото като стигне до 
    //последният елемент илзиза от vectora и дава грешка
    for (size_t i = 0; i < appointments.size() - 1; i++) {
        //pravq vremenni promenlivi ot tip Appointment pointer
        //zashtoto taka iska tupoto c++ xD
        Appointment* currAppointment = &appointments[i];
        Appointment* nextAppointment = &appointments[i + 1];
        if (currAppointment->illness == nextAppointment->illness) {
            counter++;
            numOfEachIllness.insert(pair<string, int>(currAppointment->illness, counter));
        }
    }
    //prints the most common illness
    for (auto it = numOfEachIllness.cbegin(); it != numOfEachIllness.cend(); ++it)
    {
        std::cout << it->first << " " << it->second << " " << "\n";
    }
    cout << endl;
    cout << "________________________________\n";

    return 0;
}
