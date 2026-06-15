#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
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

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    int n = accounts.size();
    DSU ds(n);
    unordered_map<string,int> mailMap;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j < accounts[i].size(); j++) {
            string mail = accounts[i][j];
            if(mailMap.find(mail) == mailMap.end()) {
                mailMap[mail] = i;
            } else {
                ds.unionBySize(i, mailMap[mail]);
            }
        }
    }
    vector<vector<string>> mergedMails(n);
    for(auto it : mailMap) {
        string mail = it.first;
        int node = it.second;
        int parent = ds.findParent(node);
        mergedMails[parent].push_back(mail);
    }
    vector<vector<string>> ans;
    for(int i = 0; i < n; i++) {
        if(mergedMails[i].empty()) continue;

        sort(mergedMails[i].begin(), mergedMails[i].end());
        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(string mail : mergedMails[i]) {
            temp.push_back(mail);
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    vector<vector<string>> accounts = {
        {"John","a@gmail.com","b@gmail.com"},
        {"John","b@gmail.com","c@gmail.com"},
        {"Mary","x@gmail.com"}
    };

    vector<vector<string>> ans = accountsMerge(accounts);
    for(auto account : ans) {
        for(string s : account) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}