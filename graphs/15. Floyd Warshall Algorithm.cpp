#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] == 1e9 || dist[k][j] == 1e9) continue;

                dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
            }
        }
    }
}

int main() {
    int INF = 1e9;
    vector<vector<int>> dist = {
        {0,   3, 10},
        {INF, 0,  1},
        {INF, INF,0}
    };
    floydWarshall(dist);
    cout << "Shortest Distance Matrix:\n";

    for(auto row : dist) {
        for(int val : row) {
            if(val == INF)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}