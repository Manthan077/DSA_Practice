#include <bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses,0);

    for(auto edge : prerequisites) {
        int course = edge[0];
        int prereq = edge[1];
        adj[prereq].push_back(course);
        indegree[course]++;
    }

    queue<int> q;
    for(int i=0;i<numCourses;i++) {
        if(indegree[i]==0)
            q.push(i);
    }
    int count = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;
        for(int neighbor : adj[node]) {
            indegree[neighbor]--;
            if(indegree[neighbor]==0)
                q.push(neighbor);
        }
    }
    return count==numCourses;
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};

    if(canFinish(numCourses, prerequisites))
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}