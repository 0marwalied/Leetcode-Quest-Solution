#define all(v)    v.begin(),v.end()

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {

        vector<int>degree(++n);
        vector<vector<int>>g(n);

        for (auto &it : edges) {
            g[it[0]].push_back(it[1]), g[it[1]].push_back(it[0]);
            degree[it[0]]++, degree[it[1]]++;
        }

        for (auto &it : g)
            sort(all(it));

        auto isConnected = [&](int x, int y)->bool{
            return binary_search(all(g[x]), y);
        };

        vector<int>oddDegreeNodes;
        for (int node = 1; node < n; node++)
            if (degree[node] & 1)
                oddDegreeNodes.push_back(node);

        if (oddDegreeNodes.size() == 1 || oddDegreeNodes.size() > 4)return false;

        vector<int>& nodes = oddDegreeNodes;
        if (oddDegreeNodes.size() == 2) {
            int x = nodes[0], y = nodes[1];
            bool valied = !isConnected(x, y);
            for (int i = 1; i < n; i++) {
                if (i != x && i != y) {
                    if (!isConnected(i, x) && !isConnected(i, y))
                        valied = true;
                }
            }
            return valied;
        } else if (oddDegreeNodes.size() == 3) {
            int x = nodes[0], y = nodes[1], z = nodes[2];
            // x,y x,z
            // y,x y,z
            // z,x z,y
            if ((isConnected(x, y) || isConnected(x, z)) &&
                    (isConnected(y, x) || isConnected(y, z)) &&
                    (isConnected(z, x) || isConnected(z, y)))
                return false;

        } else if (oddDegreeNodes.size() == 4) {
            int w = nodes[0], x = nodes[1], y = nodes[2], z = nodes[3];
            // w,x y,z
            // w,y x,z
            // w,z x,y

            // x,y w,z
            // x,z w,y

            // y,z x,w
            if ((isConnected(w, x) || isConnected(y, z)) &&
                    (isConnected(w, y) || isConnected(x, z)) &&
                    (isConnected(w, z) || isConnected(x, y)) &&
                    (isConnected(x, y) || isConnected(w, z)) &&
                    (isConnected(x, z) || isConnected(w, y)) &&
                    (isConnected(y, z) || isConnected(x, w))
               )
                return false;
        }
        return true;

    }
};