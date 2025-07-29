//https://leetcode.com/problems/remove-duplicates-from-sorted-array/


class Solution {
public:
    //probleme sovled by inplace 
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n; // edge case 
        int a = 1;
        int k = 1; // k positions we get unique elements 
        for(int i =1;i<n;i++) {
            // if current elemet is not equal to previous element then got unique element
            if(nums[i]!=nums[a-1]) {
                nums[a] = nums[i];
                a++;
                k++;
            }
        }
        return k;
    }
};