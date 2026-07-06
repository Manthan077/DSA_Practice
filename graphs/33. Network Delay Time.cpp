#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj(n + 1);
    for(auto edge : times) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];
        adj[u].push_back({v, wt});
    }

    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[k] = 0;
    pq.push({0, k});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(d > dist[node]) continue;

        for(auto neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            if(d + weight < dist[nextNode]) {
                dist[nextNode] = d + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INT_MAX) return -1;
        ans = max(ans, dist[i]);
    }
    return ans;
}

int main() {
    int n = 4;
    int k = 2;
    vector<vector<int>> times = {{2,1,1}, {2,3,1}, {3,4,1}};
    cout << networkDelayTime(times, n, k);
    return 0;
}