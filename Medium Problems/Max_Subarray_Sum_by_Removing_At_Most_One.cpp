/*
Max Subarray Sum by Removing At Most One
Given an array arr[], find the maximum sum of a non-empty subarray. You are allowed to skip at most one element in the subarray.

Note: After skipping the element, the subarray must still be non-empty.

Examples:

Input: arr[] = [1, 2, 3, -4, 5]
Output: 11
Explanation: We can get maximum sum subarray by skipping -4.
Input: arr[] = [-2, -3, 4, -1, -2, 1, 5, -3]
Output: 9
Explanation: We can get maximum sum subarray by skipping -2 as [4,-1,1,5] sums to 9, which is the maximum achievable sum.
Constraints:
1 ≤ arr.size() ≤ 106
-103 ≤ arr[i] ≤ 103
*/
class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();

    // pre[i]  -> Maximum subarray sum
    // ending at index i
    vector<int> pre(n);

    // suff[i] -> Maximum subarray sum
    // starting from index i
    vector<int> suff(n);

    // Build prefix array (Kadane from left)
    pre[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        pre[i] = max(arr[i], pre[i - 1] + arr[i]);
    }

    // Build suffix array (Kadane from right)
    suff[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = max(arr[i], suff[i + 1] + arr[i]);
    }

    // Maximum subarray sum without deletion
    int ans = *max_element(pre.begin(), pre.end());

    // Try removing each element
    for (int i = 1; i < n - 1; i++)
    {
        ans = max(ans, pre[i - 1] + suff[i + 1]);
    }

    return ans;
        
    }
};