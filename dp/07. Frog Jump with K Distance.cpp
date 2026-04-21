#include <bits/stdc++.h>
using namespace std;


int frogJumpK(vector<int>& height, int k) {
    int n = height.size();
    vector<int> dp(n, 0);

    dp[0] = 0;

    for(int i = 1; i < n; i++){
        int minCost = 1e9;

        for(int j = 1; j <= k; j++){
            if(i - j >= 0){
                int cost = dp[i-j] + abs(height[i] - height[i-j]);
                minCost = min(minCost, cost);
            }
        }

        dp[i] = minCost;
    }

    return dp[n-1];
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> height(n);
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    cout << frogJumpK(height, k);
    return 0;
}