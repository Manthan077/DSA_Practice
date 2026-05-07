#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(vector<int>& weight, vector<int>& value, int n, int W) {
    vector<int> dp(W+1, 0);

    for(int w = weight[0]; w <= W; w++){
        dp[w] = (w / weight[0]) * value[0];
    }

    for(int i = 1; i < n; i++){
        for(int w = 0; w <= W; w++){
            int notPick = dp[w];
            int pick = 0;
            if(weight[i] <= w){
                pick = value[i] + dp[w - weight[i]];
            }
            dp[w] = max(pick, notPick);
        }
    }
    return dp[W];
}

int main(){
    int n, W;
    cin >> n >> W;
    vector<int> weight(n), value(n);
    for(int i = 0; i < n; i++) cin >> weight[i];
    for(int i = 0; i < n; i++) cin >> value[i];
    cout << unboundedKnapsack(weight, value, n, W);
}