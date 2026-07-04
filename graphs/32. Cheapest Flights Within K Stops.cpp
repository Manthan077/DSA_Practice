#include <bits/stdc++.h>
using namespace std;

struct Node {
    int stops;
    int node;
    int cost;
};

int cheapestFlight(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
    for(auto flight : flights) {
        int u = flight[0];
        int v = flight[1];
        int wt = flight[2];
        adj[u].push_back({v, wt});
    }

    vector<int> dist(n, INT_MAX);
    queue<Node> q;
    q.push({0, src, 0});
    dist[src] = 0;

    while(!q.empty()) {
        Node curr = q.front();
        q.pop();
        int stops = curr.stops;
        int node = curr.node;
        int cost = curr.cost;
        if(stops > k) continue;
        for(auto neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int price = neighbor.second;
            if(cost + price < dist[nextNode]) {
                dist[nextNode] = cost + price;
                q.push({
                    stops + 1,
                    nextNode,
                    dist[nextNode]
                });
            }
        }
    }
    if(dist[dst] == INT_MAX) return -1;
    return dist[dst];
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {{0,1,100}, {1,2,100}, {2,3,100}, {0,2,500}};
    int src = 0;
    int dst = 3;
    int k = 2;
    cout << cheapestFlight(n, flights, src, dst, k);
    return 0;
}