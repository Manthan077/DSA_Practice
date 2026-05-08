#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> dp(amount + 1, 1e9);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int amt = coins[i]; amt <= amount; amt++){
            dp[amt] = min(dp[amt], 1 + dp[amt - coins[i]]);
        }
    }
    return (dp[amount] >= 1e9) ? -1 : dp[amount];
}

int main(){
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for(int i = 0; i < n; i++) cin >> coins[i];
    cout << coinChange(coins, amount);
}