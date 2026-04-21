#include <iostream>
#include <vector>
using namespace std;

int robRange(vector<int>& nums, int start, int end) {
    int prev2 = nums[start];
    int prev1 = max(nums[start], nums[start + 1]);

    for(int i = start + 2; i <= end; i++){
        int curr = max(nums[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);

    return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    cout << rob(nums);
    return 0;
}
