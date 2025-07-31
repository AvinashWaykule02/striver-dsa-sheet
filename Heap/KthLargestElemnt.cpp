//https://leetcode.com/problems/kth-largest-element-in-an-array/description/



class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // min heap store minimum elemnt at top of heap 
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0;i<n;i++){
            minHeap.push(nums[i]);
            // only store top k largest element , other minimum element will be poped 
            if(minHeap.size()>k){
            minHeap.pop();
        }
        }
        
        return minHeap.top();
    }
};