#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Textbook {
private:
    string title;     
    string author;    
    int edition;     
    string isbn;
    string date;
    int circulation;  
    double price;
    bool isApproved;  
    string approval_date; 

public:
    // Конструктор по подразбиране
    Textbook() = default;

    // Конструктор с параметри без одобрение
    Textbook(string const& t, string const& a, int e, string const& i, string const& d, int c, double p) {
        title = t;
        author = a;
        edition = e;
        isbn = i;
        date = d;
        circulation = c;
        price = p;
        isApproved = false;
    }
    // Конструктор с параметри, с одобрение
    Textbook(string const& t, string const& a, int e, string const& i, string const& d, int c, double p, string const& ad) {
        title = t;
        author = a;
        edition = e;
        isbn = i;
        date = d;
        circulation = c;
        price = p;
        approval_date = ad;
        isApproved = true;
    }

    // Getter за заглавието
    string getTitle() const {
        return title;
    }

    // Setter за заглавието
    void setTitle(string const& t) {
        title = t;
    }

    // Getter за автора
    string getAuthor() const {
        return author;
    }

    // Setter за автора
    void setAuthor(string const& a) {
        author = a;
    }

    // Getter за поредното издание
    int getEdition() const {
        return edition;
    }

    // Setter за поредното издание
    void setEdition(int e) {
        if (e > 0) {
            edition = e;
        }
    }

    // Getter за ISBN номера
    string getISBN() const {
        return isbn;
    }

    // Setter за ISBN номера
    void setISBN(string const& i) {
        isbn = i;
    }

    // Getter за датата на излизане от печат
    string getDate() const {
        return date;
    }

    // Setter за датата на излизане от печат
    void setDate(string const& d) {
        date = d;
    }

    // Getter за тиража
    int getCirculation() const {
        return circulation;
    }

    // Setter за тиража
    void setCirculation(int c) {
        if (c > 0) {
            circulation = c;
        }
    }
    
    // Getter за одобрението
    bool getIsApproved() const {
        return isApproved;
    }

    // Getter за одобрението
    void setIsApproved(bool a) {
        isApproved = a;
    }

    // Getter за датата на одобряване
    string getApprovalDate() const {
        if (isApproved) {
            return approval_date;
        }
        
         cout << "Cannot get approved date" << endl;
         return "";
    }

    // Setter за датата на одобряване
    void setApprovalDate(string const& ad) {
        if (isApproved) {
            approval_date = ad;
        }
        else {
            cout << "Cannot set approval date when the textbook has not been approved!" << endl;
        }
    }

    void setPrice(double p) {
        if (p >= 0) {
            price = p;
        }
        else {
            cout << "Price cannot be less or equal to 0" << endl;
        }
    }

    double getPrice() {
        return price;
    }

    friend ostream& operator<<(ostream& os, const Textbook& t) {
        os << "Title: " << t.title << endl;
        os << "Author/s: " << t.author << endl;
        os << "Edition: " << t.edition << endl;
        os << "ISBN: " << t.isbn << endl;
        os << "Publication date: " << t.date << endl;
        os << "Price: " << t.price << endl;
        os << "Circulation: " << t.circulation << endl;
        os << "Is it approved: " << t.isApproved << endl;

        // Save the data into a file
        ofstream file("textbooks.txt", ios::app);
        if (file.is_open()) {
            file << "Title: " << t.title << endl;
            file << "Author/s: " << t.author << endl;
            file << "Edition: " << t.edition << endl;
            file << "ISBN: " << t.isbn << endl;
            file << "Publication date: " << t.date << endl;
            file << "Price: " << t.price << endl;
            file << "Circulation: " << t.circulation << endl;
            file << "Is it approved: " << t.isApproved << endl;
            file.close();
        }
        else {
            cout << "Unable to open file." << endl;
        }

        return os;
    }
};

class MON {
private:
    vector<Textbook> approvedTextbooks;
    vector<Textbook> unapprovedTextbooks;

public:
    //Default constructor
    MON() = default;

    //Parametarlized constructor
    MON(vector<Textbook> const& aT, vector<Textbook> const& uT) {
        approvedTextbooks = aT;
        unapprovedTextbooks = uT;
    }

    void addApprovedTextBook(Textbook const& tb) {
        approvedTextbooks.push_back(tb);
    }

    void addUnapprovedTextBook(Textbook const& tb) {
        unapprovedTextbooks.push_back(tb);
    }

    vector<Textbook> getApproved() {
        return approvedTextbooks;
    }

    vector<Textbook> getUnapproved() {
        return unapprovedTextbooks;
    }
};

class Distributor {
private:
    string name;
    string address;
    string phoneNumber;
    vector<Textbook> textBooks; 
    double totalPrice = 0;

public:
    Distributor() = default;

