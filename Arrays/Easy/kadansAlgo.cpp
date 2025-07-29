

//https://leetcode.com/problems/maximum-subarray/description/


class Solution {
public:
    //kadans algoritham
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0]; // store min sum
        int currSum = nums[0]; // store current subarray sum

        for(int i =1;i<n;i++) {
            // if current number alone is better than adding previous one
            if(currSum + nums[i] < nums[i]) {
                currSum = nums[i];
            }
            else currSum += nums[i]; 
            sum = max(sum, currSum);
        }
        
        return sum;
    }
};
