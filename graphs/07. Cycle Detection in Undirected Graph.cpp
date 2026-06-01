#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<pair<int,int>> q;
    q.push({start,-1});
    visited[start] = true;

    while(!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(int neighbor : adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor,node});
            }
            else if(neighbor != parent) {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            if(bfs(i,adj,visited)) return true;
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