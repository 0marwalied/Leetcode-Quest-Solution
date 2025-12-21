class Solution {
public:
    int numberOfSubstrings(string s) {
        const int n = s.size();
        int ans = 0, l = 0, r = 0;
        map<int, int>mp;
        while (r < n) {
            mp[s[r++] - 'a']++;
            while (mp.size() == 3) {
                mp[s[l] - 'a']--;
                if (!mp[s[l] - 'a'])mp.erase(s[l] - 'a');
                ans += n - r + 1;
                l++;
            }
        }
        return ans;
    }
};