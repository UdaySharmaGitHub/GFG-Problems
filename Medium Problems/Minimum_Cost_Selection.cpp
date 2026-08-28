/*
Minimum Cost Selection
Given an n × 3 matrix mat[][], where each row represents the costs of three available choices at a shop, select exactly one choice from each row such that the same choice is not selected in two adjacent rows.

Return the minimum total cost required.

Examples:

Input: mat[][] = [[1, 50, 50], [50, 50, 50], [1, 50, 50]]
Output: 52
Explanation: One optimal selection is- Row 1: Choice 1 (Cost = 1), Row 2: Choice 2 (Cost = 50), Row 3: Choice 1 (Cost = 1)
Total cost = 1 + 50 + 1 = 52.
Input: mat[][] = [[1, 4, 1], [3, 2, 2], [3, 2, 3]]
Output: 5
Explanation: One optimal selection is- Row 1: Choice 1 (Cost = 1), Row 2: Choice 2 (Cost = 2), Row 3: Choice 3 (Cost = 2)
Total cost = 1 + 2 + 2 = 5.
Constraints:

1 ≤ n ≤ 105
3 ≤ mat[0].size() ≤ 3
1 ≤ mat[i][j] ≤ 100
mat.rows = n
*/
class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();

            // dp[i][j] = minimum cost up to row i
            // when choice j is selected in row i.
            vector<vector<int>> dp(n, vector<int>(3));

            // Initialize the first row.
            dp[0][0] = mat[0][0];
            dp[0][1] = mat[0][1];
            dp[0][2] = mat[0][2];

            // Build the DP table row by row.
            for (int i = 1; i < n; i++)
            {
                // Current row selects choice 0.
                // Previous row can select 1 or 2.
                dp[i][0] = mat[i][0] + min(dp[i - 1][1], dp[i - 1][2]);

                // Current row selects choice 1.
                // Previous row can select 0 or 2.
                dp[i][1] = mat[i][1] + min(dp[i - 1][0], dp[i - 1][2]);

                // Current row selects choice 2.
                // Previous row can select 0 or 1.
                dp[i][2] = mat[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
            }

            // The last row can end with any choice.
            return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};