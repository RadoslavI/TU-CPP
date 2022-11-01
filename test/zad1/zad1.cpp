#include <iostream>
using namespace std;

int main()
{
	int x, n;
	cout << "Enter the number of items:" << "\n";
	cin >> n;
	int *arr = new int(n);
	cout << "Enter " << n << " items" << endl;
	for (x = 0; x < n; x++) {
		cin >> arr[x];
	}

	int biggestSum = arr[0] + arr[1];

	for (x = 1; x < n; x++) 
	{
		if (biggestSum < arr[x] + arr[x - 1]) 
		{
			biggestSum = arr[x] + arr[x - 1];
		}
	}

	cout << biggestSum;
	delete[] arr;

	return 0;
}

