
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        unordered_map<int,int>mp;
        
        long long ans;
        int left=0;

        for (int right =0;right<nums.size();right++){
            
            mp[nums[right]]++;

            while(mp[nums[right]]>k){
                mp[nums[left]]--;
                left++;
            }

            ans=max(ans, right-left+1);
        }
        return ans;
    }
};