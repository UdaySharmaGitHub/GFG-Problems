/*
Maximum sum of elements not part of LIS
Given an array arr[] of positive integers, your task is to find the maximum possible sum of all elements that are not part of the Longest Increasing Subsequence (LIS).
Examples:
Input: arr[] = [4, 6, 1, 2, 3, 8]
Output: 10
Explanation: The elements which are not in LIS is 4 and 6.
Input: arr[] = [5, 4, 3, 2, 1]
Output: 14
Explanation: The elements which are not in LIS is 5, 4, 3 and 2.
Constraints:
1 ≤ arr.size() ≤ 103
1 ≤ arr[i] ≤ 105
*/
#define vi vector<int>
#define vvi vector<vi>
class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        vi dp(n, 1);       // dp[i] = length of LIS ending at i
        vi backtrack(n, -1); // To track the previous index in LIS
        vi sum(n, 0);       // sum[i] = sum of LIS ending at i

        for (int i = 0; i < n; ++i) {
            sum[i] = arr[i];  // Initialize sum with the element itself
            for (int prev = 0; prev < i; ++prev) {
                if (arr[i] > arr[prev]) {  // If increasing sequence possible
                    if (dp[i] < 1 + dp[prev]) {  // Found a longer LIS
                        dp[i] = 1 + dp[prev];
                        backtrack[i] = prev;
                        sum[i] = sum[prev] + arr[i];
                    } 
                    else if (dp[i] == 1 + dp[prev] && sum[i] > sum[prev] + arr[i]) {
                        // Same length but smaller sum → Update
                        backtrack[i] = prev;
                        sum[i] = sum[prev] + arr[i];
                    }
                }
            }
        }

        // Find the smallest-sum LIS of maximum length
        int lis_len = 0, lis_sum = INT_MAX, end_idx = -1;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > lis_len || (dp[i] == lis_len && sum[i] < lis_sum)) {
                lis_len = dp[i];
                lis_sum = sum[i];
                end_idx = i;
            }
        }

        // Mark all elements in LIS as 0 (to exclude them)
        int idx = end_idx;
        while (idx != -1) {
            arr[idx] = 0;
            idx = backtrack[idx];
        }

        // Sum of remaining elements (non-LIS)
        int ans = accumulate(arr.begin(), arr.end(), 0);
        return ans;
    }
};