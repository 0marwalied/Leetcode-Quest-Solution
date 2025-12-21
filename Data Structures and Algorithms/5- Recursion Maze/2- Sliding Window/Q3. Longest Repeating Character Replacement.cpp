class Solution {
public:
    int characterReplacement(string s, int k) {
        ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
        int mp[26] = {}, mx;
        auto calc = [&](int cnt)-> int {
            mx = INT_MIN;
            for (auto &it : mp)
                mx = max(mx, it);
            return cnt - mx;
        };
        int l = 0, r = 0, ans = 0;
        while (r < s.size()) {
            mp[s[r++] - 'A']++;
            while (calc(r - l) > k)
                mp[s[l++] - 'A']--;
            ans = max(ans, r - l);
        }
        return ans;
    }
};