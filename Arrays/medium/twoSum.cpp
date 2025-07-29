//https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n =nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            int complement = target - nums[i];
            if(m.count(complement)){
                return {i,m[complement]};
            }
           m[nums[i]]=i;
        }
        return {};
    }
};