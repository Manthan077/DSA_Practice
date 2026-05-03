#include <bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = 0;
    for(int x : nums) sum += x;
    if(sum % 2 != 0) return false;
    int target = sum / 2;
    vector<bool> prev(target+1, false);
    prev[0] = true;
    if(nums[0] <= target)
        prev[nums[0]] = true;
    for(int i = 1; i < n; i++){
        vector<bool> curr(target+1, false);
        curr[0] = true;
        for(int t = 1; t <= target; t++){
            bool notPick = prev[t];
            bool pick = false;
            if(nums[i] <= t)
                pick = prev[t - nums[i]];
            curr[t] = pick || notPick;
        }
        prev = curr;
    }
    return prev[target];
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    cout << canPartition(nums);
    return 0;
}