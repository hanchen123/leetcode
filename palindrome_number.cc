class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x) {
            ret = ret * 10 + (x % 10);
            x /= 10;
        }
        return ret;
    }
    bool isPalindrome(int x) {
        if (x < 0)  return false;
        int y = reverse(x);
        if (y == x)  return true;
        return false;
    }
};