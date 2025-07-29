//https://www.geeksforgeeks.org/problems/second-largest3735/1

class Solution {
  public:
    int getSecondLargest(vector<int> &nums) {
        
        int n = nums.size();
        if(n<2) return -1;
         int first = INT_MIN, second = INT_MIN;
        
        for(int i =0;i<n;i++) {
            int ele = nums[i];
            if(ele>first) {
                second = first;
                first = ele;
            }
            else if(ele < first && ele > second) {
                second = ele;
            }
        }
        if(second == INT_MIN) return -1;
        return second;
    }
};