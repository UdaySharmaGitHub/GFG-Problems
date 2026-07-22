/*
Minimum Deletions to Make Sorted
Given an array arr[], find the minimum number of elements to delete so that the remaining elements form a strictly increasing sequence in the same order.

Examples:

Input: arr[] = [5, 6, 1, 7, 4]
Output: 2
Explanation: Removing 1 and 4 leaves [5, 6, 7] which is strictly increasing.
Input: arr[] = [1, 1, 1]
Output: 2
Explanation: Removing any 2 elements leaves [1] which is strictly increasing.
Constraints:
1 ≤ n ≤ 105 
1 ≤ arr[i] ≤ 105
*/
class Solution {
  public:
    int minDeletions(vector<int>& arr) {
        // code here
       int n = arr.size();
    vector<int> tails;

    for (int i = 0; i < n; i++) {

        // Binary search for first tail >= arr[i]
        int lo = 0, hi = tails.size();
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (tails[mid] < arr[i])
                lo = mid + 1;
            else
                hi = mid;
        }

        // Extend LIS if arr[i] is greater than all tails
        if (lo == tails.size())
            tails.push_back(arr[i]);

        // Replace to maintain smallest possible tail
        else
            tails[lo] = arr[i];
    }

    return n - tails.size();
    }
};