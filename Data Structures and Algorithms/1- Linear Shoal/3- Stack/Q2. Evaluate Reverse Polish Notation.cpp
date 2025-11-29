class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>numbers;
        auto isNumber = [&](const string & s)->bool{
            if (s == "+")return false;
            if (s == "/")return false;
            if (s == "*")return false;
            if (s == "-")return false;
            return true;
        };
        auto getNumber = [&](const string & s)->int{
            int curPos = 0, ans = 0;
            bool neg = 0;
            neg = (s[curPos] == '-');
            curPos = (s[curPos] == '-' ? curPos + 1 : curPos);
            while (curPos < s.size()) {
                ans *= 10, ans += (s[curPos++] - '0');
            }
            if (neg)ans *= -1;
            return ans;
        };
        auto doOperation = [&](int number1, int number2, string op)->int{
            if (op == "+")return number2 + number1;
            else if (op == "-")return number2 - number1;
            else if (op == "*")return number2 * number1;
            return number2 / number1;
        };
        for (auto &it : tokens) {
            if (isNumber(it)) {
                int number = getNumber(it);
                numbers.push(number);
            } else {
                int number1 = numbers.top();
                numbers.pop();
                int number2 = numbers.top();
                numbers.pop();
                int result = doOperation(number1, number2, it);
                numbers.push(result);
            }
        }
        return numbers.top();
    }
};