class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxdepth = 0;
        int size = nums.size();

        for (int i=0; i< size ; i++){
            int depth =0;
            // int indexvalue = i;

            while(nums[i] != -1){
                int nextindex = nums[i];
                nums[i] = -1;
                i = nextindex;
                depth +=1;
            }

            maxdepth = max(maxdepth , depth);
        }
        return maxdepth;
    }
};