#include <bits/stdc++.h>
using namespace std;

string alienDictionary(vector<string>& dict, int K) {
    vector<vector<int>> adj(K);
    for(int i = 0; i < dict.size() - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        for(int j = 0; j < len; j++) {
            if(s1[j] != s2[j]) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break;
            }
        }
    }

    vector<int> indegree(K, 0);
    for(int i = 0; i < K; i++) {
        for(int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < K; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }
    string ans = "";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans += char(node + 'a');
        for(int neighbor : adj[node]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    return ans;
}

int main() {
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    int K = 4;
    cout << alienDictionary(dict, K);
    return 0;
}