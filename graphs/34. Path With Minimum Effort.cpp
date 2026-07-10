#include <bits/stdc++.h>
using namespace std;

struct Node {
    int effort;
    int row;
    int col;
};

struct Compare {
    bool operator()(Node a, Node b) {
        return a.effort > b.effort;
    }
};

int minimumEffort(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
    priority_queue<Node, vector<Node>, Compare> pq;
    
    effort[0][0] = 0;
    pq.push({0,0,0});
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,-1,1};

    while(!pq.empty()) {
        Node curr = pq.top();
        pq.pop();
        int row = curr.row;
        int col = curr.col;
        int currEffort = curr.effort;
        if(row == n-1 && col == m-1) return currEffort;

        for(int k=0;k<4;k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m) {
                int newEffort = max(currEffort, abs(heights[row][col] - heights[nr][nc]));
                if(newEffort < effort[nr][nc]) {
                    effort[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }
    }
    return 0;
}

int main() {
    vector<vector<int>> heights = {{1,2,2}, {3,8,2}, {5,3,5}};
    cout << minimumEffort(heights);
    return 0;
}