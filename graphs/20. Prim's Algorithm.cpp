#include <bits/stdc++.h>
using namespace std;

int primMST(int n, vector<vector<pair<int,int>>>& adj) {
    vector<bool> visited(n,false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    int mstWeight = 0;

    while(!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;
        visited[node] = true;
        mstWeight += wt;

        for(auto neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int edgeWeight = neighbor.second;
            if(!visited[nextNode]) {
                pq.push({edgeWeight, nextNode});
            }
        }
    }
    return mstWeight;
}

int main() {
    int n = 4;
    vector<vector<pair<int,int>>> adj(n);

    adj[0].push_back({1,4});
    adj[1].push_back({0,4});
    adj[0].push_back({2,6});
    adj[2].push_back({0,6});
    adj[0].push_back({3,5});
    adj[3].push_back({0,5});
    adj[1].push_back({3,2});
    adj[3].push_back({1,2});
    adj[2].push_back({3,3});
    adj[3].push_back({2,3});
    cout << "MST Weight = " << primMST(n, adj);
    return 0;
}