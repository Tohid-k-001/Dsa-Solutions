class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        int xorAll = 0;

        // Step 1: XOR everything
        for(int num : nums) {
            xorAll ^= num;
        }

        // Step 2: Find rightmost set bit
        unsigned int x = xorAll;
        unsigned int diff = x & (-x);

        int a = 0;
        int b = 0;

        // Step 3: Divide into two groups
        for(int num : nums) {

            if(num & diff) {
                a ^= num;
            }
            else {
                b ^= num;
            }
        }

        return {a, b};
    }
};