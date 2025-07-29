//https://www.geeksforgeeks.org/problems/largest-element-in-array4009/1

class Solution {
  public:
    int largest(vector<int> &nums) {
        
        int n = nums.size();
        int maxEle = INT_MIN;
        for(int i =0;i<n;i++) {
            int ele = nums[i];
            maxEle = max(maxEle, ele);
        }
        return maxEle;
    }
};

