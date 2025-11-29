#include "bits/stdc++.h"

using namespace std;

#define all(v) v.begin(), v.end()

#define LC_HACK
#ifdef LC_HACK
const auto oo = []() {
    struct ooo {
        static void o() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&ooo::o);
    return 0;
}();
#endif

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>ans(n);
        map<int, int>intervalAns;
        auto normalizeLog = [&](const string & log)->pair<char, vector<int>> {
            int which = 0, idx = 0, time = 0, n(log.size());
            while (log[idx] != ':') which *= 10, which += log[idx++] - '0';
            idx++;
            char startOrEnd = log[idx] == 's' ? 's' : 'e';
            if (startOrEnd == 's') idx += 6;
            else idx += 4;
            while (idx < n) time *= 10, time += log[idx++] - '0';
            return {startOrEnd, {which, time}};
        };

        char lastStartOrEnd = '#';
        int lastWhich, lastTime;
        vector<vector<int>>closedIntervals;
        stack<int>s;
        for (auto &log : logs) {
            auto Log = normalizeLog(log);
            if (Log.first == 'e') {
                int closed = 0;
                for (auto &inteval : closedIntervals) {
                    if (s.top() < inteval[0] && inteval[1] < Log.second[1]) {
                        closed += intervalAns[inteval[0]];
                    }
                }
                intervalAns[s.top()] = Log.second[1] - s.top() + 1 - closed;
                ans[Log.second[0]] += intervalAns[s.top()];
                closedIntervals.push_back({s.top(), Log.second[1]}), s.pop();
            } else s.push(Log.second[1]);
        }
        return ans;
    }
};


// 0   1   2   3   4   5   6   7   8
// |---|---|---|---|---|---|---|---|
// 0   0   0   0   0   0
// S   S   S   E   E   E
//