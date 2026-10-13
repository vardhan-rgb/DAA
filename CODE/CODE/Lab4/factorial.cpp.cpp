#include <iostream>
using namespace std;

// 1. Iterative Method to calculate Factorial
long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// 2. Recursive Method to calculate Factorial
long long factorialRecursive(int n) {
    // Base Case
    if (n <= 1) {
        return 1;
    }
    // Recursive Case
    return n * factorialRecursive(n - 1);
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial of a negative number is not defined." << endl;
    } else {
        // Run Iterative Method
        long long iterativeResult = factorialIterative(num);
        cout << "\n--- Iterative Method ---" << endl;
        cout << "Factorial of " << num << " is: " << iterativeResult << endl;

        // Run Recursive Method
        long long recursiveResult = factorialRecursive(num);
        cout << "\n--- Recursive Method ---" << endl;
        cout << "Factorial of " << num << " is: " << recursiveResult << endl;
    }

    return 0;
}