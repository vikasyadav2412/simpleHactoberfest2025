#include <iostream>
using namespace std;

int fib(int n, int dp[]) {
    if (n <= 1) return n;

    // If value already computed
    if (dp[n] != -1)
        return dp[n];

    // Store and return result
    return dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    int dp[100];
    for (int i = 0; i <= n; i++) dp[i] = -1;

    cout << "Fibonacci(" << n << ") = " << fib(n, dp);
    return 0;
}


// ✅ Time Complexity: O(n)
// ✅ Space Complexity: O(n)