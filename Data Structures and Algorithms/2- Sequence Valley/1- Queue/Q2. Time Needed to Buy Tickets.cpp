#define all(v) v.begin(), v.end()

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        deque<int>dq(all(tickets));
        int time = 0, n = tickets.size();
        while (true) {
            time++;
            if (dq.front() > 1)
                dq.front()--, dq.push_back(dq.front()), dq.pop_front(), k = (k == 0 ? dq.size() - 1 : k - 1);
            else {
                if (k == 0)return time;
                dq.pop_front(), k = (k == 0 ? dq.size() - 1 : k - 1);
            }
        }
        return time;
    }
};