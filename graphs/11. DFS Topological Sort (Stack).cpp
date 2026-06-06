#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for(int neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }
    vector<int> topo;
    while(!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);

    vector<int> topo = topologicalSort(n, adj);
    cout << "Topological Order:\n";
    for(int node : topo) {
        cout << node << " ";
    }
    return 0;
}