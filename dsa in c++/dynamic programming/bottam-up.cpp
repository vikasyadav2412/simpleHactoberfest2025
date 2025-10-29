#include <iostream>
using namespace std;

int fib(int n) {
    int dp[100];
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fib(n);
    return 0;
}

// ✅ Time: O(n)
// ✅ Space: O(n)