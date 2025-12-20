class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = -1, diff = INT_MAX;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    int val = nums[i] + nums[j] + nums[k];
                    if (abs(val - target) < diff) {
                        ans = val;
                        diff = abs(val - target);
                    }
                }
            }
        }
        return ans;
    }
};