class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *str1;
        const char *str2; 
        while (*s) {
            if (*p == '?' || *p == *s) {
                s++;
                p++;
                continue;
            }
            if (*p == '*') {
                str1 = p++;
                str2 = s;
                continue;
            }
            if (str1) {
                p = str1 + 1; 
                s = ++str2;
                continue;      
            }
            return false;
        }
        while (*p == '*') {
            p++;
        }
        return !(*p);
    }
};