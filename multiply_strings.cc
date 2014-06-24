class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() == 0 || num2.size() == 0) 
            return 0;  
        string ret = "";
        ret.append(num1.length() + num2.length(), '0');
        reverse(num1.begin(), num1.end());  
        reverse(num2.begin(), num2.end());  
        for(int i = 0; i < num1.size(); i++) {  
            int tmp1 = num1[i] -'0';  
            int carry = 0;  
            for(int j = 0; j < num2.size(); j++) {  
                int tmp2 = num2[j] - '0';  
                int tmp3 = ret[i+j] -'0';          
                ret[i+j] = (tmp1*tmp2 + carry + tmp3) % 10 +'0';    
                carry = (tmp1*tmp2 + carry + tmp3)/10;  
            }  
            if(carry)  
                ret[i + num2.size()] = carry + '0';  
            }  
        }  
        while (ret.length() > 1 && ret[ret.length() - 1] == '0') {
            ret.resize(ret.length() - 1);
        }
        reverse(ret.begin(), ret.end()); 
        return ret;
    }
};