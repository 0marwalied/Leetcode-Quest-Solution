#define all(v) v.begin(), v.end()

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        const int n = students.size();
        int ones = count(all(students), 1), zeros = n - ones;
        int idx = 0;
        deque<int>dq(all(students));
        while (idx < n) {
            if (sandwiches[idx] == 0 && !zeros)
                return n - idx;
            if (sandwiches[idx] == 1 && !ones)
                return n - idx;
            if (sandwiches[idx] != dq.front())
                dq.push_back(dq.front()), dq.pop_front();
            else
                ones -= sandwiches[idx] == 1, zeros -= sandwiches[idx] == 0, idx++, dq.pop_front();
        }
        return 0;
    }
};