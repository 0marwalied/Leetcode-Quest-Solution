class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool>vis(n);
        vis[source] = true;
        vector<vector<int>>graph(n);
        for (auto &it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        queue<int>q;
        q.push(source);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto &it : graph[cur]) {
                if (!vis[it]) {
                    vis[it] = true; q.push(it);
                }
            }
        }
        return vis[destination];
    }
};