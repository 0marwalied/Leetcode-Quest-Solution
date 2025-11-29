class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        const int n = heights.size();
        int ans = 0;
        vector<int>nearestOneSmallerFromLeft(n), nearestOneSmallerFromRight(n);
        stack<vector<int>>s; s.push({ -1, n});
        for (int i = n - 1; i >= 0; i--) {
            while (s.top()[0] >= heights[i])s.pop();
            nearestOneSmallerFromRight[i] = s.top()[1];
            s.push({heights[i], i});
        }
        while (!s.empty())s.pop();
        s.push({ -1, -1});
        for (int i = 0; i < n; i++) {
            while (s.top()[0] >= heights[i])s.pop();
            nearestOneSmallerFromLeft[i] = s.top()[1];
            s.push({heights[i], i});
        }
        for (int i = 0; i < n; i++) {
            ans = max(ans, heights[i] * ((i - nearestOneSmallerFromLeft[i] - 1) + (nearestOneSmallerFromRight[i] - i - 1) + 1));
        }
        return ans;
    }
};