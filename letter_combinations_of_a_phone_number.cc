class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        string tmp;
        this->Excute(ret, tmp, digits, 0, digits.length());
        return ret;
    }
private:
    string letters[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void Excute(vector<string> &ret, string &tmp, string &digits, int step, int len) {
        if (step == len) {
            ret.push_back(tmp);
            return;
        }
        int num = digits[step] - '0';
        for (int i = 0; i < letters[num].length(); i++) {
            tmp.append(1, letters[num][i]);
            Excute(ret, tmp, digits, step + 1, len);
            tmp.resize(tmp.size() - 1);
        }
    }    
};