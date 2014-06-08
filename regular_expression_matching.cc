class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') 
            return (*s == '\0');
        if (*(p + 1) != '*') {
            if ((*p == '.' && *s != '\0') || *s == *p) 
                return isMatch(s + 1, p + 1);
            return false;
        } 
        else {
            while ((*p == '.' && *s != '\0') || *s == *p) {
                if (isMatch(s, p + 2))
                    return true;
                s++;
            }
            return isMatch(s, p + 2);            
        }
    }
};