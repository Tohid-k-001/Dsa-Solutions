class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=0;
        int maxasc = 0;
        int maxdesc = 0;
        for (int right=0; right<nums.size(); right++){
            maxdesc++;
            maxasc++;
            ans = max({maxasc, ans, maxdesc});
            if(right+1 < nums.size() && nums[right] >= nums[right+1]){
                maxasc = 0;
            }
            if(right+1 < nums.size() && nums[right] <= nums[right+1]){
                maxdesc = 0;
            }
        }
        return ans;
    }
};