// C++ program to count subarrays
// with Prime sum

#include <bits/stdc++.h>
using namespace std;

// Function to count subarrays
// with Prime sum
int primeSubarrays(int A[], int n)
{
    int max_val = int(pow(10, 7));

    // USE SIEVE TO FIND ALL PRIME NUMBERS LESS
    // THAN OR EQUAL TO max_val
    // Create a boolean array "prime[0..n]". A
    // value in prime[i] will finally be false
    // if i is Not a prime, else true.
    vector<bool> prime(max_val + 1, true);

    // Remaining part of SIEVE
    prime[0] = false;
    prime[1] = false;
    for (int p = 2; p * p <= max_val; p++) {

        // If prime[p] is not changed, then
        // it is a prime
        if (prime[p] == true) {

            // Update all multiples of p
            for (int i = p * 2; i <= max_val; i += p)
                prime[i] = false;
        }
    }

    int cnt = 0; // Initialize result

    // Traverse through the array
    for (int i = 0; i < n - 1; ++i) {
        int val = A[i];
        for (int j = i + 1; j < n; ++j) {
            val += A[j];

            if (prime[val])
                ++cnt;
        }
    }

    // return answer
    return cnt;
}

// Driver program
int main()
{
    int A[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(A) / sizeof(A[0]);

    cout << primeSubarrays(A, n);

    return 0;
}
