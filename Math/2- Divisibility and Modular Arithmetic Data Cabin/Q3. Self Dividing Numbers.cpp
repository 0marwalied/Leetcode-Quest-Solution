class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for (int n = left; n <= right; n++) {
            string cur = to_string(n);
            bool valied = true;
            for (auto &d : cur) {
                valied &= (d - '0') && (n % (d - '0') == 0);
            }
            if (valied) ans.push_back(n);
        }
        return ans;
    }
};