/*
Max Score from Subarray Mins
You are given an array arr[] of integers. Your task is to find the maximum sum of the smallest and second smallest elements across all subarrays (of size >= 2) of the given array.
Examples :
Input: arr[] = [4, 3, 5, 1]
Output: 8
Explanation: All subarrays with at least 2 elements and find the two smallest numbers in each:
[4, 3] → 3 + 4 = 7
[4, 3, 5] → 3 + 4 = 7
[4, 3, 5, 1] → 1 + 3 = 4
[3, 5] → 3 + 5 = 8
[3, 5, 1] → 1 + 3 = 4
[5, 1] → 1 + 5 = 6
Maximum Score is 8.
Input: arr[] = [1, 2, 3]
Output: 5
Explanation: All subarray with at least 2 elements and find the two smallest numbers in each:
[1, 2] → 1 + 2 = 3
[1, 2, 3] → 1 + 2 = 3
[2, 3] → 2 + 3 = 5
Maximum Score is 5
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 106
*/
class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int count=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            count=max(count,arr[i]+arr[i+1]);
        }
        return count;
    }
};