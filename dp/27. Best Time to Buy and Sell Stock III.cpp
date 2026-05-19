#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(
        n + 1,
        vector<vector<int>>(2, vector<int>(3, 0))
    );

    for(int i = n - 1; i >= 0; i--){
        for(int buy = 0; buy <= 1; buy++){
            for(int cap = 1; cap <= 2; cap++){
                if(buy){
                    dp[i][1][cap] =
                        max(-prices[i] + dp[i+1][0][cap],
                                dp[i+1][1][cap]);
                }
                else{
                    dp[i][0][cap] =
                        max(prices[i] + dp[i+1][1][cap-1],
                                dp[i+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][2];
}

int main(){
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i = 0; i < n; i++) cin >> prices[i];
    cout << maxProfit(prices);
}