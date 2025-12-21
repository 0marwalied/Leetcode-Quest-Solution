class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int>pos;
        const int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (pos.count(nums[i]) && i - pos[nums[i]] <= k)return true;
            pos[nums[i]] = i;
        }
        return false;
    }
};