    Distributor(string const& n, string const& a, string const& p) {
        name = n;
        address = a;
        phoneNumber = p;
    }

    void setName(string const& n) {
        name = n;
    }

    string getName() {
        return name;
    }

    void setAddress(string const& a) {
        address = a;
    }

    string getAddress() {
        return address;
    }

    void setPhoneNumber(string const& p) {
        phoneNumber = p;
    }

    string getPhoneNumber() {
        return phoneNumber;
    }

    void addTextbook(Textbook t) {
        textBooks.push_back(t);
        totalPrice += t.getPrice();
    }

    double getPrice() {
        return totalPrice;
    }
};

int main() {
    MON mon;
    vector<Distributor> distributors;
    vector<Textbook> textbooks;

    Distributor distro1("Ivan", "Sofia, Bul. Cherni Vrah 5", "+359885554465");
    distributors.push_back(distro1);

    Textbook textbook1("Biology", "Georgi Asparuhov", 2, "55456", "12.03.2003", 1500, 24.55, "15.04.2004");
    textbook1.setIsApproved(true);
    textbooks.push_back(textbook1);
    mon.addApprovedTextBook(textbook1);

    int choice;
    do {
        cout << "Select an option:\n";
        cout << "1. Add an approved textbook\n";
        cout << "2. Add an unapproved textbook\n";
        cout << "3. Add a distributor\n";
        cout << "4. Add a textbook to a distributor and show the total price of his textbooks\n";
        cout << "5. Print and save all textbooks\n";
        cout << "6. Print and save all approved textbooks\n";
        cout << "7. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            string title, author, isbn, date, approval_date;
            int edition, circulation;
            double price;

            cout << "Enter textbook title: " << endl;
            cin >> title;
            cout << "Enter textbook author: " << endl;
            cin >> author;
            cout << "Enter textbook ISBN: " << endl;
            cin >> isbn;
            cout << "Enter textbook publishing date: " << endl;
            cin >> date;
            cout << "Enter textbook approval date: " << endl;
            cin >> approval_date;
            cout << "Enter textbook edition: " << endl;
            cin >> edition;
            cout << "Enter textbook circulation: " << endl;
            cin >> circulation;
            cout << "Enter textbook price: " << endl;
            cin >> price;
            Textbook textbook(title, author, edition, isbn, date, circulation, price, approval_date);
            textbook.setIsApproved(true);
            mon.addApprovedTextBook(textbook);
            textbooks.push_back(textbook);

            break;
        }
        case 2: {
            string title, author, isbn, date, approval_date;
            int edition, circulation;
            double price;

            cout << "Enter textbook title: " << endl;
            cin >> title;
            cout << "Enter textbook author: " << endl;
            cin >> author;
            cout << "Enter textbook ISBN: " << endl;
            cin >> isbn;
            cout << "Enter textbook publishing date: " << endl;
            cin >> date;
            cout << "Enter textbook edition: " << endl;
            cin >> edition;
            cout << "Enter textbook circulation: " << endl;
            cin >> circulation;
            cout << "Enter textbook price: " << endl;
            cin >> price;
            Textbook textbook(title, author, edition, isbn, date, circulation, price);
            textbook.setIsApproved(false);
            mon.addUnapprovedTextBook(textbook);
            textbooks.push_back(textbook);

            break;
        }
        case 3: {
            string name, address, phoneNumber;

            cout << "Enter distributor name: " << endl;
            cin >> name;
            cout << "Enter distributor address: " << endl;
            cin >> address;
            cout << "Enter distributor Phone number: " << endl;
            cin >> phoneNumber;

            distributors.push_back(Distributor(name, address, phoneNumber));
            break;
        }
        case 4: {
            string name, title;
            Distributor currDistro;
            Textbook currTextbook;

            cout << "Enter desired distributor name: " << endl;
            cin >> name;
            cout << "Enter desired textbook title: " << endl;
            cin >> title;

            for (int i = 0; i < distributors.size(); i++)
            {
                if (distributors[i].getName() == name) {
                    currDistro = distributors[i];
                    break;
                }
            }

            for (int i = 0; i < textbooks.size(); i++)
            {
                if (textbooks[i].getTitle() == title) {
                    currTextbook = textbooks[i];
                    break;
                }
            }

            currDistro.addTextbook(currTextbook);
            cout << "Distributor order price: " << currDistro.getPrice() << endl;
        }
        case 5: {
            for (int i = 0; i < textbooks.size(); i++)
            {
                cout << textbooks[i] << endl;
            }
            break;
        }
        case 6: {
            for (int i = 0; i < mon.getApproved().size(); i++)
            {
                cout << mon.getApproved()[i] << endl;
            }
            break;
        }
        case 7:
            cout << "Goodbye.\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    } while (choice != 7);

    return 0;
}
