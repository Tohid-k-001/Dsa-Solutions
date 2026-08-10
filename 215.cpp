// kth smallest element in an array geeks for geeks
/* class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }

        for(int i=k; i<nums.size(); i++){
            if(nums[i] < pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        int ans= pq.top();
        return ans;
    }
}; */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int num : nums){
            pq.push(num);
        }
        for(int i=0;i<=k-2;i++){
            pq.pop();
        }
        return pq.top();
    }
};