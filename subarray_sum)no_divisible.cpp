// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to print the longest
// subarray with sum of elements
// not divisible by X
void max_length(int n, int x,vector<int> a)
{
	// Variable to store start and end index
	int maxm = -1, start = -1, end = -1;

	// traversing to generate all subarray
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			// variable to store sum
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += a[k];
			}
			// Checking if sum is divisible by x
			// or not. If not then update the length 
			// if it greater than all previous length
			if (sum % x != 0 && j - i + 1 > maxm) {
				maxm = j - i + 1;
				start = i;
				end = j;
			}
		}
	}
	
	// If there is no such subarray then print “-1”
	if (maxm == -1) {
		cout << "-1\n";
	} 
	// print the subarray having the stored starting and ending indices
	else {
		for (int i = start; i <= end; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
	}

}

// Driver Code
int main()
{
	int x = 3;

	vector<int> v = { 1, 3, 2, 6 };
	int N = v.size();

	max_length(N, x, v);

	return 0;
}

// This code is contributed by Pushpesh Raj.
