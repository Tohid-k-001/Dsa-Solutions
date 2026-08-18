class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
        unordered_map<int, int> freq;
        int n = nums.size();

        // Generate every subarray of size k
        for (int i = 0; i <= n - k; i++) {
            
            unordered_set<int> st;

            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Count each number only once per window
            for (int x : st) {
                freq[x]++;
            }
        }

        int ans = -1;

        // Find largest number appearing in exactly one window
        for (auto &[x, count] : freq) {
            if (count == 1) {
                ans = max(ans, x);
            }
        }

        return ans;
    }
};