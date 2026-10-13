#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int minCoins(const vector<int>& coins, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);

    // Base case
    dp[0] = 0;

    // Calculate minimum coins for each amount
    for (int x = 1; x <= amount; x++)
    {
        for (int i = 0; i < coins.size(); i++)
        {
            int coin = coins[i];

            if (coin <= x && dp[x - coin] != INT_MAX)
            {
                dp[x] = min(dp[x], dp[x - coin] + 1);
            }
        }
    }

    // If amount cannot be formed
    if (dp[amount] == INT_MAX)
        return -1;

    return dp[amount];
}

int main()
{
    // Coin denominations
    vector<int> coins;

    coins.push_back(1);
    coins.push_back(3);
    coins.push_back(4);

    // Target amount
    int amount = 6;

    int result = minCoins(coins, amount);

    cout << "Minimum number of coins = " << result;

    return 0;
}
