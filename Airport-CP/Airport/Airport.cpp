#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class PlaneClass {
private:
    string manufacturer;
    string model;
    int seats;
    int minRunwayLength;
    double tankCapacity;
    double averageSpeed;
public:
    // Default constructor
    PlaneClass() : manufacturer(""), model(""),
        seats(), minRunwayLength(), tankCapacity(), averageSpeed() {}

    // Parameterized constructor
    PlaneClass(string const& m, string const& md, 
        int s, int mrl, double t, double a) : 
        manufacturer(m), model(md), seats(s), 
        minRunwayLength(mrl), tankCapacity(t), averageSpeed(a){}

    //Getter methods
    string getManufacturer() const {
        return manufacturer;
    }

    string getModel() const {
        return model;
    }

    int getSeats() const {
        return seats;
    }

    int getMinRunwayLength() const {
        return minRunwayLength;
    }

    double getTankCapacity() const {
        return tankCapacity;
    }

    double getAverageSpeed() const {
        return averageSpeed;
    }

    //Setter methods
    void setManufacturer(string const& manufacturer) {
        this->manufacturer = manufacturer;
    }

    void setModel(string const& model) {
        this->model = model;
    }

    void setSeats(int seats) {
        if (seats > 0) {
            this->seats = seats;
        }
        else {
            cout << "Seats must be greater than 0!";
        }
    }

    void setMinRunwayLength(int minRunwayLength) {
        if (minRunwayLength > 0) {
            this->minRunwayLength = minRunwayLength;
        }
        else {
            cout << "Runway length must be greater than 0!";
        }
    }

    void setTankCapacity(double tankCapacity) {
        if (tankCapacity > 0) {
            this->tankCapacity = tankCapacity;
        }
        else {
            cout << "Tank capacity must be greater than 0!";
        }
    }

    void setAverageSpeed(double averageSpeed) {
        if (tankCapacity > 0) {
            this->averageSpeed = averageSpeed;
        }
        else {
            cout << "Average speed must be greater than 0!";
        }
    }
};

class Plane {
private:
    string id;
    PlaneClass pclass;

public:
    // Default constructor
    Plane() {}

    // Parameterized constructor
    Plane(string const& id, PlaneClass const& pclass) {
        this->id = id;
        this->pclass = pclass;
    }

    // Getter methods
    string getId() const {
        return id;
    }

    const PlaneClass& getPlaneClass() const {
        return pclass;
    }

    // Setter methods
    void setId(string const& id) {
        this->id = id;
    }

    void setPlaneClass(PlaneClass const& pclass) {
        this->pclass = pclass;
    }
};

class Flight {
private:
    string destination;
    double distance;
    double fuelConsumptionKM;
    double crewCost;
    double fuelCost;
public:
    // Default constructor
    Flight() : distance(), fuelConsumptionKM(),
        crewCost(), fuelCost() {}

    // Parameterized constructor
    Flight(string const& d, double dst, double fc, double cc)
    : destination(d), distance(dst), fuelConsumptionKM(fc), 
        crewCost(cc), fuelCost(distance * fc){}

    // Getter methods
    string getDestination() const {
        return destination;
    }

    double getDistance() const {
        return distance;
    }

    double getFuelConsumptionKM() const {
        return fuelConsumptionKM;
    }

    double getCrewCost() const {
        return crewCost;
    }

    double getFuelCost() const {
        return fuelCost;
    }

    // Setter methods
    void setDestination(string const& d) {
        this->destination = d;
    }

    void setDistance(double d) {
        if (distance > 0) {
            this->distance = d;
        }
        else {
            cout << "Distance must be greater than 0!";
        }
    }

    void setFuelConsumptionKM(double fuelConsumption) {
        if (fuelConsumption > 0) {
            this->fuelConsumptionKM = fuelConsumption;
        }
        else {
            cout << "Fuel consumption must be greater than 0!";
        }
    }

    void setCrewCost(double crewCost) {
        
        if (crewCost >= 0) {
            this->crewCost = crewCost;
        }
        else {
            cout << "Crew cost cannot be a negative number!";
        }
    }

    double calculateMaxDistance(double tankCapacity) const {
        return tankCapacity / this->fuelConsumptionKM;
    }
};

std::ostream& operator<<(std::ostream& os, const Plane& p)
{
    // Print out the plane id
    os << "Plane ID: ";
    os << p.getId() << endl;
    os << "===============" << endl;
    PlaneClass const& pClass = p.getPlaneClass();

    // Print out the plane class info
    os << "Class info: ";
    os << "Manufacturer: " << pClass.getManufacturer() << endl;
    os << "Model: " << pClass.getModel() << endl;
    os << "Avarage speed: " << pClass.getAverageSpeed() << endl;
    os << "Minimum runway length: " << pClass.getMinRunwayLength() << endl;
    os << "Seat capacity: " << pClass.getSeats() << endl;
    os << "Tank capacity: " << pClass.getTankCapacity() << endl;

    return os;
}
void SavePlane(const Plane& p){
    // Write data to a file
    PlaneClass const& pClass = p.getPlaneClass();
    std::ofstream file;
    file.open("plane.txt", std::ios_base::app);
    if (file.is_open()) {
        file << "Plane ID: ";
        file << p.getId() << endl;
        file << "===============" << endl;

        file << "Class info: ";
        file << "Manufacturer: " << pClass.getManufacturer() << endl;
        file << "Model: " << pClass.getModel() << endl;
        file << "Avarage speed: " << pClass.getAverageSpeed() << endl;
        file << "Minimum runway length: " << pClass.getMinRunwayLength() << endl;
        file << "Seat capacity: " << pClass.getSeats() << endl;
        file << "Tank capacity: " << pClass.getTankCapacity() << endl;

        //Close the file
        file.close();
    }
}

