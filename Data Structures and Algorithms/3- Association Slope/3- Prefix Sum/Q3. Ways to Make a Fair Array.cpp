class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        const int n = nums.size();
        vector<int>even(n + 1), odd(n + 1);
        for (int i = 0; i < n; i++) {
            even[i + 1] = even[i] + (i & 1 ? nums[i] : 0);
            odd[i + 1] = odd[i] + (i & 1 ^ 1 ? nums[i] : 0);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                int Even = even[i + 1] - nums[i] + odd[n] - odd[i];
                int Odd = odd[i + 1] + even[n] - even[i + 1];
                ans += Odd == Even;
            } else {
                int Odd = odd[i + 1] - nums[i] + even[n] - even[i];
                int Even = even[i + 1] + odd[n] - odd[i + 1];
                ans += Odd == Even;
            }
        }
        return ans;
    }
};