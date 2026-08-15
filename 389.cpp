class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size()==0) return t[0];

        char ans=0;
        for(char ch:s){
            ans ^= ch;
        }
        for(char ch:t){
            ans ^= ch;
        }
        return ans;
    }
};