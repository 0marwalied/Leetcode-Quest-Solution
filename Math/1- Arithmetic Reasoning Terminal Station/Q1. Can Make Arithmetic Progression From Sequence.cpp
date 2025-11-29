#define all(v) v.begin(), v.end()

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(all(arr));
        const int val(arr[1] - arr[0]), n(arr.size());
        for (int i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] != val)return false;
        }
        return true;
    }
};
