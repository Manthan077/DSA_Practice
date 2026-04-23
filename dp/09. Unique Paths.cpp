#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int m, int n) {
    vector<int> prev(n, 1);
    for(int i = 1; i < m; i++){
        vector<int> curr(n, 1);
        for(int j = 1; j < n; j++){
            curr[j] = curr[j-1] + prev[j];
        }
        prev = curr;
    }
    return prev[n-1];
}

int main(){
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n);
    return 0;
}
