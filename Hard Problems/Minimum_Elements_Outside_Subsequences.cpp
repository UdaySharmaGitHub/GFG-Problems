/*
Minimum Elements Outside Subsequences
Given an array arr[] of size n, partition its elements into a strictly increasing subsequence and a strictly decreasing subsequence.

Each element can belong to at most one of these subsequences, and some elements may remain unused.

Determine the minimum number of elements that cannot be included in either subsequence.

Examples:

Input: arr[] = [7, 8, 1, 2, 4, 6, 3, 5, 2, 1, 8, 7]
Output: 2
Explanation: One possible increasing subsequence is: [1, 2, 4, 5, 8]. One possible decreasing subsequence is: [7, 6, 3, 2, 1]. The remaining elements are 8 and 7, so the minimum number of unselected elements is 2.
Input: arr[] = [1, 4, 2, 3, 3, 2, 4]
Output: 0
Explanation: One possible increasing subsequence is: [1, 2, 3, 4]. One possible decreasing subsequence is: [4, 3, 2]. All elements are included in one of the two subsequences.
Constraints:
1 ≤ n ≤ 100
1 ≤ arr[i] ≤ 100
*/
class Solution {
  public:
    vector<vector<vector<int>>> dp;

        int minCount(vector<int>& arr) {
            int n = arr.size();

            dp.assign(n, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

            return n - find(0, -1, -1, arr);
        }

        int find(int i, int inc, int dec, vector<int>& arr) {
            if (i == arr.size()) return 0;

            if (dp[i][inc + 1][dec + 1] != -1)
                return dp[i][inc + 1][dec + 1];

            int ans = find(i + 1, inc, dec, arr);

            if (inc == -1 || arr[i] > arr[inc]) {
                ans = max(ans, 1 + find(i + 1, i, dec, arr));
            }

            if (dec == -1 || arr[i] < arr[dec]) {
                ans = max(ans, 1 + find(i + 1, inc, i, arr));
            }

            return dp[i][inc + 1][dec + 1] = ans;
        }
};