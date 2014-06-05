class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {  
        int len = digits.size();
        int carry = 1, sum = 0;  
        vector<int> ret(len,0);  
        for(int i = len-1; i >= 0; i--) {        
            sum = carry + digits[i];  
            carry = sum/10;  
            ret[i] = sum%10;  
        }  
        if(carry)  
            ret.insert(ret.begin(), carry);  
        return ret;  
    } 
};