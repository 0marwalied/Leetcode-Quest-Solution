class Solution {
public:
    int maxArea(vector<int>& height) {
        const int n = height.size();
        int l = 0, r = n - 1, ans = 0;
        while (l <= r) {
            ans = max(ans, (r - l) * min(height[r], height[l]));
            if (height[r] < height[l])
                r--;
            else
                l++;
        }
        return ans;
    }
};