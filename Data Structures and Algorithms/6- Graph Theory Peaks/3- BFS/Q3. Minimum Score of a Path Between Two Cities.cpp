class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int>dist(n + 1, 1e9);
        vector<vector<vector<int>>>graph(n + 1);

        for (auto &it : roads) {
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }

        dist[1] = INT_MAX;
        queue<int>q;
        q.push(1);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (auto &it : graph[cur]) {
                if (dist[it[0]] > min(dist[cur], it[1])) {
                    dist[it[0]] = min(dist[cur], it[1]);
                    q.push(it[0]);
                }
            }
        }
        return dist[n];
    }
};