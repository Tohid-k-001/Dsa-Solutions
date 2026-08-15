class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>nums;
        for(int i=0;i<n;i++){
            nums.push_back(start+2*i);
        }
        int xr=0;
        for(int n : nums){
            xr ^= n;
        }
        return xr;
    }
};