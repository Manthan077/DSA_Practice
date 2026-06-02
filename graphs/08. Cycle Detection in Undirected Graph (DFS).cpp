#include <iostream>
#include <vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            if(dfs(neighbor, node, adj, visited)) return true;
        } else if(neighbor != parent) {
            return true;
        }
    }
    return false;
}

bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            if(dfs(i,-1,adj,visited)) return true;
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(0);
    adj[0].push_back(2);

    if(hasCycle(n,adj))
        cout << "Cycle Found";
    else
        cout << "No Cycle";
    return 0;
}