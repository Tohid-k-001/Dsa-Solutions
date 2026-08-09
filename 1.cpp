class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      // Using unordered_map not two pointer coz the array is not sorted so dorect find the required value to get the target value by adding with 0th element not found then traverse the element
        unordered_map<int, int> mp;

        for(int i=0; i<nums.size();i++){
            int needed = target - nums[i];

            if(mp.find(needed) != mp.end()){
                return {mp[needed], i};
            }

            mp[nums[i]]= i;
        }

        return {};
    }
};
