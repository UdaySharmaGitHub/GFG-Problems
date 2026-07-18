/*
Cut Matrix
Given a matrix of 0s and 1s and an integer k, divide the matrix into k pieces such that each piece has at least one 1 in it. A cut can be made in the following way:

Choose a direction: vertical or horizontal.
Choose an index to cut the matrix into two pieces.
If the cut is horizontal, only the bottom part can be cut further.
If the cut is vertical, only the right part can be cut further.
Return the number of different ways to divide the matrix modulo 1e9 + 7.

Examples:

Input: matrix = [[1, 0, 0], [1, 1, 1], [0, 0,0]], k = 3 
Output: 3
Explanation: There are 3 valid ways to divide the matrix into 3 pieces each having at least one 1 - horizontal cut after row 0 then vertical cut after col 0 on bottom, horizontal cut after row 0 then vertical cut after col 1 on bottom, and vertical cut after col 0 then vertical cut after col 1 on the right part.
 
Input: matrix = [[0, 0], [1, 1]], k = 2
Output: 1
Explanation: Only way is to cut vertically in the middle since the top half has no 1.
Input: matrix = [[1, 0], [0, 0]], k = 1
Output: 1
Explanation: No cut needed as k = 1, the whole matrix is one piece with at least one 1.
Constraints:
1 <= n, m, k <= 200
*/
class Solution {
  public:
        int findWays(vector<vector<int>>& matrix, int k) {

        const int MOD = 1000000007;

        int rows = matrix.size();

        int cols = matrix[0].size();

        vector<vector<int>> suffixOnes(rows + 1, vector<int>(cols + 1));

        for (int r = rows - 1; r >= 0; r--) {

            for (int c = cols - 1; c >= 0; c--) {

                suffixOnes[r][c] =

                    matrix[r][c]

                    + suffixOnes[r + 1][c]

                    + suffixOnes[r][c + 1]

                    - suffixOnes[r + 1][c + 1];

            }

        }

        if (suffixOnes[0][0] < k)

            return 0;

        vector<vector<int>> nextRow(rows, vector<int>(cols, rows));

        vector<vector<int>> nextCol(rows, vector<int>(cols, cols));

        for (int c = 0; c < cols; c++) {

            for (int r = rows - 1; r >= 0; r--) {

                if (suffixOnes[r][c] > suffixOnes[r + 1][c])

                    nextRow[r][c] = r + 1;

                else if (r + 1 < rows)

                    nextRow[r][c] = nextRow[r + 1][c];

            }

        }

        for (int r = 0; r < rows; r++) {

            for (int c = cols - 1; c >= 0; c--) {

                if (suffixOnes[r][c] > suffixOnes[r][c + 1])

                    nextCol[r][c] = c + 1;

                else if (c + 1 < cols)

                    nextCol[r][c] = nextCol[r][c + 1];

            }

        }

        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1));

        for (int r = 0; r < rows; r++)

            for (int c = 0; c < cols; c++)

                dp[r][c] = suffixOnes[r][c] ? 1 : 0;

        for (int pieces = 2; pieces <= k; pieces++) {

            vector<vector<int>> rowSuffix(rows + 1, vector<int>(cols + 1));

            vector<vector<int>> colSuffix(rows + 1, vector<int>(cols + 1));

            for (int r = rows - 1; r >= 0; r--) {

                for (int c = cols - 1; c >= 0; c--) {

                    rowSuffix[r][c] = (rowSuffix[r + 1][c] + dp[r][c]) % MOD;

                    colSuffix[r][c] = (colSuffix[r][c + 1] + dp[r][c]) % MOD;

                }

            }

            vector<vector<int>> current(rows + 1, vector<int>(cols + 1));

            for (int r = 0; r < rows; r++) {

                for (int c = 0; c < cols; c++) {

                    if (suffixOnes[r][c] < pieces)

                        continue;

                    long long ways = 0;

                    if (nextRow[r][c] < rows + 1)

                        ways += rowSuffix[nextRow[r][c]][c];

                    if (nextCol[r][c] < cols + 1)

                        ways += colSuffix[r][nextCol[r][c]];

                    current[r][c] = ways % MOD;

                }

            }

            dp.swap(current);

        }

        return dp[0][0];

    }
};