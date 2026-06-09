#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            if(d + weight < dist[nextNode]) {
                dist[nextNode] = d + weight;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    return dist;
}

int main() {
    int n = 4;
    vector<vector<pair<int,int>>> adj(n);

    adj[0].push_back({1,4});
    adj[0].push_back({2,1});
    adj[1].push_back({3,2});
    adj[2].push_back({3,5});

    vector<int> dist = dijkstra(n, adj, 0);
    cout << "Shortest Distances:\n";
    for(int d : dist)
        cout << d << " ";

    return 0;
}