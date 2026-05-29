#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int countComponents(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    int provinces = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            provinces++;
            dfs(i, adj, visited);
        }
    }
    return provinces;
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[2].push_back(3);
    adj[3].push_back(2);
    cout << countComponents(n, adj);
    return 0;
}