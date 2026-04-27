#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<int> front = triangle[n-1];
    for(int i = n-2; i >= 0; i--){
        vector<int> curr(i+1);
        for(int j = 0; j <= i; j++){
            curr[j] = triangle[i][j] + min(front[j], front[j+1]);
        }
        front = curr;
    }
    return front[0];
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for(int i = 0; i < n; i++){
        triangle[i].resize(i+1);
        for(int j = 0; j <= i; j++){
            cin >> triangle[i][j];
        }
    }
    cout << minimumTotal(triangle);
    return 0;
}