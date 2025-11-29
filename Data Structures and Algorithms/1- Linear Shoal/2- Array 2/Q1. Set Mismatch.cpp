class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int n = nums.size();
        vector<int>cnt(n + 1);
        for (auto &it : nums)cnt[it]++;
        int fir = -1, sec = -1;
        for (int i = 1; i <= n; i++) {
            fir = (cnt[i] == 2 ? i : fir);
            sec = (cnt[i] == 0 ? i : sec);
        }
        return vector<int> {fir, sec};
    }
};