int main() {
    vector<PlaneClass> classes;
    classes.emplace_back("Boeing", "747", 416, 10500, 216860, 917);
    classes.emplace_back("Airbus", "A380", 853, 12000, 320000, 945);

    const PlaneClass pclass1 = classes[0];
    const PlaneClass pclass2 = classes[1];

    vector<Plane> planes;
    planes.emplace_back("1", pclass1);
    planes.emplace_back("2", pclass2);

    vector<Flight> flights;
    flights.emplace_back("New York", 7500, 2.7, 5000);
    flights.emplace_back("London", 5600, 2.5, 4000);
    flights.emplace_back("Tokyo", 10000, 3.1, 6000);

    int choice = -1;
    do {
        cout << "Please choose an option:" << endl;
        cout << "1. View list of planes" << endl;
        cout << "2. Add a plane" << endl;
        cout << "3. Remove a plane" << endl;
        cout << "4. View list of flights" << endl;
        cout << "5. Add a flight" << endl;
        cout << "6. Remove a flight" << endl;
        cout << "7. Search planes with enough fuel to reach a destination and write result into a file" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "List of planes:" << endl;
            for (Plane plane : planes) {
                cout << plane << endl;
            }
            break;
        case 2: {
            string id;
            cout << "Enter plane ID: ";
            cin >> id;
            
            string manufacturer;
            string model;
            int seats;
            int minRunwayLength;
            double tankCapacity;
            double averageSpeed;

            cout << "Enter plane class details:" << endl;
            cout << "Manufacturer: ";
            cin >> manufacturer;
            cout << "Model: ";
            cin >> model;
            cout << "Number of seats: ";
            cin >> seats;
            cout << "Minimum runway length required: ";
            cin >> minRunwayLength;
            cout << "Tank capacity: ";
            cin >> tankCapacity;
            cout << "Average speed: ";
            cin >> averageSpeed;
            PlaneClass currClass = PlaneClass(manufacturer, model, seats,
                minRunwayLength, tankCapacity, averageSpeed);
            classes.emplace_back(currClass);

            Plane newPlane = Plane();
            newPlane.setId(id);
            newPlane.setPlaneClass(currClass);
            planes.push_back(newPlane);
            cout << "Plane added successfully!" << endl;
            break;
        }
        case 3: {
            string id;
            cout << "Enter plane ID: ";
            cin >> id;

            bool planeRemoved = false;
            for (int i = 0; i < planes.size(); i++) {
                if (planes[i].getId() == id) {
                    planes.erase(planes.begin() + i);
                    //classes.erase(classes.begin() + i);
                    planeRemoved = true;
                    break;
                }
            }

            if (planeRemoved) {
                cout << "Plane removed successfully!" << endl;
            }
            else {
                cout << "Plane not found!" << endl;
            }
            break;
        }
        case 4:
            cout << "List of flights:" << endl;
            for (Flight flight : flights) {
                cout << flight.getDestination() << endl;
            }
            break;
        case 5: {
            string destination;
            int distance;
            int duration;
            int minFuelRequired;
            cout << "Enter flight details:" << endl;
            cout << "Destination: ";
            cin >> destination;
            cout << "Distance: ";
            cin >> distance;
            cout << "Duration: ";
            cin >> duration;
            cout << "Minimum fuel required: ";
            cin >> minFuelRequired;
            flights.emplace_back(destination, distance, duration, minFuelRequired);
            cout << "Flight added successfully!" << endl;
            break;
        }
        case 6: {
            string destination;
            cout << "Enter flight destination: ";
            cin >> destination;

            bool flightRemoved = false;
            for (int i = 0; i < flights.size(); i++) {
                if (flights[i].getDestination() == destination) {
                    flights.erase(flights.begin() + i);
                    flightRemoved = true;
                    break;
                }
            }

            if (flightRemoved) {
                cout << "Flight removed successfully!" << endl;
            }
            else {
                cout << "Flight not found!" << endl;
            }
            break;
        }
        case 7: {
            string destination;
            cout << "Enter destination: ";
            cin >> destination;
            Flight currFlight;
            for (int i = 0; i < flights.size(); i++) {
                if (flights[i].getDestination() == destination) {
                    currFlight = flights[i];
                    break;
                }
            }
            cout << "Planes with enough fuel to reach " << destination << ":" << endl;
            for (Plane plane : planes) {
                if (currFlight.calculateMaxDistance(plane.getPlaneClass().getTankCapacity()) >= 
                    currFlight.getDistance()) {
                    cout << plane << endl;
                    SavePlane(plane);
                }
            }
            break;
        }
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

