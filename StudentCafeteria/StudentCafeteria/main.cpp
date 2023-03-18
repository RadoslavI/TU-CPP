#include "pch.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

class User {
private:
    std::string name;
    std::string group;
    double balance;

public:
    User(std::string n, std::string g)
    {
        name = n;
        group = g;
        balance = 0;
    }

    User(std::string n, std::string g, double b)
    {
        name = n;
        group = g;
        balance = b;
    }

    std::string getName() const { return name; }
    void setName(std::string n)
    {
        name = n;
    }

    std::string getGroup() const { return group; }
    void setGroup(std::string g)
    {
        group = g;
    }

    double getBalance() const { return balance; }
    void setBalance(double b)
    {
        if (b >= 0)
        {
            balance = b;
        }
        else
        {
            std::cout << "Balance cannot be a negative number!";
        }
    }
};

class Food {
private:
    std::string name;
    double price;
public:
    Food(std::string n, double p)
    {
        name = n;
        price = p;
    }
    std::string getName() const { return name; }

    void setName(std::string n) 
    {
        name = n;
    }

    double getPrice() const { return price; }

    void setPrice(double p) 
    {
        if (p >= 0) {
            price = p;
        }

        else {
            std::cout << "Price cannot be a negative number!";
        }
    }
};

class FoodBlock {
private:
    double discount;
    double markup;
public:
    std::vector<User> users;
    std::vector<Food> menu;
    FoodBlock(double d, double m)
    {
        discount = d;
        markup = m;
    }

    void setDiscount(double d) {
        if (d > 0) 
        {
            discount = d;
        }
        else 
        {
            std::cout << "The discount must be creater than 0!";
        }
    }
    double getDiscount() {
        return discount;
    }

    void setMarkup(double m) {
        if (m > 0) 
        {
            markup = m;
        }
        else 
        {
            std::cout << "The markup must be creater than 0!";
        }
    }
    double getMarkup() {
        return markup;
    }

    void addUser(User user) { users.push_back(user); }
    

    void addFood(Food food) { menu.push_back(food); }
    

    double calculatePrice(User user, Food food) const 
    {
        double priceForUser = food.getPrice(); 
        if (user.getGroup() == "Teachers") {
            priceForUser += markup;
        }
        else if (user.getGroup() == "Students") {
            priceForUser *= (100 - discount) / 100;
            if (priceForUser < 0)
                priceForUser = food.getPrice();
        }
        return priceForUser;
    }

    friend std::ostream& operator<<(std::ostream& os, const FoodBlock& fb);
};

std::ostream& operator<<(std::ostream& os, const FoodBlock& fb)
{
    // Print out the users
    os << "Users: ";
    for (const auto& user : fb.users) {
        os << user.getName() << " | $";
        os << user.getBalance() << " | ";
        os << user.getGroup() << std::endl;
    }
    os << std::endl;

    // Print out the menu
    os << "Menu: ";
    for (const auto& food : fb.menu) {
        os << food.getName() << ": $";
        os << food.getPrice() << std::endl;
    }
    os << std::endl;

    // Print out the discount and markup
    os << "Discount: " << fb.discount << std::endl;
    os << "Markup: " << fb.markup << std::endl;

    // Write data to a file
    std::ofstream file("cafeteria.txt");
    if (file.is_open()) {
        file << "Users: ";
        for (const auto& user : fb.users) {
            file << user.getName() << " | ";
            file << user.getBalance() << " | ";
            file << user.getGroup() << std::endl;
        }
        file << std::endl;

        file << "Menu: ";
        for (const auto& food : fb.menu) {
            file << food.getName() << ": $";
            file << food.getPrice() << std::endl;
        }
        file << std::endl;

        file << "Discount: " << fb.discount << std::endl;
        file << "Markup: " << fb.markup << std::endl;

        file.close();
    }

    return os;
}

int main()
{
    double discount, markup;
    std::cout << "Enter the discount percentage: ";
    std::cin >> discount;
    std::cout << "Enter the markup price: ";
    std::cin >> markup;

    FoodBlock fb(discount, markup);

    int choice;
    do {
        std::cout << "\Cafeteria Menu\n";
        std::cout << "1. Add User\n";
        std::cout << "2. Add Food\n";
        std::cout << "3. Print FoodBlock\n";
        std::cout << "4. Buy Food\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string name, group;
            double balance;
            std::cout << "Enter the user name: ";
            std::cin >> name;
            std::cout << "Enter the user group: ";
            std::cin >> group;
            std::cout << "Enter the user balance: ";
            std::cin >> balance;
            User user(name, group, balance);
            fb.addUser(user);
            break;
        }
        case 2:
        {
            std::string name;
            double price;
            std::cout << "Enter the food name: ";
            std::cin >> name;
            std::cout << "Enter the food price: ";
            std::cin >> price;
            Food food(name, price);
            fb.addFood(food);
            break;
        }
        case 3:
        {
            std::cout << fb << std::endl;
            break;
        }
        case 4:
        {
            std::string username, foodname;
            std::cout << "Enter the user name: ";
            std::cin >> username;
            std::cout << "Enter the food name: ";
            std::cin >> foodname;
            bool found_user = false;
            bool found_food = false;
            for (auto& user : fb.users) {
                if (user.getName() == username) {
                    found_user = true;
                    for (auto& food : fb.menu) {
                        if (food.getName() == foodname) {
                            found_food = true;
                            double price = fb.calculatePrice(user, food);
                            std::cout << "The price for " << user.getName() << " to buy " << food.getName() << " is $" << price << std::endl;
                            if (price > 0 && user.getBalance() >= price) {
                                user.setBalance(user.getBalance() - price);
                                std::cout << user.getName() << " purchased " << food.getName() << " for $" << price << std::endl;
                            }
                            else {
                                std::cout << "Insufficient funds!" << std::endl;
                            }
                            break;
                        }
                    }
                    break;
                }
            }
            if (!found_user) {
                std::cout << "User not found!" << std::endl;
            }
            else if (!found_food) {
                std::cout << "Food not found!" << std::endl;
            }
            break;
        }
        case 5:
            std::cout << "Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice! Please try again." << std::endl;
            break;
        }
    } 
    while (choice != 5);

    return 0;
}
