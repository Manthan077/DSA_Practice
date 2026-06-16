#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++) {
            parent[i]=i;
        }
    }

    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u,int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

struct Edge {
    int u;
    int v;
    int wt;
};

bool cmp(Edge a, Edge b) {
    return a.wt < b.wt;
}

int kruskalMST(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);
    DSU ds(n);
    int mstWeight = 0;
    for(auto edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int wt = edge.wt;
        if(ds.findParent(u) != ds.findParent(v)) {
            mstWeight += wt;
            ds.unionBySize(u,v);
        }
    }
    return mstWeight;
}

int main() {
    int n = 4;
    vector<Edge> edges = {
        {0,1,4},
        {0,2,6},
        {0,3,5},
        {1,3,2},
        {2,3,3}
    };

    cout << "MST Weight = " << kruskalMST(n,edges);
    return 0;
}