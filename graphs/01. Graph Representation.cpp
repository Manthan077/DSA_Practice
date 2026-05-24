// Adjacency List Representation of a Graph

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<vector<int>> adj(n);

    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);

    cout << "Adjacency List:\n";
    for(int i = 0; i < n; i++) {
        cout << i << " -> ";
        for(int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
    return 0;
}

// Adjacency Matrix Representation of a Graph

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<vector<int>> adj(n, vector<int>(n, 0));

    adj[0][1] = 1;
    adj[1][0] = 1;
    adj[0][2] = 1;
    adj[2][0] = 1;
    adj[1][3] = 1;
    adj[3][1] = 1;
    adj[2][3] = 1;
    adj[3][2] = 1;

    cout << "Adjacency Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}