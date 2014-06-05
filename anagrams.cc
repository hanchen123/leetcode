class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > mp;
        map<string, vector<string> >::iterator it;
        vector<string> ret;
        string tmp;
        for (int i = 0; i < strs.size(); i++) {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }
        for (it = mp.begin(); it != mp.end(); it++) {
            if ((it->second).size() > 1) {
                for (int i = 0; i < (it->second).size(); i++) 
                    ret.push_back((it->second)[i]);
            }
        }
        return ret;
    }
};