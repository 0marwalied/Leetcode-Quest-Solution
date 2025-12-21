class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        int n = s.size();
        int i = 0;
        string ans = "";
        while (i < n) {
            if (s[i] == ']') {
                string op = "";
                while (!st.empty()) {
                    if (st.top() == "[") {
                        st.pop();
                        break;
                    }
                    op = st.top() + op;
                    st.pop();
                }
                string ok = op;
                string num = "";
                while (!st.empty()) {
                    if (st.top() >= "0" && st.top() <= "9")
                        num += st.top();
                    else
                        break;
                    st.pop();
                }
                reverse(num.begin(), num.end());
                int k = stoi(num);
                op = "";
                while (k > 0) {
                    op += ok;
                    k--;
                }
                st.push(op);
            }
            else {
                string g = "";
                g += s[i];

                st.push(g);
            }
            i++;

        }
        while (!st.empty()) {reverse(st.top().begin(), st.top().end()); ans += st.top(); st.pop();}
        reverse(ans.begin(), ans.end());
        return ans;
    }
};