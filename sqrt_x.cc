class Solution {
public:
    int sqrt(int x) {
        int left = 0, right = x, mid;
        while (left < right) {
            mid = (left + right)/2 + 1;
            if (x/mid == mid) 
                return mid;
            else if (x/mid < mid)
                right = mid - 1;
            else 
                left = mid;
        }
        return right;
    }
};