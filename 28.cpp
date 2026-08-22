class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.size();
        int m=haystack.size();

        for(int i=0; i<=m-n ; i++){
            // for finding the word needle 
            int j=0;
            while(j<n && haystack[i+j]==needle[j]){
                j++;
            }
            if(j==n){
                return i;
            }
        }
        return -1;
    }
};