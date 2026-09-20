/*
Largest Subsquare Surrounded by X
Given a square matrix mat[][] of size n × n, where each cell contains either 'X' or 'O'. Find the size of the largest square submatrix whose boundary is completely surrounded by 'X'. The cells inside the submatrix can contain either 'X' or 'O'. Only the four sides of the submatrix must contain 'X'.
Return side length of the largest such square submatrix.
Note: A square of size 1 is valid if its only cell is 'X'. If no such square submatrix exists, return 0.
Examples:
Input: mat[][] = [[X,X,X,O],[X,O,X,X],[X,X,X,O],[X,O,X,X]]

Output: 3
Explanation: Here, the input represents following matrix of size 4 x 4
The square submatrix starting at (0,0) and ending at (2,2) is the largest submatrix surrounded by X. Therefore, size of that matrix would be 3.
Input: mat[][] = [[X,X],[X,X]]
Output: 2
Explanation: The largest square submatrix surrounded by X is the whole input matrix.
Constraints:
1 ≤ n, mat.size(), mat[i].size() ≤ 1000
*/
class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat)
    {
        int n = mat.size();

        // Matrices to store count of 'X' to the right
        // and bottom of cells.
        vector<vector<int>> right(n, vector<int>(n, 0));
        vector<vector<int>> down(n, vector<int>(n, 0));

        // Fill the right and down matrices
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (mat[i][j] == 'X')
                {
                    right[i][j] = (j == n - 1) ? 1 : right[i][j + 1] + 1;
                    down[i][j] = (i == n - 1) ? 1 : down[i + 1][j] + 1;
                }
            }
        }

        int maxSize = 0;

        // Check each cell as the top-left corner of the square
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Calculate the maximum possible side
                // length for the square starting at (i, j)
                int maxSide = min(right[i][j], down[i][j]);

                // Iterate from the maximum side length down to 1
                for (int side = maxSide; side > 0; side--)
                {
                    // Check if the square of length
                    // 'side' has valid borders
                    if (right[i + side - 1][j] >= side && down[i][j + side - 1] >= side)
                    {
                        maxSize = max(maxSize, side);
                        break;
                    }
                }
            }
        }

        return maxSize;
    }
};