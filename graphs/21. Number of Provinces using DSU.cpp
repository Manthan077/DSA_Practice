#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++)
            parent[i]=i;
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

int numberOfProvinces(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    DSU ds(n);
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(isConnected[i][j]==1) {
                ds.unionBySize(i,j);
            }
        }
    }
    int provinces = 0;

    for(int i=0;i<n;i++) {
        if(ds.findParent(i)==i) provinces++;
    }
    return provinces;
}

int main() {
    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };
    cout << numberOfProvinces(isConnected);
    return 0;
}