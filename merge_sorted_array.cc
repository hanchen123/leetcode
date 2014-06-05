class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int len = m + n - 1;
        m--, n--;
        while (m >= 0 && n >= 0) {
            if (A[m] > B[n])    A[len--] = A[m--];
            else    A[len--] = B[n--];
        }
        while (n >= 0)  A[len--] = B[n--];
    }
}