class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>use = nums;
        sort(use.begin(), use.end());
        vector<int>ans;
        for (auto &it : nums) {
            ans.push_back(lower_bound(use.begin(), use.end(), it) - use.begin());
        }
        return ans;
    }
};