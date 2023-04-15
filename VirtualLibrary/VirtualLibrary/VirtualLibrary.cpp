#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Media {
protected:
    string type;
    string author;
    string title;
    int year;

public:
    Media(string type_, string author_, string title_, int year_) :
        type(type_), author(author_), title(title_), year(year_) {}

    Media() {}

    string getType() { return type; }
    void setType(string type_) { type = type_; }

    string getAuthor() { return author; }
    void setAuthor(string author_) { author = author_; }

    string getTitle() { return title; }
    void setTitle(string title_) { title = title_; }

    int getYear() { return year; }
    void setYear(int year_) { year = year_; }
};

class Item : public Media {
private:
    bool isAvailable;

public:
    Item(string type_, string author_, string title_, int year_, bool isAvailable_) :
        Media(type_, author_, title_, year_), isAvailable(isAvailable_) {}

    Item() {}

    bool getIsAvailable() { return isAvailable; }
    void setIsAvailable(bool isAvailable_) { isAvailable = isAvailable_; }

    friend ostream& operator<<(ostream& os, const Item& i) {
        os << i.type << endl;
        os << i.author << endl;
        os << i.title << endl;
        os << i.year << endl;
        os << i.isAvailable << endl;

        // Save the data into a file
        ofstream file("library.txt", ios::app);
        if (file.is_open()) {
            file << i.type << endl;
            file << i.author << endl;
            file << i.title << endl;
            file << i.year << endl;
            file << i.isAvailable << endl;
            file.close();
        }
        else {
            cout << "Unable to open file." << endl;
        }

        return os;
    }
};

class Library {
private:
    vector<Item> items;

public:
    void addItem() {
        string type, author, title;
        int year;
        bool available;

        // Валидация на типа на медията
        while (true) {
            cout << "Enter media type (book, magazine, audio-cd, cd-rom, cassette, video-cassette): ";
            getline(cin, type);
            if (type == "book" || type == "magazine" || type == "audio-cd" || type == "cd-rom" || type == "cassette" || type == "video-cassette") {
                break;
            }
            else {
                cout << "Invalid media type. Please try again." << endl;
            }
        }

        // Валидация на името на автора
        while (true) {
            cout << "Enter author name: ";
            getline(cin, author);
            if (!author.empty()) {
                break;
            }
            else {
                cout << "Invalid author name. Please try again." << endl;
            }
        }

        // Валидация на заглавието
        while (true) {
            cout << "Enter title: ";
            getline(cin, title);
            if (!title.empty()) {
                break;
            }
            else {
                cout << "Invalid title. Please try again." << endl;
            }
        }

        // Валидация на годината на издаване
        while (true) {
            cout << "Enter year of publication: ";
            string input;
            getline(cin, input);
            try {
                year = stoi(input);
                if (year >= 0) {
                    break;
                }
                else {
                    cout << "Year must be non-negative. Please try again." << endl;
                }
            }
            catch (const invalid_argument&) {
                cout << "Invalid year. Please try again." << endl;
            }
        }

        // Валидация на наличността
        while (true) {
            cout << "Is the item available? (y/n): ";
            string input;
            getline(cin, input);
            if (input == "y") {
                available = true;
                break;
            }
            else if (input == "n") {
                available = false;
                break;
            }
            else {
                cout << "Invalid input. Please enter 'y' or 'n'." << endl;
            }
        }

        // Създаване на нов обект Item и добавяне към списъка
        Item newItem(type, author, title, year, available);
        items.push_back(newItem);

        cout << "Item added successfully!" << endl;
    }

    vector<Item> searchItems(bool isAvailable) {
        vector<Item> result;
        for (Item item : items) {
            if (item.getIsAvailable() == isAvailable) {
                result.push_back(item);
            }
        }
        return result;
    }
};

int main() {
    Library library;
    int choice;
    do {
        cout << "Select an option:\n";
        cout << "1. Add item\n";
        cout << "2. Search available items\n";
        cout << "3. Search unavailable items\n";
        cout << "4. Print and save all items\n";
        cout << "5. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            library.addItem();
            cout << "Item added.\n";
            break;
        }
        case 2: {
            vector<Item> availableItems = library.searchItems(true);
            if (availableItems.empty()) {
                cout << "No available items found.\n";
            }
            else {
                cout << "Available items:\n";
                for (Item item : availableItems) {
                    cout << item.getTitle() << " by " << item.getAuthor() << " (" << item.getYear() << ")\n";
                }
            }
            break;
        }
        case 3: {
            vector<Item> unavailableItems = library.searchItems(false);
            if (unavailableItems.empty()) {
                cout << "No unavailable items found.\n";
            }
            else {
                cout << "Unavailable items:\n";
                for (Item item : unavailableItems) {
                    cout << item.getTitle() << " by " << item.getAuthor() << endl;
                }
            }
            break;
        }
        case 4: {
            vector<Item> availableItems = library.searchItems(true);
            for (Item item : availableItems) {
                cout << item << endl;
            }
            vector<Item> unavailableItems = library.searchItems(false);
            for (Item item : unavailableItems) {
                cout << item << endl;
            }
            break;
        }
        case 5:
            cout << "Goodbye.\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
