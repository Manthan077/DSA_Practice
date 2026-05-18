#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for(int i = n - 1; i >= 0; i--){
        dp[i][1] = max(-prices[i] + dp[i+1][0],
                        dp[i+1][1]);
        dp[i][0] = max(prices[i] - fee + dp[i+1][1],
                        dp[i+1][0]);
    }
    return dp[0][1];
}

int main(){
    int n, fee;
    cin >> n >> fee;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << maxProfit(prices, fee);
}