#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if(rank[pv] < rank[pu]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

vector<int> redundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    DSU ds(n);
    for(auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        if(ds.findParent(u) == ds.findParent(v)) return edge;
        ds.unionByRank(u, v);
    }
    return {};
}

int main() {
    vector<vector<int>> edges = {
        {1,2},
        {1,3},
        {2,3}
    };

    vector<int> ans = redundantConnection(edges);
    cout << ans[0] << " " << ans[1];
    return 0;
}