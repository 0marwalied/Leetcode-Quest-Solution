class Solution {
public:
    char findKthBit(int n, int k) {
        string cur = "0";
        n--, k--;
        while (n--) {
            string New = cur + "1";
            reverse(cur.begin(), cur.end());
            for (auto& it : cur)
                New += !(it - '0') + '0';
            cur = New;
        }
        return cur[k];
    }
};