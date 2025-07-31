//https://www.geeksforgeeks.org/problems/k-sorted-array1610/1

// solution using binary search 
class Solution {
public:
    int giveIndex(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return -1; // not found
    }

    string isKSortedArray(int arr[], int n, int k) {
        vector<int> temp(arr, arr + n);  // copy to vector
        sort(temp.begin(), temp.end());

        for (int i = 0; i < n; i++) {
            int j = giveIndex(temp, arr[i]);
            if (abs(j - i) > k) return "No";
        }
        return "Yes";
    }
};



