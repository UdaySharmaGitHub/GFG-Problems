/*
Sum of Subarrays
Given an array arr[], find the sum of all the subarrays of the given array.
Note: It is guaranteed that the total sum will fit within a 32-bit integer range.
Examples:
Input: arr[] = [1, 2, 3] 
Output: 20
Explanation: All subarray sums are: [1] = 1, [2] = 2, [3] = 3, [1, 2] = 3, [2, 3] = 5, [1, 2, 3] = 6. Thus total sum is 1 + 2 + 3 + 3 + 5 + 6 = 20.
Input: arr[] = [1, 3]
Output: 8
Explanation: All subarray sums are: [1] = 1, [3] = 3, [1, 3] = 4. Thus total sum is 1 + 3 + 4 = 8.
Constraints :
1 ≤ arr.size() ≤ 105
0 ≤ arr[i] ≤ 104
*/
class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        int n=arr.size();
      int result = 0;
    for (int i = 0; i < n; i++)
        result += (arr[i] * (i + 1) * (n - i));
    return result;
    }
};