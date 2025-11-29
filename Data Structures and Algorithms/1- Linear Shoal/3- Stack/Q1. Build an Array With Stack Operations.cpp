class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int cur = 1;
        for (auto &it : target) {
            if (cur == it)ans.push_back("Push");
            else {
                while (cur != it && cur <= n) {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                    cur++;
                }
                ans.push_back("Push");
            }
            cur++;
        }
        return ans;
    }
};