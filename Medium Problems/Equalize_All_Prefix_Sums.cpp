/*
Equalize All Prefix Sums
Given a sorted array arr[]. For each i(0 ≤ i ≤ n-1), make all the elements of the array from index 0 to i equal, using the minimum number of operations.

In one operation you either increase or decrease the array element by 1. Return an array that contains the minimum number of operations for each i, to accomplish the above task.

Note:  

For each index i, consider the original array without applying modifications made for previous indices.
Try to solve the problem using O(1) extra space (excluding the resultant array).
Examples :

Input: arr[] = [1, 6, 9, 12]
Output: [0, 5, 8, 14]
Explanation: 
For i = 0, prefix [1] already has all equal elements, so operations = 0.
For i = 1, make [1, 6] equal to 4, operations = |1 - 4| + |6 - 4| = 5.
For i = 2, make [1, 6, 9] equal to 6, operations = |1 - 6| + |6 - 6| + |9 - 6| = 8.
For i = 3, make [1, 6, 9, 12] equal to 8, operations = 7 + 2 + 1 + 4 = 14
Input: arr[] = [1, 1, 1, 7, 7, 10, 19]
Output: [0, 0, 0, 6, 12, 21, 33]
Explanation:
For i = 0, prefix [1] already has equal elements, so operations = 0.
For i = 1, prefix [1, 1] already has equal elements, so operations = 0.
For i = 2, prefix [1, 1, 1] already has equal elements, so operations = 0.
For i = 3, make [1, 1, 1, 7] equal to 1, operations = 6.
For i = 4, make [1, 1, 1, 7, 7] equal to 1, operations = 12.
For i = 5, make [1, 1, 1, 7, 7, 10] equal to 5, operations = 21.
For i = 6, make [1, 1, 1, 7, 7, 10, 19] equal to 7, operations = 33.
Constraints:
1 ≤ arr.size() ≤ 105
-104 ≤ arr[i] ≤ 104
Sum of n over all test case does not exceed 106.
*/
class Solution {
  public:
      vector<int> optimalArray(vector<int> &arr) {
        int n = arr.size();

        vector<long long> pref(n);
        pref[0] = arr[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + arr[i];
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int m = i / 2;

            long long leftCost =
                1LL * arr[m] * (m + 1) - pref[m];

            long long rightCost =
                (pref[i] - pref[m]) -
                1LL * arr[m] * (i - m);

            ans[i] = (int)(leftCost + rightCost);
        }

        return ans;
    }
};