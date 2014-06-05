class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(haystack == NULL || needle == NULL)  
            return NULL;  
        int hlen = strlen(haystack);  
        int nlen = strlen(needle);  
        if(hlen<nlen)  
            return NULL;  
        for(int i=0; i<hlen - nlen + 1; i++) {  
            char *cur = &haystack[i];  
            int j=0;
            for(; j< nlen; j++) {  
                if(*cur != needle[j])  
                    break;  
                cur++;  
            }  
            if(j == nlen)  
                return &haystack[i];  
        }  
        return NULL; 
    }
};