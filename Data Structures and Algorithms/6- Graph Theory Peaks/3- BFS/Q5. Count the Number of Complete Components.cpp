class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>>graph(n);
        for (auto &it : edges) {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < n; i++)
            sort(graph[i].begin(), graph[i].end());

        vector<bool>vis(n);
        auto search = [&](int node, vector<int>& path) -> void{
            queue<int>q; q.push(node);
            vis[node] = true;
            while (!q.empty()) {
                int cur = q.front();
                path.push_back(cur);
                q.pop();
                for (auto &it : graph[cur]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        };

        for (int node = 0; node < n; node++) {
            if (!vis[node]) {
                bool good = true;
                vector<int>path;
                search(node, path);
                sort(path.begin(), path.end());
                for (auto &it : path) {
                    for (auto &i : path) {
                        if (i == it)continue;
                        good &= binary_search(graph[i].begin(), graph[i].end(), it);
                    }
                }
                ans += good;
            }
        }
        return ans;
    }
};