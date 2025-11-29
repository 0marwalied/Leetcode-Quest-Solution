class Solution {
public:
    int pivotInteger(int n) {
        auto getSum = [&](int n)->int{
            return n * (n + 1) / 2;
        };
        int total = getSum(n);
        for (int i = 1; i <= n; i++)
            if (total - getSum(i) + i == getSum(i))return i;
        return -1;
    }
};
