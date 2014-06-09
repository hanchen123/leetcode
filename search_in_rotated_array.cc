class Solution {
public:
    int search(int A[], int n, int target) {
        int left = 0, right = n-1;   
        while(left <= right) {   
            int mid = (left + right)/2;   
            if(A[mid] == target) 
				return mid;   
            if(A[mid] >= A[left]) {   
                if(target >= A[left] && target <= A[mid])   
                    right = mid - 1;   
                else   
                    left = mid + 1;       
            }   
            else {   
                if(target >= A[left] || target <= A[mid])   
                    right = mid - 1;    
                else   
                    left = mid + 1;   
            }   
        }   
        return -1;         
    }
};