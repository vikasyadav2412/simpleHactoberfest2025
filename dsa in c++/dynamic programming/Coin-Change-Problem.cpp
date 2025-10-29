#include <iostream>
using namespace std;

int countWays(int coins[], int n, int sum) {
    int dp[sum + 1];
    dp[0] = 1;

    for (int i = 1; i <= sum; i++)
        dp[i] = 0;

    for (int i = 0; i < n; i++)
        for (int j = coins[i]; j <= sum; j++)
            dp[j] += dp[j - coins[i]];

    return dp[sum];
}

int main() {
    int coins[] = {1, 2, 5};
    int n = sizeof(coins) / sizeof(coins[0]);
    int sum = 5;

    cout << "Number of ways to make sum = " << countWays(coins, n, sum);
    return 0;
}


// ✅ Time Complexity: O(n × sum)
// ✅ Space Complexity: O(sum)