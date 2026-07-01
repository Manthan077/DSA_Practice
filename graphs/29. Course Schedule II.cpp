#include <bits/stdc++.h>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> indegree(numCourses, 0);

    for(auto edge : prerequisites) {
        int course = edge[0];
        int prereq = edge[1];
        adj[prereq].push_back(course);
        indegree[course]++;
    }

    queue<int> q;
    for(int i = 0; i < numCourses; i++) {
        if(indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for(int neighbor : adj[node]) {
            indegree[neighbor]--;
            if(indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }
    if(order.size() == numCourses) return order;
    return {};
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};
    vector<int> ans = findOrder(numCourses, prerequisites);

    if(ans.empty()) {
        cout << "Cycle Exists";
    } else {
        cout << "Course Order:\n";
        for(int course : ans)
            cout << course << " ";
    }
    return 0;
}