class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;  
        int idx = this->binarySearch(A, 0, n-1, target);  
        if(idx == -1) {  
            ret.push_back(-1);  
            ret.push_back(-1);  
        }  
        else {  
            int start = idx;  
            while(start > 0 && A[start - 1] == A[idx]) 
                start--;  
            int end = idx;  
            while(end <n-1 && A[end + 1] == A[idx]) 
                end++;  
            ret.push_back(start);  
            ret.push_back(end);        
        }  
        return ret;  
    } 
private:
    int binarySearch(int A[], int start, int end, int target) {  
        if(start > end) 
            return -1;  
        int mid = (start + end)/2;  
        if(A[mid] == target) 
            return mid;  
        if(A[mid] < target)  
            return binarySearch(A, mid+1, end, target);  
        else  
            return binarySearch(A, start, mid-1, target);      
    }
};