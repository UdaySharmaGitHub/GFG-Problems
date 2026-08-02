/*
Sequences where Adjacent Divide
Given two positive integer n and m. Find the number of arrays of size n that can be formed such that:

Each element is in the range [1, m].
All adjacent are such that one of them divide the another i.e element Ai divides Ai + 1 or Ai+1 divides Ai.
Examples:

Input: n = 3, m = 3
Output : 17
Explanation: The possible arrays are [1, 1, 1], [1, 1, 2], [1, 1, 3], [1, 2, 1], [1, 2, 2], [1, 3, 1], [1, 3, 3], [2, 1, 1], [2, 1, 2], [2, 1, 3], [2, 2, 1], [2, 2, 2], [3, 1, 1], [3, 1, 2], [3, 1, 3], [3, 3, 1] and [3, 3, 3].
Input: n = 1, m = 10 
Output: 10
Explanation: The possible arrays are [1], [2], [3], [4], [5], [6], [7], [8], [9] and [10].

Constraints:

1 ≤ n ≤ 11
1 ≤ m ≤ 11
*/
class Solution {
  public:
    int count(int n, int m) {
        // code here
           vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // Base case
        for (int i = 1; i <= m; i++)
            dp[1][i] = 1;
 
        // DP
        for (int len = 2; len <= n; len++) {
            for (int last = 1; last <= m; last++) {
 
                for (int prev = 1; prev <= m; prev++) {
 
                    if (prev % last == 0 || last % prev == 0)
                        dp[len][last] += dp[len - 1][prev];
                }
            }
        }
 
        int ans = 0;
 
        for (int i = 1; i <= m; i++)
            ans += dp[n][i];

        return ans;
    }
};