#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to solve 0/1 Knapsack problem using Dynamic Programming
int knapsackDP(int W, int wt[], int val[], int n) {
    // DP table where dp[i][w] stores max value with i items and capacity w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; // Base case: 0 items or 0 capacity
            }
            else if (wt[i - 1] <= w) {
                // Maximum of including or excluding the item
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else {
                // Cannot include current item if its weight exceeds current capacity
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Return the maximum value for n items and capacity W
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50; // Total capacity of knapsack
    int n = sizeof(val) / sizeof(val[0]);

    cout << "Item Values: ";
    for (int i = 0; i < n; i++) cout << val[i] << " ";
    cout << "\nItem Weights: ";
    for (int i = 0; i < n; i++) cout << wt[i] << " ";
    cout << "\nKnapsack Capacity: " << W << endl;

    int maxProfit = knapsackDP(W, wt, val, n);

    cout << "\n--- Dynamic Programming Result ---" << endl;
    cout << "Maximum Value/Profit obtainable: " << maxProfit << endl;

    return 0;
}
