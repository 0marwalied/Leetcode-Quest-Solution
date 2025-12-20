class Solution {
public:
    int magicalString(int n) {
        if (n <= 3)return 1;
        vector<int>use = {1, 2, 2};
        int cur = 0, last = 2, ans = 1;
        while ((int)use.size() < n) {
            last = last % 2 + 1;
            int num = use[cur];
            while (num--)
                if (cur >= 2)use.push_back(last);
            cur++;
        }
        while (use.size() > n)use.pop_back();
        return count(all(use), 1);
    }
};
