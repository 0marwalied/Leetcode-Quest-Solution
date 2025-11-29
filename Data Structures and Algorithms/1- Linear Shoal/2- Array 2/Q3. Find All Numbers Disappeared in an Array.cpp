class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int n = nums.size();
        vector<bool>appear(n + 1);
        for (auto &it : nums) {
            appear[it] = 1;
        }
        vector<int>ans;
        for (int i = 1; i <= n; i++)if (!appear[i])ans.push_back(i);
        return ans;
    }
};