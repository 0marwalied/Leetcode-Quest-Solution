class Solution {
public:
    bool isPalindrome(int n) {
        if (n < 0)return false;
        long long p = 0, nCopy = n;
        while (nCopy) {
            p *= 10, p += nCopy % 10, nCopy /= 10;
        }
        return p == n;
    }
};
