class Solution {
public:
    double pow(double x, int n) {
        double ret = 1;
        bool flag = true;
        if (n < 0) {
            flag = false;
            n = -n;
        }
        while (n) {
            if (n % 2 != 0)
                ret *= x;
            x *= x;
            n /= 2;
        }
        if (flag)
            return ret;
        return 1.0 / ret;
    }
};