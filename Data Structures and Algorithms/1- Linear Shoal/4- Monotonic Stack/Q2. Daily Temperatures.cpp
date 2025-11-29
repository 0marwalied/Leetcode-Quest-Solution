class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<vector<int>>s;
        const int n = temperatures.size();
        vector<int>ans(n);
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 0;
            while (!s.empty() && s.top()[0] <= temperatures[i])s.pop();
            ans[i] = (s.empty() ? 0 : s.top()[1] - i);
            s.push({temperatures[i], i});
        }
        return ans;
    }
};