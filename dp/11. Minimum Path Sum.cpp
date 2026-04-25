#include <bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n, 0);

    for(int i = 0; i < m; i++){
        vector<int> curr(n, 0);
        for(int j = 0; j < n; j++){
            if(i == 0 && j == 0){
                curr[j] = grid[i][j];
            }
            else{
                int up = (i > 0) ? prev[j] : 1e9;
                int left = (j > 0) ? curr[j-1] : 1e9;
                curr[j] = grid[i][j] + min(up, left);
            }
        }
        prev = curr;
    }
    return prev[n-1];
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m,vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    cout << minPathSum(grid);
    return 0;
}