class Solution {
public:
    int countTriplets(vector<int>& arr) {

        unordered_map<int, int> count;
        unordered_map<int, int> sum;

        int ans = 0;
        int xr = 0;

        // prefix XOR = 0 at index 0
        count[0] = 1;
        sum[0] = 0;

        for(int i = 0; i < arr.size(); i++) {

            xr ^= arr[i];

            if(count.find(xr) != count.end()) {

                ans += count[xr] * i - sum[xr];
            }

            count[xr]++;
            sum[xr] += i + 1;
        }

        return ans;
    }
};