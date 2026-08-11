class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];

        for(int i=1;i<nums.size(); i++ ){
            if(nums[i]==nums[i-1]+1){
                sum+=nums[i];
            }else{
                break;
            }
        }
        int ans=sum;
        unordered_set<int>st(nums.begin(),nums.end());

        while(st.find(ans)!=st.end()){
            ans++;
        }

        return ans;
    }
};