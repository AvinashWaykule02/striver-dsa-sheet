//https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int first = 0, second = 0;
        map<int, vector<int>> m;

        // Build the map with indices
        for(int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }

        for(int i = 0; i < n; i++) {
            int ele = nums[i];
            int find = target - ele;

            if (m.find(find) != m.end()) {
                if (find == ele) {
                    if (m[ele].size() > 1) {
                        first = m[ele][0];
                        second = m[ele][1];
                        break;
                    }
                } 
                else {
                    first = i;
                    second = m[find][0]; 
                    break;
                }
            }
        }

        return {first, second};
    }
};
