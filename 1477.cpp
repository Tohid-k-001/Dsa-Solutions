class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {

        int n = arr.size();

        const int INF = 1e9;

        // dp[i] = minimum length of a target-sum subarray
        // completely inside arr[0 ... i-1]
        vector<int> dp(n + 1, INF);

        int left = 0;
        int sum = 0;
        int ans = INF;

        for (int right = 0; right < n; right++) {

            sum += arr[right];

            // Shrink window
            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            // Current window has target sum
            if (sum == target) {

                int len = right - left + 1;

                // Find the best subarray before this window
                if (dp[left] != INF) {
                    ans = min(ans, len + dp[left]);
                }

                // Store current subarray as the best
                dp[right + 1] = min(dp[right], len);
            }
            else {
                dp[right + 1] = dp[right];
            }
        }

        return ans == INF ? -1 : ans;
    }
};