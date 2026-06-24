#include <bits/stdc++.h>
using namespace std;

void dfs1(int node, vector<vector<int>>& adj, vector<int>& vis, stack<int>& st) {
    vis[node] = 1;
    for(int neighbor : adj[node]) {
        if(!vis[neighbor]) {
            dfs1(neighbor, adj, vis, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<vector<int>>& revAdj, vector<int>& vis) {
    vis[node] = 1;
    for(int neighbor : revAdj[node]) {
        if(!vis[neighbor]) {
            dfs2(neighbor, revAdj, vis);
        }
    }
}

int kosaraju(int n, vector<vector<int>>& adj) {
    vector<int> vis(n,0);
    stack<int> st;    
    for(int i=0;i<n;i++) {
        if(!vis[i]) {
            dfs1(i, adj, vis, st);
        }
    }

    vector<vector<int>> revAdj(n);
    for(int i=0;i<n;i++) {
        for(int neighbor : adj[i]) {
            revAdj[neighbor].push_back(i);
        }
    }

    fill(vis.begin(), vis.end(), 0);
    int sccCount = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            sccCount++;
            dfs2(node, revAdj, vis);
        }
    }
    return sccCount;
}

int main() {
    int n = 5;
    
    vector<vector<int>> adj(n);
    adj[0].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(3);
    adj[3].push_back(4);

    cout << "SCC Count = " << kosaraju(n,adj);
    return 0;
}