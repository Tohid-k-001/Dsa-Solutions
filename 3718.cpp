class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int val: nums){
            st.insert(val);
        }
        int multiplier=1;
        while(true){
            int value= k * multiplier;
            if(st.find(value)!=st.end()){
                multiplier++;
            }else{
                return value;
            }
        }
    }
};