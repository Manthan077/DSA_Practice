#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& image, int oldColor, int newColor) {
    int n = image.size();
    int m = image[0].size();
    if(row < 0 || row >= n || col < 0 || col >= m || image[row][col] != oldColor) return;

    image[row][col] = newColor;
    dfs(row - 1, col, image, oldColor, newColor);
    dfs(row + 1, col, image, oldColor, newColor);
    dfs(row, col - 1, image, oldColor, newColor);
    dfs(row, col + 1, image, oldColor, newColor);
}

int main() {
    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    int sr = 1;
    int sc = 1;
    int color = 2;
    int oldColor = image[sr][sc];

    if(oldColor != color) dfs(sr, sc, image, oldColor, color);

    for(auto &row : image) {
        for(int val : row)
            cout << val << " ";
        cout << endl;
    }
    return 0;
}