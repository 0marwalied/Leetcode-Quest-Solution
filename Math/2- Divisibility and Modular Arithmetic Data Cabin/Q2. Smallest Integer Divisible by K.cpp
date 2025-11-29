class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int cur = 0;
        for (int i = 1; i <= k; i++) {
            cur *= 10, cur++;
            cur %= k;
            if (cur == 0)return i;
        }
        return -1;
    }
};