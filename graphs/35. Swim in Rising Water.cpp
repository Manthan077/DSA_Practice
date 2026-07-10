#include <bits/stdc++.h>
using namespace std;

struct Node {
    int time;
    int row;
    int col;
};

struct Compare {
    bool operator()(Node a, Node b) {
        return a.time > b.time;
    }
};

int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> time(n, vector<int>(n, INT_MAX));
    priority_queue<Node, vector<Node>, Compare> pq;
    time[0][0] = grid[0][0];
    pq.push({grid[0][0], 0, 0});
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};

    while(!pq.empty()) {
        Node curr = pq.top();
        pq.pop();
        int row = curr.row;
        int col = curr.col;
        int currTime = curr.time;

        if(row == n-1 && col == n-1) return currTime;

        for(int k=0;k<4;k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<n) {
                int newTime = max(currTime, grid[nr][nc]);
                if(newTime < time[nr][nc]) {
                    time[nr][nc] = newTime;
                    pq.push({newTime, nr, nc});
                }
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> grid = { {0,2}, {1,3}};
    cout << swimInWater(grid);
    return 0;
}