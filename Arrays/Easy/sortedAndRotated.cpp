
//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/


class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int drops = 0; // Count the number of drops

        for(int i = 0;i<n;i++) {
            if(nums[i] > nums[(i + 1) % n]) { // this will compare in roatated manner
            // i.e also compare last elemet with first one too
                drops++;
            }
        }

        return drops <= 1;
    }
};
