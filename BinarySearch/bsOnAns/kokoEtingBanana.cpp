//https://leetcode.com/problems/koko-eating-bananas/description/



class Solution {
public:
 long long sum(long long n, vector<int>& piles) {
    long long totalHours = 0;
    for (int pile : piles) {
        totalHours += (pile + n - 1) / n; // Calculate ceiling of pile/n
    }
    return totalHours;
}

   int minEatingSpeed(vector<int>& piles, int h) {
    long long l = 1; // Minimum speed
    long long r = *max_element(piles.begin(), piles.end()); // Maximum speed
    int ans = 0;

    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long hrs = sum(mid, piles);
        if (hrs <= h) {
            ans = mid; // Potential answer
            r = mid - 1; // Try smaller speeds
        } else {
            l = mid + 1; // Try larger speeds
        }
    }
    return ans;
}
};