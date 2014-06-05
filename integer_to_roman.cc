class Solution {
public:
    string intToRoman(int num) {
        char roman[7] = { 'I','V','X', 'L','C', 'D','M'};
        string ret = "";
        int div = 1000;
        for (int i = 6; i >= 0; i -= 2) {
            int tmp = num / div;
            if (tmp == 0) {
                div /= 10;
                continue;
            }
            if (tmp <= 3) 
                ret.append(tmp, roman[i]);
            else if (tmp == 4) {
                ret.append(1, roman[i]);
                ret.append(1, roman[i + 1]);
            }
            else if (tmp == 5) 
                ret.append(1, roman[i + 1]);
            else if (tmp <= 8) {
                ret.append(1, roman[i + 1]);
                ret.append(tmp - 5, roman[i]);
            }
            else {
                ret.append(1, roman[i]);
                ret.append(1, roman[i + 2]);
            }
            num = num % div;
            div = div / 10;
        }
        return ret;
    }
};