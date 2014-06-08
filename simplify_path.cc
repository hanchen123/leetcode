class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vt;
        string tmp; 
        string ret = "";
        int len = path.size();
        int start = 0;
        int end = 0;
        while (start < len) {
            while (start < len && path[start] == '/') {
                start++;
            }
            end = start + 1;
            while (end < len && path[end] != '/') {
                end++;
            }
            tmp = path.substr(start, end - start);
            if (tmp == "..") {
                if (vt.size()>0) 
                    vt.pop_back();
            } 
            else if (tmp != "." && path.size() > 0) 
                vt.push_back(tmp);
            start = end + 1;
        }
        for (int i = 0; i < vt.size(); i++) {
            ret += '/';
            ret += vt[i];
        }
        if (ret.size() == 0) 
            return "/";
        return ret;
    }
};