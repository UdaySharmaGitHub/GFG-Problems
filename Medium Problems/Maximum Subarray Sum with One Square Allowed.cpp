/*
Maximum Subarray Sum with One Square Allowed
Given an integer array arr[], find the maximum subarray sum by squaring at most one element.

Examples:

Input: arr[] =  [-1, -2, 3, -2, 3]
Output: 10
Explanation: The subarray {3, -2, 3} with squaring -2 will give the maximum sum as 3 + 4 + 3 = 10.
Input: arr[] =  [-4, -4, -2, 5, 2, -1]
Output: 27
Explanation: The subarray {5, 2} with squaring 5 will give a maximum sum of 25 + 2 = 27.
Constraints:

1 ≤ arr.size() ≤ 105
-103 ≤ arr[i] ≤ 103
*/
class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
           int n = arr.size();
           int fAns = INT_MIN;
           int activeSum = 0;
           int dormantSum = 0;
           for(int i=0;i<n;i++){
               activeSum = max(activeSum + arr[i], dormantSum + arr[i] * arr[i]);
               dormantSum = max(dormantSum + arr[i], 0);
               fAns = max(fAns, max(activeSum, dormantSum));
           }
           return fAns;
       }
};