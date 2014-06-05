class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;  
        int sum = 0;
        string ret;  
        for(int i = a.size()-1, j = b.size()-1; i >=0 || j>=0; --i,--j) {  
            int temp1 = i>=0? a[i]-'0':0;  
            int temp2 = j>=0? b[j]-'0':0;  
            sum = (temp1 + temp2 + carry)%2;  
            carry = (temp1 + temp2 + carry)/2;  
            ret.insert(ret.begin(), sum+'0');  
        }  
        if(carry)  
            ret.insert(ret.begin(), '1');  
        return ret;       
    }
};