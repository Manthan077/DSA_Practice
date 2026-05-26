#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(2);

    vector<bool> visited(n, false);
    cout << "DFS Traversal:\n";
    dfs(0, adj, visited);
    return 0;
}