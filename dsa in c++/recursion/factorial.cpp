#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1)  // Base condition
        return 1;
    return n * factorial(n - 1);  // Recursive call
}

int main() {
    int num = 5;
    cout << "Factorial of " << num << " = " << factorial(num) << endl;
    return 0;
}

// Factorial recursion:
// Time Complexity → O(n)
// Space Complexity → O(n) (because of recursive stack)