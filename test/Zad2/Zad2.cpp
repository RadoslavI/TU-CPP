#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int m, n;
	cout << "Enter the N and M:" << "\n";
	cin >> n >> m;
	int* arr = new int(m);
	cout << "Enter " << m << " items" << endl;
	for (int x = 0; x < m; x++) {
		cin >> arr[x];
	}

	sort(arr, arr + m);

	cout << arr[n - 1];
	delete[] arr;

	return 0;
}

