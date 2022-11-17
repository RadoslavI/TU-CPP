#include < iostream >							 
#include < string.h >
using std::cout;

int main()
{
	char name[20] = "Ivan Petrov";
	cout << "Низа : " << name << "  има дължина " << strlen(name);
	cout << "  символа. ";
	return 0;
}