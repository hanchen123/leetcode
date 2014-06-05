class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string tmp = "";
        this->Excute(ret, tmp, 0, 0, n);
        return ret;
    }
private:
    void Excute(vector<string> &ret, string &tmp, int left, int right, int n) {
        if (left == n && right == n) 
            ret.push_back(tmp);
        if (left < n) {
            tmp.append(1, '(');
            Excute(ret, tmp, left + 1, right, n);
            tmp.resize(tmp.size() - 1);
        }
        if (right < left) {
            tmp.append(1, ')');
            Excute(ret, tmp, left, right + 1, n);
            tmp.resize(tmp.size() - 1);
        }
    }
};