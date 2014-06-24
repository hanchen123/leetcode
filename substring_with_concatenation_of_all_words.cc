class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        int slen = S.length();
        int llen = L[0].length()*L.size();
        if (L.size() == 0) {
            for (int i = 0; i < slen; i++) 
                ret.push_back(i);
            return ret;
        }
        map<string, int> lcount;
        map<string, int> scount;
        for (int i = 0; i < L.size(); i++) 
            lcount[ L[i] ]++;
        for (int i = 0; i + llen <= slen; i++) {
            scount.clear();
            bool flag = true;
            for (int j = 0; j < L.size(); j++) {
                string tmp = S.substr(i + j * L[0].length(), L[0].length());
                if (lcount[tmp] > scount[tmp]) 
                    scount[tmp]++;
                else {
                    flag = false;
                    break;
                }
            }
            if (flag) 
                ret.push_back(i);
        }
        return ret;
    }
};