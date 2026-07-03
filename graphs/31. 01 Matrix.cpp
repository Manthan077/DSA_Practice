#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    queue<pair<int,int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 0) {
                q.push({i,j});
            } else {
                mat[i][j] = -1;
            }
        }
    }

    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int k = 0; k < 4; k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && mat[nr][nc] == -1) {
                mat[nr][nc] = mat[row][col] + 1;
                q.push({nr,nc});
            }
        }
    }
    return mat;
}

int main() {
    vector<vector<int>> mat = {{0,0,0}, {0,1,0}, {1,1,1}};
    vector<vector<int>> ans = updateMatrix(mat);

    for(auto row : ans) {
        for(int x : row){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}