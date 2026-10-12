
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);

        long long total = 0;
        int maxDiff = 0;
        long long k = (long long)k1 + k2;

        // Step 1: Calculate absolute differences
        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total += diff[i];
            maxDiff = max(maxDiff, diff[i]);
        }

        // Step 2: Enough operations to make all differences zero
        if (total <= k) return 0;

        // Step 3: Binary search for the minimum possible maximum difference
        int left = 0, right = maxDiff;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long operations = 0;

            for (int d : diff) {
                if (d > mid) {
                    operations += d - mid;
                }
            }

            if (operations <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        // Step 4: Reduce all differences to at most 'left'
        for (int i = 0; i < n; i++) {
            if (diff[i] > left) {
                k -= diff[i] - left;
                diff[i] = left;
            }
        }

        // Step 5: Use remaining operations on differences equal to left
        for (int i = 0; i < n && k > 0; i++) {
            if (diff[i] == left) {
                diff[i]--;
                k--;
            }
        }

        // Step 6: Calculate the minimum sum of squares
        long long ans = 0;

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};
