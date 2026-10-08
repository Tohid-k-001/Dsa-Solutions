class Solution {
public:
    string removeOuterParentheses(string s) {
        int balance=0;
        string ans;
        for(char ch: s){
            if(ch =='('){
                if(balance > 0){
                    ans+=ch;
                }
                balance++;
            }
            else{
                balance--;
                if(balance > 0){
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};