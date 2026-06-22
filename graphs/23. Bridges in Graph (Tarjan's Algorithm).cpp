#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& tin, vector<int>& low) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for(int neighbor : adj[node]) {
        if(neighbor == parent) continue;
        if(!vis[neighbor]) {
            dfs(neighbor, node, adj, vis, tin, low);
            low[node] = min(low[node], low[neighbor]);
            if(low[neighbor] > tin[node]) {
                cout << node << " - " << neighbor << " is a Bridge\n";
            }
        } else {
            low[node] = min(low[node], tin[neighbor]);
        }
    }
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[1].push_back(3);
    adj[3].push_back(1);

    vector<int> vis(n,0);
    vector<int> tin(n);
    vector<int> low(n);
    dfs(0,-1, adj, vis, tin, low);
    return 0;
}