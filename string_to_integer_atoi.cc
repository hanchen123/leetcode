class Solution {
public:
    int atoi(const char *str) {  
        int num=0, i=0;  
        bool flag = true, set = false;  
        int len = strlen(str);  
        while(str[i] == ' ' && i< len) i++;  
        if(str[i] == '+') {
            set = true;
            i++; 
        }
        if(!set && str[i] == '-') {
            flag = false; 
            i++;
        }  
        for(;i<len; i++)  
        {  
            if(str[i] == ' ') break;  
            if(str[i]<'0' || str[i] > '9') break;  
            if(INT_MAX/10 < num || INT_MAX/10 == num && INT_MAX%10 < (str[i] -'0'))  
            {  
                return flag? INT_MAX:INT_MIN;  
                break;  
            }  
            num = num*10 + str[i] -'0';  
        }  
        return flag? num:-num;  
    }  
};