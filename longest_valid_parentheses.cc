class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> st;
        stack<int> pos;
        int ret = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
                pos.push(i);
            } else {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    pos.pop();
                    ret = max(ret, (st.empty() ? i + 1 : i - pos.top()));
                } else {
                    st.push(s[i]);
                    pos.push(i);
                }
            }
        }
        return ret;
    }
};