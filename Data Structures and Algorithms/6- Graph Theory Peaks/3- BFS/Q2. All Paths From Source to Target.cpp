class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& edges) {
        const int n = edges.size();
        vector<vector<int>>graph(n);
        for (int i = 0; i < n; i++) {
            for (auto &it : edges[i]) {
                graph[i].push_back(it);
            }
        }
        vector<vector<int>>ans;

        auto search = [&](int node)->vector<vector<int>> {
            queue<pair<int, vector<int>>>q;
            q.push({node, vector<int>{node}});
            vector<vector<int>>use;
            while (!q.empty()) {
                pair<int, vector<int>>cur = q.front(); q.pop();
                bool found = false;
                for (auto &it : graph[cur.first]) {
                    found = true;
                    vector<int>C = cur.second;
                    C.push_back(it);
                    q.push({it, C});
                }
                if (cur.first == n - 1) {
                    use.push_back(cur.second);
                }
            }
            return use;
        };

        vector<vector<int>>use = search(0);
        for (auto &it : use)
            ans.push_back(it);
        return ans;
    }
};