#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVisited) {
    visited[node] = true;
    pathVisited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            if(dfs(neighbor, adj, visited, pathVisited)) return true;
        }
        else if(pathVisited[neighbor]) {
            return true;
        }
    }
    pathVisited[node] = false;
    return false;
}

bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n,false);
    vector<bool> pathVisited(n,false);
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            if(dfs(i, adj, visited, pathVisited)) return true;
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);

    if(hasCycle(n,adj))
        cout << "Cycle Found";
    else
        cout << "No Cycle";
    return 0;
}