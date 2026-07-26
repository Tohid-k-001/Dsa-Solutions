class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int first=INT_MIN;
        int second=INT_MIN;
        int three=INT_MIN;
        int min1=INT_MAX;
        int min2=INT_MAX;
        for(int i=0;i<nums.size();i++){

            if(first<nums[i]){
                three=second;
                second=first;
                first=nums[i];
            }else if(second<nums[i] ){
                three=second;
                second=nums[i];
            }else if(three<nums[i]){
                three=nums[i];
            }

            if(nums[i]<min1){
                min2=min1;
                min1=nums[i];
            }else if(nums[i]<min2){ 
                min2=nums[i];
            }
        }

        return max(first*second*three,first*min1*min2);
    }
};