/*
Minimum Moves to Sort Permutation
Given an array arr[] containing integers from 1 to n exactly once, sort the array in ascending order.

In one operation, you can pick any element and move it either to the beginning or to the end of the array.

Return the minimum number of operations required to sort the array.

Examples:

Input: arr[] = [2, 1, 3]
Output: 1
Explanation: Move 1 to the beginning.
Input: arr[] = [4, 3, 1, 2]
Output: 2
Explanation: Move 3 to the end to get [4, 1, 2, 3]. Then move 4 to the end to get [1, 2, 3, 4].
Constraints:

arr.size() ≤ 105
1 ≤ arr[i] ≤ arr.size()
*/
class Solution {
  public:
    int minMoves(vector<int>& arr) {
        // code here
        int n = arr.size();
        int count[n + 1] = {0};

        // Compute longest consecutive increasing subsequence.
        for (int x : arr) {
            if (count[x - 1]!= 0) {
                count[x] = count[x - 1] + 1;
            } else {
                count[x] = 1;
            }
        }

        int longest = 0;

        // Find maximum subsequence length.
        for (int i = 0; i <= n; ++i) {
            longest = max(longest, count[i]);
        }

        return n - longest;
    }
};