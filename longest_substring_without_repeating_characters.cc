class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) 
            return 0;
        bool vis[256];
        memset(vis, false, sizeof(vis));
        int ret = 1, start = 0, end = 0;
        while (start <= end && end < s.length()) {
            while (end < s.length() && vis[ s[end] ] == false) 
                vis[ s[end++] ] = true;
            ret = max(ret, end - start);
            while (start < end && s[start] != s[end]) 
                vis[ s[start++] ] = false;
            start++, end++;
        }
        return ret;
    }
};