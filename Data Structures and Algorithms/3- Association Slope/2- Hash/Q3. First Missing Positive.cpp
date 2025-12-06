// Not an efficient solution
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n + 1, false);
        for (int num : nums) {
            if (num > 0 && num <= n) {
                seen[num] = true;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!seen[i]) {
                return i;
            }
        }
        return n + 1;
    }
};