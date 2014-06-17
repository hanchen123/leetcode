class Solution {
public:
    int candy(vector<int> &ratings) {
        int ret = 0;
        int slen = 0;  
        int precnt = 1; 
        int maxcnt = 1;
        if(ratings.begin() != ratings.end()) {
            ret++;
            for(vector<int>::iterator i = ratings.begin() + 1; i!= ratings.end(); i++) {
                if(*i < *(i-1)) {
                    slen++;
                    if(maxcnt == slen)
                        slen++;
                    ret += slen;
                    precnt = 1;
                }
                else {
                    if(*i > *(i-1))
                        precnt++;
                    else
                        precnt = 1;
                    ret += precnt;
                    slen = 0;
                    maxcnt = precnt;
                }   
            }
        }
        return ret;        
    }
};