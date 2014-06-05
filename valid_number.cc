class Solution {
public:
    bool isNumber(const char *s) {
        int left = 0, right = strlen(s) - 1;
        while (left <= right && s[left] == ' ') {
            left++;
        }
        while (left <= right && s[right] == ' ') {
            right--;
        }
        if (left > right) {
            return false;
        }
        if (left < right && (s[left] == '+' || s[left] == '-')) {
            left++;
        }
        bool Dot = false;
        bool Exp = false;
        bool ExpLeft = false;
        bool ExpRight = false;
        for (int i = left; i <= right; i++) {
            if (s[i] == '+' || s[i] == '-') {
                if (!(s[i - 1] == 'e' || s[i - 1] == 'E')) 
                    return false;
            } 
            else if (s[i] == '.') {
                if (Dot || ExpRight || Exp) {
                    return false;
                }
                Dot = true;
            } 
            else if (s[i] == 'e' || s[i] == 'E') {
                if (!ExpLeft || Exp) {
                    return false;
                }
                Exp = true;
            } 
            else if (s[i] >= '0' && s[i] <= '9') {
                if (Exp) 
                    ExpRight = true;
                else 
                    ExpLeft = true;
            } 
            else 
                return false;
        }
        if (!ExpLeft || (Exp && !ExpRight)) 
            return false;
        return true;
    }
};