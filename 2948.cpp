class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        // Store indices
        vector<int> indices(n);

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        // Sort indices according to their values
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> ans(n);

        int i = 0;

        while (i < n) {

            int j = i + 1;

            // Find the group
            while (j < n &&
                   nums[indices[j]] - nums[indices[j - 1]] <= limit) {
                j++;
            }

            // Get original indices of this group
            vector<int> groupIndices;

            for (int k = i; k < j; k++) {
                groupIndices.push_back(indices[k]);
            }

            // Sort original indices
            sort(groupIndices.begin(), groupIndices.end());

            // Put smallest values at smallest indices
            for (int k = 0; k < groupIndices.size(); k++) {
                ans[groupIndices[k]] = nums[indices[i + k]];
            }

            i = j;
        }

        return ans;
    }
};