#include <bits/stdc++.h>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> prev = matrix[0];

    for(int i = 1; i < n; i++){
        vector<int> curr(n);
        for(int j = 0; j < n; j++){
            int up = prev[j];
            int leftDiag = (j > 0) ? prev[j-1] : 1e9;
            int rightDiag = (j < n-1) ? prev[j+1] : 1e9;
            curr[j] = matrix[i][j] + min({up, leftDiag, rightDiag});
        }
        prev = curr;
    }
    int ans = 1e9;
    for(int j = 0; j < n; j++){
        ans = min(ans, prev[j]);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    cout << minFallingPathSum(matrix);
    return 0;
}