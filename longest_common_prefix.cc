class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret = "";
        if (strs.size() == 0) {
            return ret;
        }
        bool flag = true;
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < strs.size(); j++) {
                if (strs[0][i] != strs[j][i] || i >= strs[j].length()) {
                    flag = false;
                    break;
                }
            }
            if (flag)   ret.append(1, strs[0][i]);
            else    break;
        }
        return ret;
    }
};