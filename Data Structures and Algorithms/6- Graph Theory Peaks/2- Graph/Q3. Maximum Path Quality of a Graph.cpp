class Solution {
public:
    int ans = 0;

    void dfs(int node, int time, int maxTime,
             vector<int>& values,
             vector<vector<pair<int, int>>>& graph,
             vector<bool>& vis,
             int score) {

        if (time > maxTime) return;

        if (node == 0)
            ans = max(ans, score);

        for (auto &[to, w] : graph[node]) {
            if (!vis[to]) {
                vis[to] = true;
                dfs(to, time + w, maxTime, values, graph, vis, score + values[to]);
                vis[to] = false;
            } else {
                dfs(to, time + w, maxTime, values, graph, vis, score);
            }
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n = values.size();
        vector<vector<pair<int, int>>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<bool> vis(n, false);
        vis[0] = true;
        dfs(0, 0, maxTime, values, graph, vis, values[0]);

        return ans;
    }
};