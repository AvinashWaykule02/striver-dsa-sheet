//https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/

//In this question as there mention subsequence but here sorting is nessasary coz question is not consern about oder of elements



class Solution {
public:
    using ll = long long;
    const int mod = 1e9 + 7;

    // Fast exponentiation: calculates (base^exp) % mod
    ll fastPow(ll base, ll exp) {
        ll res = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int low = i, high = n - 1, validIndex = -1;

            // Binary search to find the furthest index where nums[i] + nums[j] <= target
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (nums[i] + nums[mid] <= target) {
                    validIndex = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            // If valid pair found, count all subsequences between i and validIndex
            if (validIndex != -1) {
                ll count = fastPow(2, validIndex - i);
                ans = (ans + count) % mod;
            }
        }

        return ans;
    }
};
