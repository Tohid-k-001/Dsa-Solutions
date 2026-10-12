
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> cnt(31, 0);

        // Step 1: Count set bits at every position
        for (int num : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if ((num >> bit) & 1) {
                    cnt[bit]++;
                }
            }
        }

        long long ans = 0;

        // Step 2: Construct k maximum numbers
        for (int i = 0; i < k; i++) {
            long long x = 0;

            for (int bit = 0; bit < 31; bit++) {
                if (cnt[bit] > 0) {
                    x |= (1LL << bit);
                    cnt[bit]--;
                }
            }

            // Step 3: Add square modulo MOD
            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};
