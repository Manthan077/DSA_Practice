#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u;
    int v;
    int wt;
};

vector<int> bellmanFord(int n, vector<Edge>& edges, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    for(int i = 1; i <= n - 1; i++) {
        for(auto edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int wt = edge.wt;

            if(dist[u] != INT_MAX && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    return dist;
}

int main() {
    int n = 3;
    vector<Edge> edges;

    edges.push_back({0,1,4});
    edges.push_back({0,2,5});
    edges.push_back({2,1,-5});

    vector<int> dist = bellmanFord(n, edges, 0);
    cout << "Shortest Distances:\n";
    for(int d : dist) cout << d << " ";
    return 0;
}