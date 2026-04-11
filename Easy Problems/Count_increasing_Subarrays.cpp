/*
Count increasing Subarrays

Given an array arr[] of integers, count the number of subarrays in arr[] which are strictly increasing with size greater or equal to 2. A subarray is a contiguous part of array. A subarray is strictly increasing if each element is greater then it's previous element if it exists.
Examples:
Input: arr[] = [1, 4, 5, 3, 7, 9]
Output: 6
Explanation: The strictly increasing subarrays are: [1, 4], [1, 4, 5], [4, 5], [3, 7], [3, 7, 9], [7, 9]
Input: arr[] = [1, 3, 3, 2, 3, 5]
Output: 4
Explanation: Increasing Subarrays of size greater or equal to 2 are : {1, 3}, {2, 3}, {2, 3, 5}, {3, 5}. So answer for this test case is 4.
Input: arr[] = [2, 2, 2, 2]
Output: 0
Explanation: No strictly increasing subarray exists.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 107
*/
class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int count = 0;

        for(int end = 1; end < n; end++) {
            if(arr[end] > arr[end - 1]) {
                // valid increasing window
                count += (end - start);
            } else {
                // reset window
                start = end;
            }
        }

        return count;
    }
};