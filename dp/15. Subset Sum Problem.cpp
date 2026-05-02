#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int>& nums, int k) {
    int n = nums.size();
    vector<bool> prev(k+1, false);
    prev[0] = true; 
    if(nums[0] <= k)
        prev[nums[0]] = true;
    for(int i = 1; i < n; i++){
        vector<bool> curr(k+1, false);
        curr[0] = true;
        for(int target = 1; target <= k; target++){
            bool notPick = prev[target];
            bool pick = false;
            if(nums[i] <= target)
                pick = prev[target - nums[i]];
            curr[target] = pick || notPick;
        }
        prev = curr;
    }
    return prev[k];
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << subsetSum(nums, k);
    return 0;
}