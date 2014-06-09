class Solution {
public:
    int numDecodings(string s) {
        int len  = s.length();
        if (len == 0 || s[0] == '0') 
            return 0;
        vector<int> ret;
        for (int i = 0; i <= len; i++) 
            ret.push_back(0);
        ret[1] = ret[0] = 1;
        for (int i = 2; i <= len; i++) {
            if (s[i - 1] != '0') 
                ret[i] += ret[i - 1];
            int tmp = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if (tmp >= 10 && tmp <= 26) 
                ret[i] += ret[i - 2];
        }
        return ret[len];
    }
};