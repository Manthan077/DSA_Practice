#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int frogJump(vector<int>& height) {
    int n = height.size();
    int prev2 = 0; 
    int prev1 = abs(height[1] - height[0]); 

    for(int i = 2; i < n; i++){
        int jump1 = prev1 + abs(height[i] - height[i-1]);
        int jump2 = prev2 + abs(height[i] - height[i-2]);

        int curr = min(jump1, jump2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main(){
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    cout << frogJump(height);
    return 0;
}