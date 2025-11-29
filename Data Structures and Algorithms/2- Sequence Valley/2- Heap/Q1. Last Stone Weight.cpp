#define all(v) v.begin(), v.end()

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq(all(stones));
        while ((int)pq.size() > 1) {
            int fir = pq.top(); pq.pop();
            int sec = pq.top(); pq.pop();
            if (fir - sec != 0)pq.push(fir - sec);
        }
        pq.push(0);
        return pq.top();
    }
};
