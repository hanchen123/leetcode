class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0 || divisor == 0) 
            return 0;
        bool flag = true;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) 
            flag = false;
        long long a = dividend;
        long long b = divisor;
        if (a < 0) 
            a = -a;
        if (b < 0) 
            b = -b;
        long long tmp, count, ret = 0;
        while (a >= b) {
            tmp = b;
            count = 1;
            while (tmp + tmp <= a) {
                tmp += tmp;
                count += count;
            }
            ret += count;
            a -= tmp;
        }
        return (int)(flag ? ret : -ret);
    }
};