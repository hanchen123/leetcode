class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        bool flag = true;
        if (x<0){
            flag = false; 
            x=-x;
        }
        while (x) {
            ret = ret * 10 + (x % 10);
            x /= 10;
        }
        return flag? ret:-ret;
    }
};