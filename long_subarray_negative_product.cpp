// C++ implementation of the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to find length of the
// longest subarray such that product
// of the subarray is negative
int maxLength(int a[], int n)
{
	int product = 1, len = -1;

	// Check if product of complete
	// array is negative
	for (int i = 0; i < n; i++)
		product *= a[i];

	// Total product is already
	// negative
	if (product < 0)
		return n;

	// Find an index i such the a[i]
	// is negative and compare length
	// of both halves excluding a[i] to
	// find max length subarray
	for (int i = 0; i < n; i++) {
		if (a[i] < 0)
			len = max(len,
					max(n - i - 1, i));
	}

	return len;
}

// Driver Code
int main()
{
	int arr[] = { 1, 2, -3, 2, 5, -6 };
	int N = sizeof(arr) / sizeof(arr[0]);

	cout << maxLength(arr, N)
		<< "\n";

	int arr1[] = { 1, 2, 3, 4 };
	N = sizeof(arr1) / sizeof(arr1[0]);

	cout << maxLength(arr1, N)
		<< "\n";

	return 0;
}
