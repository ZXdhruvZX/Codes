class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // int n= nums.size();
        // sort(nums.begin(), nums.end());
        // return nums[n-k];

        priority_queue<int,vector<int>, greater<int>>pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};