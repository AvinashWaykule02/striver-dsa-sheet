

//https://leetcode.com/problems/rotate-array/description/


class Solution {
public: // inplace
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // Handle k > n
        reverse(nums.begin(), nums.end());             
        reverse(nums.begin(), nums.begin() + k);       
        reverse(nums.begin() + k, nums.end());         
    }
};