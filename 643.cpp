class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();

        // First window
        long long sum = 0;

        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        long long maxSum = sum;

        // Slide the window
        for (int right = k; right < n; right++) {

            sum += nums[right];          // add new element
            sum -= nums[right - k];      // remove old element

            maxSum = max(maxSum, sum);
        }

        return (double)maxSum / k;
    }
};