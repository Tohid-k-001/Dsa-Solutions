class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        for( int i=0; i<=s.size(); i++){
            int j=0;
            while(s[i+j] !=' ' && i+j <s.size()){
                j++;
            }

            if(j!=0) ans=j;
            i+=j;
        }
        return ans;
    }
};