#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>> q;
    int fresh = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2){
                q.push({i,j});
            } else if(grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    if(fresh == 0) return 0;
    int minutes = 0;
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};

    while(!q.empty()) {
        int size = q.size();
        bool rottenThisMinute = false;
        while(size--) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nr = row + dr[k];
                int nc = col + dc[k];
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    rottenThisMinute = true;
                    q.push({nr,nc});
                }
            }
        }
        if(rottenThisMinute) minutes++;
    }
    if(fresh > 0) return -1;
    return minutes;
}

int main() {
    vector<vector<int>> grid = {{2,1,1}, {1,1,0}, {0,1,1}};
    cout << orangesRotting(grid);
    return 0;
}