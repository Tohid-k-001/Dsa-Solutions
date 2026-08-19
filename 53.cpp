class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum=INT_MIN;
        int currsum=0;

        for(int right=0; right<nums.size(); right++){
            currsum+=nums[right];

            maxsum=max(maxsum,currsum);
            if(currsum < 0){
                currsum = 0;
            }
        }
        return maxsum;
    }
};