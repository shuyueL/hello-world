class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
        if(source == NULL || target == NULL){
            return -1;
        }
        int m = strlen(source);
        int n = strlen(target);
        if(m==0&&n!=0){
            return -1;
        }
        if(n==0){
            return 0;
        }
        
        int i,j;
        int next[m+1];
        next[0] = next[1] = 0;
        for(i = 1;i<m;i++){
            if(j>0 && source[i]!=source[j]){
                j = next[j];
            }
            if(source[i]==source[j]){
                j++;
            }
            next[i+1]=j;
        }
        j=0;
        for(i=0;i<m;i++){
            if(j>0 && source[i] != target[j]){
                j = next[j];
            }
            if(source[i] == target[j]){
                j++;
            }
            if(j == n){
                return i-j+1;
            }
        }
        return -1;
    }
};
