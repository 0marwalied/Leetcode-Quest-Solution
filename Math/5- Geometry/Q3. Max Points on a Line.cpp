class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        const int n = points.size();
        int ans = 1;
        if (n == 1)return ans;
        map<int, int>mp;
        auto getSlope = [&](long double x1, long double y1, long double x2, long double y2)->long double{
            return (y2 - y1) / (x2 - x1);
        };
        for (int i = 0; i < n; i++) {
            mp[points[i][0]]++;
            for (int j = 0; j < n; j++) {
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                int cnt = 2;
                ans = max(ans, cnt);
                if (x1 == x2)continue;
                long double m = getSlope(x1, y1, x2, y2);
                for (int k = 0; k < n; k++) {
                    if (i == k || j == k)continue;
                    int x3 = points[k][0], y3 = points[k][1];
                    if (x3 != x1 && x2 != x3 && getSlope(x1, y1, x3, y3) == m && getSlope(x2, y2, x3, y3) == m) cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        for (auto &it : mp)ans = max(ans, it.second);
        return ans;
    }
};