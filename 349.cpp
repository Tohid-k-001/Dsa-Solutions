class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st;
        unordered_set<int>result;
        for(int n: nums1){
            st.insert(n);
        }

        for(int n: nums2){
            if(st.find(n)!=st.end()){
                result.insert(n);
            }
        }
        return vector<int>(result.begin(),result.end());
        
    }
};