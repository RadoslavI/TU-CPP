#include <iostream>
using namespace std;

//Base class for different media types
class Item {
	string contentType;
	string datePurchased;
	int ItemID;
	string mediaFormat;
	int numberOfItems;
	double price;
	string title;
public:
	Item(string cT, string dP, int IID, string mF, int noi, double p, string t)
	{
		contentType = cT, datePurchased = dP, ItemID = IID, mediaFormat = mF,
			numberOfItems = noi, price = p, title = t;
	}
	void toString() {
		cout << contentType << "със заглавие" << title << "е била за купена на цена " << price << " на дата " << datePurchased << '\n';
	};
	string getContentType() {
		return contentType;
	}
	string getDatePurchased() {
		return datePurchased;
	}
	string getMediaFormat() {
		return mediaFormat;
	}
	int getItemId() {
		return ItemID;
	}
	int getNumberOfItems() {
		return numberOfItems;
	}
	double getPrice() {
		return price;
	}
	string getTitle() {
		return title;
	}
	void setItemId(int id) {
		ItemID = id;
	}
};
class movie : public Item {
	double rating;
public:
	movie (double r, string cT, string dP, int IID, string mF, int noi, double p, string t) : Item(cT, dP, IID, mF, noi, p, t) 
	{
		rating = r; 
	}
	
	void show()
	{
		toString();
		//cout << "Passengers:" << passengers << '\n';
	}
};
class game : public Item {
	double rating;
public:
	game(double r, string cT, string dP, int IID, string mF, int noi, double p, string t) : Item(cT, dP, IID, mF, noi, p, t) { rating = r; }
	void show()
	{
		/*showv();
		cout << "Loadlimit:" << loadlimit << '\n';*/
	}
};
int main()
{
	movie m(5, 4, 500);
	game g(30000, 12, 1200);
	cout << "Movie:\n";
	m.show();
	cout << "\Game:\n";
	g.show();
	return 0;
}
