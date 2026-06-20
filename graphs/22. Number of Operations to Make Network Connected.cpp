#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int findParent(int node) {
        if(node==parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u,int v) {
        int pu=findParent(u);
        int pv=findParent(v);
        if(pu==pv) return;

        if(size[pu] < size[pv]) {
            parent[pu]=pv;
            size[pv]+=size[pu];
        } else {
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

int makeConnected(int n, vector<vector<int>>& connections) {
    DSU ds(n);
    int extraEdges = 0;

    for(auto edge : connections) {
        int u = edge[0];
        int v = edge[1];
        if(ds.findParent(u) ==
           ds.findParent(v)) {
            extraEdges++;
        } else {
            ds.unionBySize(u,v);
        }
    }
    int components = 0;

    for(int i=0;i<n;i++) {
        if(ds.findParent(i)==i)
            components++;
    }
    int requiredEdges = components - 1;
    if(extraEdges >= requiredEdges) return requiredEdges;
    return -1;
}

int main() {
    int n = 4;
    vector<vector<int>> connections = {
        {0,1},
        {0,2},
        {1,2}
    };
    cout << makeConnected(n, connections);
    return 0;
}