class Solution {
public:
    bool checkValidString(string s) {
        int high=0;
        int low=0;

        for(char ch : s){
            if(ch == '('){
                low++;
                high++;
            }
            else if(ch == ')'){
                low--;
                high--;
            }else{
                high++;
                low--;
            }

            if(high < 0){
                return false;
            }
            if(low < 0){
                low = 0;
            }

        }
        return low==0;
    }
};



