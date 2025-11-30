class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int N = points.size();
        double ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i + 1; j < N; ++j)
                for (int k = j + 1; k < N; ++k)
                    ans = max(ans, area(points[i], points[j], points[k]));
        return ans;
    }

    double area(vector<int>& P, vector<int>& Q, vector<int>& R) {
        return 0.5 * abs(P[0] * Q[1] + Q[0] * R[1] + R[0] * P[1] - P[1] * Q[0] - Q[1] * R[0] - R[1] * P[0]);
    }
};
