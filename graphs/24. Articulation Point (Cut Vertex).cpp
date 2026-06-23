#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<int>& mark) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;
    int children = 0;

    for(int neighbor : adj[node]) {
        if(neighbor == parent) continue;
        if(!vis[neighbor]) {
            dfs(neighbor, node, adj, vis, tin, low, mark);
            low[node] = min(low[node], low[neighbor]);
            if(low[neighbor] >= tin[node] && parent != -1) {
                mark[node] = 1;
            }
            children++;
        } else {
            low[node] = min(low[node], tin[neighbor]);
        }
    }
    
    if(parent == -1 && children > 1) {
        mark[node] = 1;
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);
    
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    vector<int> vis(n,0);
    vector<int> tin(n);
    vector<int> low(n);
    vector<int> mark(n,0);

    dfs(0, -1, adj, vis, tin, low, mark);

    cout << "Articulation Points:\n";
    for(int i=0;i<n;i++) {
        if(mark[i]) cout << i << " ";
    }
    return 0;
}