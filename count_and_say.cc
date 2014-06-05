class Solution {
public:
    string countAndSay(int n) {
        string ret = "1"; 
        if (n <= 1) {
            return ret;
        }
        int i = 2;  
        while(i<=n) {  
            string temp = "";
            int count = 0;
            for (int i = 0; i < ret.length(); i++) {
                count = 1;
                while (i + 1 < ret.length() && ret[i] == ret[i + 1]) {
                    count++;
                    i++;
                }
                temp.append(1, (char)(count + '0'));
                temp.append(1, ret[i]);
            }
            ret = temp; 
            i++;  
        }  
        return ret;          
    }
};