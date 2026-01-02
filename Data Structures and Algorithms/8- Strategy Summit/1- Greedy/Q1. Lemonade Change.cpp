class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int arr[2] = {};
        for (auto &it : bills) {
            if (it == 5) {
                arr[0]++;
            } else if (it == 10) {
                if (arr[0])arr[0]--, arr[1]++;
                else return false;
            } else {
                if (arr[0] && arr[1])arr[0]--, arr[1]--;
                else if (arr[0] >= 3)arr[0] -= 3;
                else return false;
            }
        }
        return true;
    }
};