class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int left = 0, right = n - 1, mid;
        if (left == right) return A[0]<target? 1:0;
        while (left < right) {
            mid = (left + right) / 2;
            if(A[mid] == target) return mid;
            if(mid>left && A[mid]>target && A[mid-1]<target) return mid;
            if (A[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left == n-1 && A[left]<target)  return left + 1;
        return left;
    }
};