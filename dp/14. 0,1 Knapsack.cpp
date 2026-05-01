#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int n, int W) {
    vector<int> prev(W+1, 0);
    for(int w = weight[0]; w <= W; w++){
        prev[w] = value[0];
    }

    for(int i = 1; i < n; i++){
        vector<int> curr(W+1, 0);
        for(int w = 0; w <= W; w++){
            int notPick = prev[w];
            int pick = 0;
            if(weight[i] <= w){
                pick = value[i] + prev[w - weight[i]];
            }
            curr[w] = max(pick, notPick);
        }
        prev = curr;
    }
    return prev[W];
}

int main(){
    int n, W;
    cin >> n >> W;
    vector<int> weight(n), value(n);
    for(int i = 0; i < n; i++) cin >> weight[i];
    for(int i = 0; i < n; i++) cin >> value[i];
    cout << knapsack(weight, value, n, W);
    return 0;
}