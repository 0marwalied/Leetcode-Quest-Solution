class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (auto &it : nums) {
            if (it == 0) {
                cnt = 0;
            } else cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};