#include <bits/stdc++.h>
using namespace std;

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for(int x : nums) sum += x;
    if(abs(target) > sum || (target + sum) % 2 != 0)
        return 0;

    int k = (target + sum) / 2;
    int n = nums.size();
    vector<int> prev(k+1, 0);
    
    if(nums[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;

    if(nums[0] != 0 && nums[0] <= k)
        prev[nums[0]] = 1;

    for(int i = 1; i < n; i++){
        vector<int> curr(k+1, 0);
        for(int t = 0; t <= k; t++){
            int notPick = prev[t];
            int pick = 0;
            if(nums[i] <= t)
                pick = prev[t - nums[i]];
            curr[t] = pick + notPick;
        }
        prev = curr;
    }
    return prev[k];
}

int main(){
    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    cout << findTargetSumWays(nums, target);
}