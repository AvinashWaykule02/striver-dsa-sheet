//https://leetcode.com/problems/split-array-largest-sum/description/




class Solution {
public:
using ll = long long;
   
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        ll low = *max_element(nums.begin(), nums.end());
        ll high = accumulate(nums.begin(), nums.end(), 0ll);
       
        int ans = 0;
        while(low<=high) {
            ll mid = low+(high-low)/2; // bs on asn
            ll cnt = 0;
            ll sum = 0;
           

            for(ll i =0;i<n;i++){
                if(sum + nums[i] > mid) {
                    cnt++;
                    sum = nums[i];
                }
                else {
                    sum += nums[i];
                }
            }
           cnt++;
            if(cnt <= k) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return ans;
        }
        
    
};