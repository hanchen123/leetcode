class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        set<int> st;
        int n = num.size();
        for (int i = 0; i < n; i++)
            st.insert(num[i]);
        int ret = 0;
        for (int i = 0; i < n; i++) {
            int len = 1;
            int tmp = num[i];
            if (st.find(tmp) == st.end())
                continue;
            st.erase(tmp);
            while (st.find(++tmp) != st.end()) {
                len++;
                st.erase(tmp);
            }
            tmp = num[i];
            while (st.find(--tmp) != st.end()) {
                len++;
                st.erase(tmp);
            }
            ret = max(ret, len);
        }
        return ret;
    }
};