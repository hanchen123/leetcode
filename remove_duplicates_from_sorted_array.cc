class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) {
            return 0;
        }
        int len = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] != A[len])     
                A[++len] = A[i];
        }
        return len + 1;
    }
};