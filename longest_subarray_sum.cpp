// C++ code for the above approach:

#include <bits/stdc++.h>
using namespace std;

// Function to find the longest subarray
// satisfying the given condition
void findLongestSubarray(int arr[], int n, int k)
{

	// Initializing ans to the minimum
	// integer value
	int ans = INT_MIN;

	// Initializing the left and right
	// index of the subarray
	int l = 0;
	int r = n - 1;

	// Nested loop to iterate over all
	// possible subarrays
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int diff_sum = 0;

			// Loop to calculate the sum
			// of absolute differences
			for (int k = j; k >= i; k--) {
				diff_sum += abs(arr[j] - arr[k]);
			}

			// Checking if the sum of
			// absolute differences is
			// less than or equal to K
			if (diff_sum <= k) {

				// Updating ans and the
				// left and of right index
				// the subarray
				ans = max(ans, j - i + 1);
				if (ans == diff_sum) {
					l = i;
					r = j;
				}
			}
		}
	}

	// Printing the result
	cout << ans << endl;
	for (int i = l; i <= r; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Driver code
int main()
{

	// First array
	int arr1[] = { 1, 4, 5, 6, 10 };

	int n = sizeof(arr1) / sizeof(int);

	int K = 4;

	// Function call
	findLongestSubarray(arr1, n, K);

	// Second array
	int arr2[] = { 2, 4, 5, 10, 28 };
	K = 20;

	// Function call
	findLongestSubarray(arr2, n, K);

	return 0;
}
