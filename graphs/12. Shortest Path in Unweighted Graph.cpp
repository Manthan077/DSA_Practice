#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(int n, vector<vector<int>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    queue<int> q;
    dist[src] = 0;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int neighbor : adj[node]) {
            if(dist[node] + 1 < dist[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return dist;
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
    adj[1].push_back(3);
    adj[3].push_back(1);

    vector<int> dist = shortestPath(n, adj, 0);
    cout << "Shortest Distances:\n";
    for(int d : dist) {
        cout << d << " ";
    }
    return 0;
}