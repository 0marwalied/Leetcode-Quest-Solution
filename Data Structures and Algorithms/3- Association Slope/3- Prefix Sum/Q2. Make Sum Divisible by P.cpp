class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        const int n = nums.size();
        int totalSum = 0;
        vector<int>pref(n + 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i], pref[i + 1] %= p;
        }
        int rem = pref[n];
        if (rem == 0)return 0;
        map<int, int>near;
        near[0] = -1;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int target = ((((pref[i + 1] % p) - rem) % p) + p) % p;
            if (near.count(target))
                ans = min(ans, i - near[target]);
            near[pref[i + 1]] = i;
        }
        return ans == n ? -1 : ans;
    }
};