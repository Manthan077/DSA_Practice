#include <bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>& nums, int k) {
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
        for(int target = 0; target <= k; target++){
            int notPick = prev[target];
            int pick = 0;
            if(nums[i] <= target)
                pick = prev[target - nums[i]];
            curr[target] = pick + notPick;
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
    cout << countSubsets(nums, k);
    return 0;
}