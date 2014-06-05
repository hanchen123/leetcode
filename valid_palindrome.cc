class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left <= right) {
            while (left < s.length() && !this->isLetter(s[left]))
                left++;
            while (right >= 0 && !this->isLetter(s[right]))
                right--;
            if (left <= right && s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
private:
    bool isLetter(char &ch) {
        if (ch >= '0' && ch <= '9')
            return true;
        if (ch >= 'a' && ch <= 'z')
            return true;
        if (ch >= 'A' && ch <= 'Z') {
            ch += 32;
            return true;
        }
        return false;
    }
};